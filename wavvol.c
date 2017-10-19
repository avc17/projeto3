#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"

#define TAM 100


cabecalho head;

void vol_audio (FILE *output, float vol)
{   
long i;

    for (i = 0; i < head.SubChunk2Size/2; i++)
    {
		head.Audio_data[i] *= vol;
        fwrite(&head.Audio_data[i], 2, 1, output);
 
    }
}
int main (int argc, char *argv[])
{
FILE *audio, *output;  
char filename[TAM];
char saida[TAM];
int i;	
float x;
    saida[0] = 0;	
	filename[0] = 0;
    if (pertence(argc, argv, "-i"))
    {
        i = arg_indice(argc, argv, "-i");
        strcpy(filename, argv[i]);
    }
    if (pertence(argc, argv, "-o"))
    {
        i = arg_indice(argc, argv, "-o");
        strcpy(saida, argv[i]);
    }

    if (pertence(argc, argv, "-l"))
    {
        i = arg_indice(argc, argv, "-l");
		x = atof(argv[i]);
    }
	
	if (filename[0] == 0)
		audio = stdin;
	else
		audio = fopen(filename, "r");

	if (audio == NULL)
	{	
		perror("Erro");
		return -1;
	}

	load_header(audio, &head);

	if (saida[0] != 0)
	{
		output = fopen(saida, "w");
		print_audio(output, &head);
		vol_audio(output, x);
	}
	else
	{
		print_audio(stdout, &head);
		vol_audio(stdout, x);
	}
}
