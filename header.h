//ANDREY VASCONCELOS CHAVES 
//GRR20172630

#ifndef HEADER
#define HEADER

//Tipo FILE está definido aqui.
#include <stdio.h>



//Denifinição da estrutura contendo os subchunks do arquivo tipo wav.
typedef struct cabecalho
{
	char ChunkID[5];
	int ChunkSize;
	char Format[5];
	char SubChunk1ID[5];
	int SubChunk1Size;
	short Audio_format;
	short NumberOfChannels;
	unsigned int SampleRate;
	int ByteRate;
	short Block_align;
	short Bits_per_sample;
	char SubChunk2ID[5];
	int SubChunk2Size;
    short *Audio_data;
}cabecalho;

//Procedimento que pega os dados do arquivo audio e armazena na memoria. 
void load_header (FILE *audio, cabecalho *head);

//Procedimento que armazena no arquivo output os dados do cabeçalho tirando as amostras de audio.
void print_audio (FILE *output, cabecalho *head);

#endif
