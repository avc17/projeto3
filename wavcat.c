#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"

#define TAM 100


cabecalho head;

cabecalho head_cat;
void cat_audio (FILE *output, char filenames[])
{   
static long i, j=0;
short *new_audio_data;
FILE *audio = NULL;


	
	 
		audio = fopen(filenames, "r");
		if (audio == NULL)
			perror("Erro");
		else
			load_header(audio, &head_cat);
		
		new_audio_data = malloc(head.SubChunk2Size+head_cat.SubChunk2Size);
		
		for (i = 0; i<head.SubChunk2Size/2; i++)
			new_audio_data[i] = head.Audio_data[i];	
	
		if (head_cat.SampleRate == head.SampleRate)
		{
				for (i = head.SubChunk2Size/2;i<(head.SubChunk2Size+head_cat.SubChunk2Size)/2; i++)
				{
					new_audio_data[i] = head_cat.Audio_data[i];
					
				}
        	
		}
		head.SubChunk2Size += head_cat.SubChunk2Size;
		
		head.Audio_data = new_audio_data;
		fclose(audio);

}
int main (int argc, char *argv[])
{
FILE *audio = NULL, *output = NULL;  
char filename[TAM];
char saida[TAM];
int i, j=0;	

    saida[0] = 0;	
	printf("oi");
    if (pertence(argc, argv, "-o"))
    {
        i = arg_indice(argc, argv, "-o");
        strcpy(saida, argv[i]);
    }
	
	if (saida[0] != 0)
	{
		output = fopen(saida, "w");
	
	}
	
	if (output == NULL)
	{
		perror("Erro");
		return-1;
	}

	for (i = 1; i < argc; i++)
	{
		if ((i != arg_indice(argc, argv, "-o")) && ( i != arg_indice(argc, argv, "-o")-1))
		{
			strcpy(filename, argv[i]);
			
			audio = fopen(filename, "r");
			
			if (audio == NULL)
			{			
				perror("Erro");
					return -1;
			}
		
			if (j == 0)
			{
				load_header(audio, &head);
				
			}
			
			if (j != 0)
			{
				cat_audio(output, filename);
			}
										
			
			j++;
		}
	
	}	
				print_audio(output, &head);
	
        		fwrite(head.Audio_data, head.SubChunk2Size, 1, output);
	



}
