/*------------------------------------------------------*/
/*	Author	    : Thennarasu D			*/
/*	Date	    : 6-Feb-2019			*/
/*	Filename    : mutex.c				*/
/*	Description : Posix Thread header		*/
/*------------------------------------------------------*/



#include "mutex.h"


static int glob = 0;
static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

static void *threadfun(void *arg)
{
	int loops =*((int *) arg);
	int loc,j,s;


	for(j = 0; j < loops; j++)
	{
		s = pthread_mutex_lock(&mtx);
		loc = glob;
		loc++;
		glob = loc;
		s = pthread_mutex_unlock(&mtx);
	}
	return NULL;
}

int main(int argc,char *argv[ ])
{
	pthread_t t1,t2;

        int loops,s;

	loops = (argc>1) ?1000 :100000000;

	if( pthread_create(&t1,NULL,threadfun,&loops) != 0)
		pthread_exit("pthread_create1:");

	if( pthread_create(&t2,NULL,threadfun,&loops) != 0)
		pthread_exit("pthread_create2:");

	if(pthread_join(t1, NULL) != 0)
		pthread_exit("pthread_join1:");

	if(pthread_join(t2, NULL) != 0)
		pthread_exit("pthread_join2:");
	printf("glob = %d\n",glob);
	exit(EXIT_SUCCESS);
	
}
