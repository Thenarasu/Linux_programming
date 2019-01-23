#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <error.h>

char message [ ] = "Hi i'm Naveenkumar process5\n";

int main()
{
	int ret;
	mqd_t mqopen;
	struct mq_attr my_attr;
	my_attr.mq_maxmsg = 102;    // max number of message in queue
	my_attr.mq_msgsize = 1024;  // max size of message

	//name of message queue must be starting with /
	mqopen = mq_open("/ten",O_RDWR);                      //opens an existing  queue
	perror("mq_open:");       

	ret = mq_send(mqopen,message,strlen(message)+1,105);  //send a message to message queue
	perror("mq_send:");                                   
	ret = mq_close(mqopen);                            //close a message queue descreptor
	perror("mq_close:");
}

