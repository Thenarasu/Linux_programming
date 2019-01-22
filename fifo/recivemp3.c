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

	fd = open("pipe1",O_RDONLY);
	perror("open:");
	ret_read = read(fd,buff,900000);
	perror("read:");

	fd1 = open("./kan.mp3",O_CREAT | O_WRONLY,0764);
	perror("open:");
	ret_write = write(fd1,buff,900000);
	perror("open:");
}
