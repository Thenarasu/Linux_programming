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


static void *threadfun1(void *arg)
{
	unsigned long long int *ptr = (unsigned long long int *)arg;

	unsigned long long int i,k=0;

	for(i=1;i<=(*ptr);i++)
	{
		k+=(i*i);
	}
		printf("%lld\n",k);

}


int main(int argc,char*argv[])

{
	pthread_t t1,t2,t3;
	int s1,s2,s3;
	unsigned long long int input_data1 =10000000000,input_data2 = input_data1*2,input_data3 =input_data2*2;
	void *res1,*res2,*res3;

	/* create a new thread   */
	/* int pthread_create(pthread_t *thread, const pthread_attr_t *attr,void *(*start_routine) (void *), void *arg);*/

	s1 = pthread_create(&t1,NULL,threadfun1,&input_data1);
	
	perror("pthread :");

	s2 = pthread_create(&t2,NULL,threadfun1,&input_data2);

	perror("pthread:");

	s3 = pthread_create(&t3,NULL,threadfun1,&input_data3);

	perror("pthread:");

	/* join with a terminated thread */
        /* int pthread_join(pthread_t thread, void **retval); */
//	threadfun1(&input_data1);

	s1 = pthread_join(t1,&res1);
	perror("pthread_join:");
	
	s2 = pthread_join(t2,&res2);
	perror("pthread_join:");
	
	s3 = pthread_join(t3,&res3);
	perror("pthread_join:");
}
