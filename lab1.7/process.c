
#include <stdio.h>
#define RAND_MAX 1000
#define Arrsize 10

void FCFS(void);
int create(void);

typedef struct process	{
	int id;
	int burst;
	int waittime;
	int turnaroundtime;
 };

struct process procArr[Arrsize];


int n, exeTime[100];
int processtime;

int main() 
{
	int choice ;
	printf("Hello, 	choose which scheduling algorithm you want to use\n" 
	"1 : FCFS\n" "2 : SJF\n" "3 : Priority Scheduling\n" "4 : Round-Robin Scheduling\n");
	scanf("%d", &choice);
	printf("You entered: %d\n", choice);
	
	
	create();
	printf("processes are \n");
	

	
	int p;
	for(p = 0; p<10;p++) {
		printf("PID : %d\n", procArr[p].id);
		printf("BURSTTIME : %d\n", procArr[p].burst); 
		printf("WAITTIME : %d\n", procArr[p].waittime); 
		printf("TURNAROUNDTIME : %d\n\n", procArr[p].turnaroundtime);
	
		}
	
	
	
	
return 0;

}
int create() {

	int i = 0;
	int wait =0;

	for(i; i<Arrsize; i++) {
		procArr[i].id = i+1;
		procArr[i].burst = rand() % 20;
		procArr[i].waittime = wait;
		procArr[i].turnaroundtime = procArr[i].waittime + procArr[i].burst;
		wait = procArr[i].burst + wait;
	} 
	processtime = wait + procArr[i].waittime;
return 0;
}






