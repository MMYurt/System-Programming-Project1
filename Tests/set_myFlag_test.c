#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <errno.h> 
#include <string.h> 

#define set_myFlag 355

int main(int argc, char *argv[]){
	int ret_val;
	int pid, flag_value;
	printf("Flag atamak istediğiniz pid değerini girin.\n");
	scanf("%d", &pid);
	
	printf("Atamak istediğiniz flag değerini girin.\n");
	scanf("%d", &flag_value);
	

	ret_val = syscall(set_myFlag, pid, flag_value);
	
	if(ret_val == 0){
		printf("Success!\n");
	}
	else{
		printf("Error! %s\n", strerror(-ret_val));
	}
	
	return ret_val;
}
