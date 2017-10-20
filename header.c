//ANDREY VASCONCELOS CHAVES
//GRR20172630
#include <stdio.h>
#include "header.h"
#include <stdlib.h>

//Procedimento que pega os dados do arquivo audio e armazena na memoria. 
void load_header (FILE *audio, cabecalho *head)
{
	fread(head->ChunkID, 1, 4, audio);
    fread(&head->ChunkSize, 4, 1, audio);
    fread(head->Format, 1, 4, audio);
    fread(head->SubChunk1ID, 1, 4, audio);
    fread(&head->SubChunk1Size, 4, 1, audio);
    fread(&head->Audio_format, 2, 1, audio);
    fread(&head->NumberOfChannels, 2, 1, audio);
    fread(&head->SampleRate, 4, 1, audio);
    fread(&head->ByteRate, 4, 1, audio);
    fread(&head->Block_align, 2, 1, audio);
    fread(&head->Bits_per_sample, 2, 1, audio);
    fread(head->SubChunk2ID, 1, 4, audio);
    fread(&head->SubChunk2Size, 4, 1, audio);
 	//head.Audio_data aponta pra uma area do tamanho head.SubChunk2Size, que é o espaço ocupado pelas amostras.
    head->Audio_data = malloc(head->SubChunk2Size);
    fread(head->Audio_data, head->SubChunk2Size, 1, audio);



}

//Procedimento que armazena no arquivo output os dados do cabeçalho tirando as amostras de audio.
void print_audio (FILE *output, cabecalho *head)
{
	fwrite(head->ChunkID, 1, 4, output);
	fwrite(&head->ChunkSize, 4, 1, output);
	fwrite(head->Format, 1, 4, output);
	fwrite(head->SubChunk1ID, 1, 4, output);
	fwrite(&head->SubChunk1Size, 4, 1, output);
	fwrite(&head->Audio_format, 2, 1, output);
	fwrite(&head->NumberOfChannels, 2, 1, output);
	fwrite(&head->SampleRate, 4, 1, output);
	fwrite(&head->ByteRate, 4, 1, output);
	fwrite(&head->Block_align, 2, 1, output);
	fwrite(&head->Bits_per_sample, 2, 1, output);
	fwrite(head->SubChunk2ID, 1, 4, output);
	fwrite(&head->SubChunk2Size, 4, 1, output);

	
	
	
}















