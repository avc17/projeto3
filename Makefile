CFLAGS = 	-Wall -g
objs =	 header.o commands.o
header = commands.h header.h
CC = gcc

all:	wavinfo wavrev wavvol wavautovol wavecho wavwide wavcat wavmix


wavinfo: 	wavinfo.o $(objs)
wavrev: 	wavrev.o $(objs)
wavvol:		wavvol.o $(objs)		
wavautovol:	wavautovol.o $(objs)
wavecho:	wavecho.o $(objs)
wavwide:	wavwide.o $(objs)
wavcat:		wavcat.o $(objs)
wavmix:		wavmix.o $(objs)



header.o: 	header.c header.h 
commands.o: 	commands.c commands.h


wavinfo.o:	     wavinfo.c $(header)      
wavrev.o:        wavrev.c $(header) 
wavvol.o:     	 wavvol.c $(header) 
wavautovol.o:    wavautovol.c $(header)
wavecho.o:       wavecho.c $(header)
wavwide.o:       wavwide.c $(header)
wavcat.o:        wavcat.c $(header)
wavmix.o:        wavmix.c $(header)



clean:
				  -rm  wavinfo.o wavrev.o wavvol.o wavautovol.o wavecho.o wavwide.o wavcat.o wavmix.o header.o commands.o

# Remove todos os binários:
purge:	clean
	-rm wavinfo wavrev wavvol wavautovol wavecho wavwide wavcat wavmix


