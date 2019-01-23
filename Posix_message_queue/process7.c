#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <error.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
	int shmid1;
	char data[300];
	char *data_ptr;
	shmid1 = shmget(111,8192,0); // rw-r--r-- similar to 0644
	perror("shmget:");          

	//returns the virtual address where the shared memory is mapped
	data_ptr = shmat(shmid1,NULL,0);
	perror("shmat:");

	//copy some data into shared memory is the address returned from shmat()

	strcpy(data,data_ptr);
	printf("%s\n",data);
	shmdt(data_ptr);
	perror("shmdt:");
	return 0;
}
