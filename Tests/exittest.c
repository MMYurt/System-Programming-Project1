#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h> /* EINVAL */
#include <string.h>
#include <sys/resource.h>

#define set_myFlag 355

int main(){
	int ret_val = -EINVAL;
	int choice, priority, myflag, which, ret, sonuc, i;
	which = PRIO_PROCESS;		
							
	for(i = 0; i<3; i++){
		sonuc = fork();	
		if(sonuc == 0)
			break;
		}
		
	if(sonuc == -1)
		printf("Fork failed.\n");
	else if(sonuc == 0){
		
		printf("Child pid: %d, Parent pid: %d\n", getpid(), getppid());
		while(1);
		}
		
	else{
		ret_val = syscall(set_myFlag, getpid(), 0);
		if(ret_val == 0)
		printf("Success! Flag atandı\n");				
		else
		printf("Error!. %s\n", strerror(-ret_val));
		
		ret = setpriority(which, getpid(), 15);
		printf("Prio atanan pid: %d, prio değeri %d.\n", getpid(), getpriority(which, getpid()));
		printf("Parent pid: %d\n", getpid());
		while(1);
		}
			
	}
		
	
	
	
