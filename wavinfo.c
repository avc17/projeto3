#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"

#define TAM 100

cabecalho head;

void print_info (FILE *output)
{
    head.ChunkID[4] = '\0';
    head.Format[4] = '\0';
    head.SubChunk1ID[4] = '\0';
    head.SubChunk2ID[4] = '\0';

    fprintf(output , "riff tag       : \"%s\"\n", head.ChunkID);
    fprintf(output , "riff size      : %d\n", head.ChunkSize);
    fprintf(output , "wave tag       : \"%s\"\n", head.Format);
    fprintf(output , "form tag       : \"%s\"\n", head.SubChunk1ID);
    fprintf(output , "fmt_size       : %d\n", head.SubChunk1Size);
    fprintf(output , "audio_format   : %d\n", head.Audio_format);
    fprintf(output , "num_channels   : %d\n", head.NumberOfChannels);
    fprintf(output , "sample_rate    : %u\n", head.SampleRate);
    fprintf(output , "byte_rate      : %d\n", head.ByteRate);
    fprintf(output , "block_align    : %d\n", head.Block_align);
    fprintf(output , "bit_per_sample : %d\n", head.Bits_per_sample);
    fprintf(output , "data tag       : \"%s\"\n", head.SubChunk2ID);
    fprintf(output , "data size      : %d\n", head.SubChunk2Size);
    fprintf(output , "samples/channel: %d\n", head.SubChunk2Size/4);

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
		print_info(output);
	}
	else
	{
		print_info(stdout);
	}
}
