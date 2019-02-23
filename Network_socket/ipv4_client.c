/*----------------------------------------------------*/
/*	  Author	: Thennarasu.D		      */
/*	  Date	        : 21Feb2019		      */
/*	  Filename	: ipv4_client.c		      */
/*	  Description   : ipv4 client and server chat */
/*----------------------------------------------------*/

/* include header files  */
#include "ipv4_client.h"

int main(int argc,char *argv[ ] )
{
	struct sockaddr_in socket_addr;
	int socket_fd,j;
	size_t msglen;
	ssize_t numbytes;
	char resp[BUF_SIZE];
        char str1[BUF_SIZE];

	socklen_t length = sizeof(socket_addr);
        //creating a socket
	socket_fd = socket(AF_INET,SOCK_DGRAM,0);
	perror("socket");
	if(socket_fd == -1)
		exit(0);


	socket_addr.sin_family = AF_INET;
	socket_addr.sin_port = htons(atoi(argv[1]));

	//convert IPV4 addresses from text to binary form
	unsigned int ip_addr = inet_pton(AF_INET,argv[2],&socket_addr.sin_addr);

	perror("inet_pton");
	while(1)
	{

		scanf("%[^\n]%*c",str1);
       		//send a message
		sendto(socket_fd,str1,strlen(str1)+1,0,(struct sockaddr*)&socket_addr,sizeof(socket_addr));

		//recive a message
		recvfrom(socket_fd,resp,200,0,(struct sockaddr*)&socket_addr,&length);
		printf("%s\n",resp);
	}
	perror("sendto");
	sleep(2);
	close(socket_fd);

}
