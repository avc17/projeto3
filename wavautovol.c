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
int aux;

    for (i = 0; i < head.SubChunk2Size/2; i++)
    {
                aux = head.Audio_data[i];
                aux *= vol;

                if (aux > 32767)
                        head.Audio_data[i] = 32767;
                else if (aux < -32768)
                        head.Audio_data[i] = -32768;
                else   
                        head.Audio_data[i] = aux;

        fwrite(&head.Audio_data[i], 2, 1, output);

    }

}

void auto_vol(FILE *output)
{
long i;
int max = 0;
	for (i = 0; i<head.SubChunk2Size/2; i++)	
		if (abs(head.Audio_data[i])>max)
			max = abs(head.Audio_data[i]);

	vol_audio(output, 32767.0/max);


}
int main (int argc, char *argv[])
{
FILE *audio, *output;  
char filename[TAM];
char saida[TAM];
int i;	
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
		auto_vol(output);
	}
	else
	{
		print_audio(stdout, &head);
		auto_vol(stdout);
	}
}
