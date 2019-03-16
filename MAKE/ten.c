/*----------------------------------------------------*/
/*   AUTHOR    	 : THENNARASU            	      */
/*   DATE 	 : 16-03-2019	        	      */
/*   FILE NAME 	 : ten.c	        	      */
/*   DESCRIPTION : Arithmetic operation		      */
/*----------------------------------------------------*/

/*header file declaration*/
#include "make.h"

/*Function defenition and prototype*/

/*Global variable Deaclarations*/
int a,b,c;

int main()
{
	printf("Enter the values\n");
	scanf("%d%d",&a,&b);
	add(a,b);
	sub(a,b);
	mod(a,b);
	div(a,b);
	mul(a,b);
	return 0;
}
