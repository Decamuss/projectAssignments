#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	int i,j;
	char *temp;

   for(i=1;i<argc-1;i++)
   {
     for(j=i+1;j<argc;j++)
     {
       if(strcmp(argv[i],argv[j])>0)
       {
        temp = argv[i];
        argv[i] = argv[j];
        argv[j] = temp;
       }
     }
   }

   for(i=1;i<argc;i++)
   {
   puts(argv[i]);
   }
	return 0;
}
    


