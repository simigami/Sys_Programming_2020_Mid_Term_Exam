#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	pid_t pid;

	pid=fork(); //make a child process

	if(pid==-1){ //perror if error on fork function
		perror("fork() failed\n");
	}
	else if(pid==0){ //let child process do the execl function
		printf("Start execl func on child process\n");
		execl("/bin/ls", "ls", "-l", NULL); //put a valid arguments on execl function
		//if execl failed
		printf("execl() faild\n");
	}
	else{ //for parent process
		wait((int*)0); //wait until child process is finished
		printf("execl() function execution\n"); //print out that execl function is done by child process
		exit(0); //exit
	}
	return 0; //return for child process
}
