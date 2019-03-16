/*----------------------------------------------------*/
/*   AUTHOR    	 : THENNARASU            	      */
/*   DATE 	 : 16-03-2019	        	      */
/*   FILE NAME 	 : ten.c	        	      */
/*   DESCRIPTION : Arithmetic operation		      */
/*----------------------------------------------------*/


#ifndef MAKE_H
#define MAKE_H

#include <stdio.h>

#define RED "\x1b[;31m"
#define BOLD_GREEN "\x1b[;32m"
#define YELLOW "\x1b[;33m"
#define BLUE "\x1b[;34m"
#define MAGENTA "\x1b[;35m"

void add(int a,int b);
void sub(int a,int b);
void mul(int a,int b);
void div(int a,int b);
void mod(int a,int b);

#endif
