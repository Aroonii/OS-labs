/**
 * Simple shell interface program.
 *
 * Operating System Concepts - Ninth Edition
 * Copyright John Wiley & Sons - 2013
 */

#include <stdio.h>
#include <unistd.h>



#define MAX_LINE		80 /* 80 chars per line, per command */
void ChildProcess(void);           /* child process prototype*/


int main(void)
{
	char *args[MAX_LINE/2 + 1];	/* command line (of 80) has max of 40 arguments */
    int should_run = 1;
	
	int i, upper;
		
    while (should_run){   
        printf("osh>");
        fflush(stdout);
	
	pid_t pid;
	pid = fork();

	//execvp(args[0], args);
	if(pid ==0) 
	{ 
		ChildProcess();
	}

        
        /**
         * After reading user input, the steps are:
         * (1) fork a child process
         * (2) the child process will invoke execvp()
         * (3) if command did not include &, parent will invoke wait()
         */
    }
    
	return 0;
}

void ChildProcess(void)
{
	int i;
	//execvp(args[0], args);
	for(i=1; i<= MAX_LINE; i++) {
		printf("    This line is from child, value = %d\n", i);
	printf("   ***Child process is done ***\n");
	}

}



