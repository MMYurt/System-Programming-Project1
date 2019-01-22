#include <stdio.h>
#include <unistd.h>
#include <errno.h> /* EINVAL */
#include <string.h>
#include <sys/resource.h>

#define set_myFlag 355


int main(){
	int ret_val = -EINVAL;
	int sonuc = 0;
	int priority = 15;
	int which = PRIO_PROCESS;
	int ret;
	ret = setpriority(which, getpid(), priority);
		
	printf("\nMain - pid: %d\n", getpid());
	ret_val = syscall(set_myFlag, getpid(), 0);
	
	if(ret_val == 0){
		printf("Success! Flag atandı\n");	
	}
	
	else{
		printf("Error! %s\n", strerror(-ret_val));
		}
		
	sonuc = fork();
	
	if ( sonuc == 0 ){
		printf("Çocuk oluştu\n");	
		}
		
	else if (sonuc > 0) {
		printf("Parent prosesin içindeyiz\n");
		}
		
	else{
		printf("Çocuk oluşmadı\n");
		printf("Error! %s\n", strerror(-sonuc));
		
		}
		
	
}
