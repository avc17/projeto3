//ANDREY VASCONCELOS CHAVES
//GRR20172630

#include <string.h>
#include "commands.h"

//Verifica se a string s1 foi passada como argumento.
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


//Retorna a posição do nome do arquivo no vetor argv.
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
