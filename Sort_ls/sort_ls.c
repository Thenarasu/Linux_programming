/*---------------------------------------------*/
/*	Author       : Thennarasu.D	       */
/*	Date	     : 15-Feb-2019	       */
/*	Filename     : sort_ls.c	       */
/*	Description  : sorting ls	       */
/*---------------------------------------------*/

/* include header files */
#include "sort_ls.h"

/* Global variable declaration */


/* Function declaration */

int sort_ls(char argv[]);

int main(int argc,char *argv[])
{
	if(argc>1)
	{
		sort_ls(argv[1]);
	}
	else
		sort_ls(".");
}

int sort_ls(char argv[ ])
{
	DIR *ptr;
	struct dirent *list;
	int n = 0,i,j;
	char *arr[100];
	char temp[100];
        //Function opens a directory stream a corresponding to the directory name returns to the directory poiter
	/* DIR *opendir(const char *name)  */
	ptr = opendir(argv);
	perror("opendir");
        //Read directory
	/* struct dirent *readdir(DIR *dirp)  */
	list = readdir(ptr);
	perror("readdir");

	for(list ; list != NULL; )
	{
		arr[n] = list->d_name;
		n++;
		list = readdir(ptr);
	}

	for( i = 0; i<n-1 ; i++)
	{
		for(j = i; j<n ; j++)
		{
			if(strcmp(arr[i],arr[j])>0)
			{
				strcpy(temp,arr[i]);
				strcpy(arr[i],arr[j]);
				strcpy(arr[j],temp);
			}
		}
	}
	for(i=0;i<n;i++)
		printf("%s\n",arr[i]);
}
