#include <linux/kernel.h>  			// Process operations 	
#include <linux/syscalls.h>			//System call prototype
#include <asm/errno.h>				//Error library
#include <linux/sched.h>	
#include <linux/cred.h>

asmlinkage long sys_set_myFlag(pid_t pid, int flag_val)
{
	struct task_struct *process;   // defining process struct 
	
	process = NULL;
	
	int oto;
	oto = current_uid();
	
	printk(KERN_DEBUG "Current uid: %d\t", oto);
	
	if (oto == 0)   // checking root previlege
	{
		process=find_task_by_vpid(pid);
		
		if (process == NULL){
			return -ESRCH;
		}
		else {
			if(flag_val == 0 || flag_val == 1){
				process->myFlag = flag_val;
				return 0; 
				
			}
			else{
				printk(KERN_DEBUG "Value : %d\n", oto);
				return -EINVAL;
						
			}
		}
	}
	
	
	else
	{
		printk(KERN_DEBUG "Permission denied! %d\n", oto);
		return -EACCES;  //Do not have root privilege
		 
	}
	return 0;
}
