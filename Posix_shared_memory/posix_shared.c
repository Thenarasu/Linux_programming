/*-------------------------------*/
/*				 */
/*				 */
/*  AUTHOR NAME  :THENNARASU     */
/*  DATE	 :23-1-2019	 */
/*  DESCREPTION  :POSIX SHARED   */
/*                       MEMORY  */
/*				 */
/*				 */
/*-------------------------------*/

  //*-------------------------*//
 //      SCHOOL OF LINUX        //
 //*--------------------------*//


#include <stdio.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <error.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>



unsigned char string[ ] ="Thondrin pugalodu thondruga agthilar\nthondralin thondramai nandru\n";

int main()
{

	int fd,fd1,fd2;
	char *ptr;
	ssize_t ret_write;

	fd = shm_open("/ten",O_CREAT | O_RDWR,0644);		//create or open posix shared memory

	perror("shm_open:");					//print the last system call execution 

	fd1 = ftruncate(fd,4096);				//increse or decrese the file size

	perror("ftruncate:");					//print the last system call execution

	ret_write = write(fd,string,strlen(string)+1);		//write content using file descreptor

	ptr = mmap(NULL,4096,PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);	// creates a new mapping in the virtual address space of the calling process
	perror("mmap:");
}
