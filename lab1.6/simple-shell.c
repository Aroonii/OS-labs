


/**
 * Simple shell interface program.
 *
 * Operating System Concepts - Ninth Edition
 * Copyright John Wiley & Sons - 2013
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



#define MAX_LINE		80 /* 80 chars per line, per command */
void ChildProcess(char word[]);           /* child process prototype*/


int main(void)
{
	char *args[MAX_LINE/2 + 1];	/* command line (of 80) has max of 40 arguments */
    int should_run = 1;
	
	int i, upper;
	char word[MAX_LINE];
	char s[MAX_LINE];
	int ln;
	
    while (should_run){   
        printf("osh>");
        fflush(stdout);
	
	 fgets(s, MAX_LINE, stdin);
	  int ln =strlen(s);
	  int i;
	  int p;
	  char c;
	for(i=0; i<=ln;i++) {
		c = s[i];
		if(c == ' ') {
			for(p=0; p<i;p++) {
				word[p] = s[p];
			}
		}else {
			for(p=0; p<=ln; p++) {
				word[p] =s[p];
			}
		}
	}
	    
	pid_t pid;
	pid = fork();

	
	if(pid <0) {
		perror("fork() error");
		exit(-1);
	if(pid !=0) {
		printf("i'm the parent %d, my child is %d\n", getpid(), pid);
		c = word[ln-1];
		if(c!="&") {
			wait(NULL);
		} else {
			ChildProcess(word);
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
	if(word =="exit") {
		exit(0);
	}
	printf("i'm the child%d, py parent is %d\n", getpid(), getppid());
	execl("bin/echo","echo", word, NULL);

}



