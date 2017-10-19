#include <string.h>
#include "commands.h"


int pertence (int tam, char *argv[], const char *s1)
{
int i;


	for (i = 0; i < tam; i++)
	{
		if (strcmp(argv[i],s1) == 0)
			return 1;
	}	
	return 0;
}



int arg_indice (int tam, char *argv[], const char*s1)
{
int i;
	
	for (i = 0; i < tam; i++)
	{
		if (strcmp(argv[i],s1) == 0)
			return i+1;
	}	
	return 0;

}
