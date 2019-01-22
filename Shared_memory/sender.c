///////////////////  Shared memory process1  /////////////////////////
////////////       Author name :Thennarasu         ///////////////////
////////////       Date        :22-01-2019         ///////////////////
//////////////////////////////////////////////////////////////////////


#include <sys/ipc.h>
#include <sys/shm.h>
#include <error.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>

int main()
{
	int shmid1;
	int fd;
	char *data_ptr;
	ssize_t ret_read;
	shmid1 = shmget(110,8192,IPC_CREAT | S_IRUSR | S_IWUSR | S_IRGRP |S_IROTH); //rw-r--r-- similar to 0644
	perror("shmget: ");
	
	//returns the virtual address where the shared memory is mapped 
	data_ptr = shmat(shmid1,NULL,0);
	perror("shmat:");

	//copy some data into shared is the address returned from shmat()
	fd = open("./tamil",O_RDWR);                    //open a file to do read and write operation 
	perror("open:");
	ret_read = read(fd,data_ptr,100);               //read data into filedescreptor 

	//the virtual address mapped to shared memory has to be detached after usage is done so shmdt is used
	shmdt(data_ptr);
	perror("shmdt");
	close(fd);
	return 0;
}
