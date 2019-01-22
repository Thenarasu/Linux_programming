/////////////////////////////////// System calls for working with files and directories //////////////////////////////////

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int file_discreptor = 0;
	ssize_t ret_write;

	//open system call open a file to do read and write operations
	file_discreptor = open("./file1",O_CREAT | O_RDWR,0644);  //readwrite-read--read-- similar to 0644

	//write system call writes the data mentioned in second argument on the open file opened in 'open' system calls
        ret_write = write(file_discreptor,"content added",13);
	printf("file_discreptor = %d\t total number of bytes written on file is = %d\n",file_discreptor,ret_write);

	//close system call close the file opened using open system call
	close(file_discreptor);
	return 0;
}
