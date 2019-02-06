/*------------------------------------------------------*/
/*	Author	    : Thennarasu D			*/
/*	Date	    : 5-Feb-2019			*/
/*	Filename    : pthread.c				*/
/*	Description : Create thread			*/
/*------------------------------------------------------*/




/* include header files */
#include "pthread.h"

/* Global variable decarations */

/* Function defenitions  */


static void *threadfun(void *arg)
{
	unsigned long long int *ptr = (unsigned long long int *)arg;

	unsigned long long int i,k=0;

	for(i=1;i<=(*ptr);i++)
	{
		k+=i;
		printf("%lld\n",k);
	}

}

int main(int argc,char*argv[])
{
	pthread_t t;
	int s;
	unsigned long long int input_data1 =4294967298;
	void *res;

	/* create a new thread   */
	/* int pthread_create(pthread_t *thread, const pthread_attr_t *attr,void *(*start_routine) (void *), void *arg);*/

	s = pthread_create(&t,NULL,threadfun,&input_data1);
	
	perror("pthread :");

	/* join with a terminated thread */
        /* int pthread_join(pthread_t thread, void **retval); */
	threadfun(&input_data1);

	s = pthread_join(t,&res);
	perror("pthread_join:");
}
