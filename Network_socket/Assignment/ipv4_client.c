/*----------------------------------------------------*/
/*	  Author	: Thennarasu.D		      */
/*	  Date	        : 21Feb2019		      */
/*	  Filename	: ipv4_server.c		      */
/*	  Description   : ipv4 client and server chat */
/*----------------------------------------------------*/

/* include header files  */
#include "ipv4_client.h"

/* function defenition and prototype   */
static void *recv_from();
static void *send_to();

/* Global variable declarations  */
struct sockaddr_in socket_addr;
int socket_fd,j;
size_t msglen;
ssize_t numbytes;
char str[BUF_SIZE];
char str1[BUF_SIZE];
pthread_t t1,t2;
int s1,s2;
socklen_t length = sizeof(socket_addr);



int main(int argc,char *argv[ ] )
{


	int det1,det2;

        //creating a socket
	socket_fd = socket(AF_INET,SOCK_DGRAM,0);
	perror("socket");


	socket_addr.sin_family = AF_INET;
	socket_addr.sin_port = htons(atoi(argv[1]));
	
	//convert IPV4 addresses from text to binary form
	unsigned int ip_addr = inet_pton(AF_INET,argv[2],&socket_addr.sin_addr);

	while(1)
	{
		/* Create a sender message thread  */
        	s1 = pthread_create(&t1,NULL,send_to,0);

		/* Create a recive message thread  */
		s2 = pthread_create(&t2,NULL,recv_from,0);
	}
	close(socket_fd);
}

static void *recv_from()
{

      	 //recive  a message
	recvfrom(socket_fd,str,200,0,(struct sockaddr*)&socket_addr,&length);
	printf("%s\n",str);
}

static void *send_to()
{
	scanf("%[^\n]%*c",str1);
	sendto(socket_fd,str1,strlen(str1)+1,0,(struct sockaddr*)&socket_addr,sizeof(socket_addr));
}
