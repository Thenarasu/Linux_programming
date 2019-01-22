#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int main()
{
	int fd;
	//named pipe | fifo
	fd = mknod("pipe1",0644 | S_IFIFO,0); //creating a named pipe 

	printf("file descreptor = %d\n",fd);
}
