/*  Make the necessary includes and set up the variables.  */

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct{
	char math;
	int values[10];
	int size;
} mypackage;

int main()
{
    int server_sockfd, client_sockfd;
    int server_len, client_len;
    long result = 0;
    struct sockaddr_un server_address;
    struct sockaddr_un client_address;

/*  Remove any old socket and create an unnamed socket for the server.  */

    unlink("server_socket");
    server_sockfd = socket(AF_UNIX, SOCK_STREAM, 0);

/*  Name the socket.  */

    server_address.sun_family = AF_UNIX;
    strcpy(server_address.sun_path, "server_socket");
    server_len = sizeof(server_address);
    bind(server_sockfd, (struct sockaddr *)&server_address, server_len);

/*  Create a connection queue and wait for clients.  */

    listen(server_sockfd, 5);
    while(1) {
	unsigned char i;
	int n = 0;
        mypackage pack;
        printf("Server: waiting...\n");

/*  Accept a connection.  */

        client_len = sizeof(client_address);
        client_sockfd = accept(server_sockfd, 
            (struct sockaddr *)&client_address, &client_len);

/*  We can now read/write to client on client_sockfd.  */
        read(client_sockfd, &pack, sizeof(mypackage));
	printf("Size: %d\n", pack.size);
	printf("Server: received...\n");
	printf("Operation: %c\n",pack.math);
	for(i=0;i<n;i++){
		printf("Value[%d] = %d\n",i,pack.values[i]);
	}
       	if(pack.math == '+'){
		for(i=0;i<pack.size;i++){				
			result += (long) pack.values[i];
		}
	}else if(pack.math == '-'){
		for(i=0;i<pack.size;i++){				
			result -= (long) pack.values[i];
		}
	}else if(pack.math == 'x'){
		result = 1;
		for(i=0;i<pack.size;i++){				
			result *= pack.values[i];
		}
	}else{
		result = -99999;
	}
        write(client_sockfd, &result, sizeof(long));
	result = 0;
        close(client_sockfd);
    }
}
