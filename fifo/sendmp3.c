#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <error.h>

int main()
{
	int ret_val;
	ssize_t ret_read,ret_write;
	unsigned char buff[1000000];
	int fd,fd1;

	//open system call 
	fd  = open("./Kannaana-Kanney-MassTamilan.org.mp3",O_RDONLY);   //open a file to do read and write operations

	perror("open:");                                                //checking the last error on system call

        //read system call
	ret_read = read(fd,buff,900000);				//read the data from file descriptor 

	perror("read:");						//checking the last error on system call

	fd1 = open("pipe1",O_WRONLY);					//open a fifo to do write operation 

	perror("open:");						//checking the last error on the system call

	//write system call
	ret_write = write(fd1,buff,900000);				//write the data mentioned in second argument on the open file opened in 'open'system call

	perror("write");

	close(fd);

	close(fd1);

	return 0;
}
