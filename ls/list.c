/*----------------------------------------------------*/
/*   AUTHOR    	 : THENNARASU            	      */
/*   DATE 	 : 25-01-2019	        	      */
/*   FILE NAME 	 : my_ls.c	        	      */
/*   DESCRIPTION : ls COMMAND			      */
/*----------------------------------------------------*/


//INCLUDE THE HEADER FILES
#include "list.h"

//GLOBAL VARIABLES DECLARATIONS 


int main(int argc,char *argv[])
{
	DIR *ptr;
        struct dirent *list;
	int i;
	int fd;

  	//RID2 : EXECUTING my_ls WITHOUT PARAMETERS HAS TO TAKE THE LISTING DIRECTORY AS CURRENT DIRECTORY 
	if(argc == 1)
	{
		ptr = opendir("."); //THE OPENDIR RETURNS THE POINTER TO THE DIRECTORY STREAMS 
	        perror("opendir:");

        	list = readdir(ptr); //THE READDIRECTORY RETURNS TO POINTER DIRENT STRUCTURE
       		perror("readdir:");
        	for(list  ;list !=0; )
        	{
			if((strcmp(list -> d_name,".") !=0 && strcmp(list -> d_name,"..") !=0))
	       		printf(" %s\n",list ->d_name);
		        list = readdir(ptr);
        	}
		//RID5 : CLOSE THE DIRECTORY
		closedir(ptr);  //CLOSES THE DIRECTORY STREAMS
	}

	else if(argc > 1)
	{
		for(i=1;i<argc;i++)
		{
			ptr = opendir(argv[i]);   //THE OPENDIR RETURNS THE POINTER TO THE DIRECTORY STREAMS 
			perror("opendir:");
			//RID3 : EXECUTING my_ls WITH ONE ARGUMENT HAS TO CHECK WETHER THE PASSED ARGUMENT IS A DIRECTORY OR NOT 
			if(ptr == 0)
			{
				printf("It's not a directory\n");
			}
			//RID4 
			else if(ptr != 0)
			{
        			list = readdir(ptr); //THE READDIRECTORY RETURNS TO POINTER DIRENT STRUCTURE
	       			perror("readdir:");
        			for(list  ;list !=0; )
        			{
					if((strcmp(list -> d_name,".") !=0 && strcmp(list -> d_name,"..") !=0))
	       				printf("%ld  %s\n",list ->d_off,list ->d_name);
			               	list = readdir(ptr);
        			}
			}
		}
		//RID5 
		closedir(ptr);   //CLOSES THE DIRECTORY STREAMS
	}
}
