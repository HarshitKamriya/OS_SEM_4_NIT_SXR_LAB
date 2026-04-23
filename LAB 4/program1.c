#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main() {
	
	pid_t q;
	q = fork();
	  wait(NULL);

	if(q < 0) printf("NO PROCESS IS CREATED \n");
	
	else  if (q == 0) {
		printf("CHILD CREATED SUCCESSFULLY \n");
		printf("%d \n",getpid());
                printf("%d \n",getppid());
	}

	else { 
	printf("%d \n",getpid());
	printf("%d \n",q);

	}

	printf("ABC \n");


}
