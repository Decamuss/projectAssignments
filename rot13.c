#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	int st;
	for(int i =0; i<strlen(argv[1]); i++)
	{
		st = argv[1][i];
		if('a' <= st && st <= 'z')
		{
   			st = (((st-'a')+13)%26)+'a';
    		putchar(st);
  		}
		else if ('A' <= st && st <= 'Z')
		{
    		st = (((st-'A')+13)%26)+'A';
    		putchar(st);
		}
		else
		{
			putchar(st);
		}
	}
	
	return EXIT_SUCCESS;
}
    


