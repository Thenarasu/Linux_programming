/*----------------------------------------------------*/
/*	  Author	: Thennarasu.D		      */
/*	  Date	        : 21Feb2019		      */
/*	  Filename	: ipv4_client.h		      */
/*	  Description   : ipv4 client and server chat */
/*----------------------------------------------------*/



#ifndef IPV4_CLIENT_H
#define IPV4_CLIENT_H


/* include header files  */
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <error.h>

#define BUF_SIZE 8096        /* maximum size of message exchanged between client and server  */

#define PORT_NUM 8015

#endif
