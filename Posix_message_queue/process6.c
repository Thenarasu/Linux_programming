//////////////////////////=====> AUTHOR NAME: THENNARASU
//////////////////////////=====> DATE       : 22-01-2019

///collecting 5 process data , that data to used shared memory 


#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <error.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>

unsigned char buff1[8192];
unsigned char buff2[8192];
unsigned char buff3[8192];
unsigned char buff4[8192];
unsigned char buff5[8192];
unsigned char buff6[8192];
int main()
{
	int ret,i,j=0;
	mqd_t mqopen;
	ssize_t recv;
	unsigned int prio;
	struct mq_attr my_attr;



	//As we are using existing mq. we are sending 2 parameters only if we create a new message queue, we have to send 4 parameters

	mqopen = mq_open("/ten",O_RDWR);   //name of message queue must be starting with / and open a message queue

	//recive the all messages from message queue
	recv = mq_receive(mqopen,buff1,8192,&prio);
	strcpy(&buff6[0],buff1);                    //copy the message buff1 to buff6 using strcpy function call

	recv = mq_receive(mqopen,buff2,8192,&prio);
	for(i=0;buff1[i] != '\0';i++)
		j++;
	strcpy(&buff6[j],buff2);                    //copy the message buff2 to buff6 using strcpy function call
	
	recv = mq_receive(mqopen,buff3,8192,&prio);
	for(i=0;buff2[i] != '\0';i++)
		j++;
	strcpy(&buff6[j],buff3);                    //copy the message buff3 to buff6 using strcpy function call

	recv = mq_receive(mqopen,buff4,8192,&prio);
	for(i=0;buff3[i] != '\0';i++)
		j++;
	strcpy(&buff6[j],buff4);                    //copy the message buff4 to buff6 using strcpy function call

	recv = mq_receive(mqopen,buff5,8192,&prio);
	for(i=0;buff4[i] != '\0';i++)
		j++;
	strcpy(&buff6[j],buff5);                    //copy the message buff5 to buff6 using strcpy function call


	//shared memory start

	int shmid1;
	int fd;
	char *data_ptr;
	ssize_t ret_read;
	shmid1 = shmget(111,8192,IPC_CREAT | S_IRUSR |S_IWUSR | S_IRGRP | S_IROTH);

	//returns the virtual address where shared memory is mapped

	data_ptr = shmat(shmid1,NULL,0);
	perror("shmat:");

	//copy some data into shared is the address return from shmat
	strcpy(data_ptr,buff6);
        //The virtual address mapped to shared memory has to be detached after usage is done so shmdt is used
	shmdt(data_ptr);
	perror("shmdt:");

	
	perror("mq_close:");
	perror("my_close:");
	return 0;
}
