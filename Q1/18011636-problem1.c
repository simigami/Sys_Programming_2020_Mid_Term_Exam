#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	pid_t pid; //make a variable that stores pid values

	if((pid=fork())<0){ //if fork error happens
		perror("error in fork()\n");
	}
	else if(pid!=0){ //if this process is a parent process
		printf("I am a parent process. My pid is %d and child is %d\n",getpid(),pid);
		//prints its pid and its child pid
	}
	else if(pid==0){ //if this process is a child process
		printf("I am a child process.\nMy parent pid is %d My pid is %d\n",getppid(),getpid());		//prints its pid and its parent pid
	}
	
	exit(EXIT_SUCCESS);
}
