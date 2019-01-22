/////////////////////  Shared memory process2 ////////////////////////
////////////          Author name :Thennarasu         ////////////////
////////////          Date        :22-01-2019         ////////////////
//////////////////////////////////////////////////////////////////////


#include <sys/ipc.h>
#include <sys/shm.h>
#include <error.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int shmid1,fd;
	char data[300];
	char *data_ptr;
	shmid1 = shmget(110,8192,IPC_CREAT | S_IRUSR | S_IWUSR | S_IRGRP |S_IROTH); //rw-r--r-- similar to 0644
	perror("shmge ");
	
	//returns the virtual address where the shared memory is mapped 
	data_ptr = shmat(shmid1,NULL,0);
	perror("shmat");

	//copy some data into shared is the address returned from shmat()
	strcpy(data,data_ptr);
	data[150] = '\0';
	printf("%s\n",data);
	
	//the virtual address mapped to shared memory has to be detached after usage is done so shmdt is used
	shmdt(data_ptr);
	perror("shmdt");
	return 0;
}

