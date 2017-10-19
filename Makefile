CFLAGS = 	-Wall -g
objs =	 header.o commands.o
header = commands.h header.h


all:	wavinfo wavrev wavvol wavautovol wavecho wavwide wavcat wavmic


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


wavinfo.o:	  gcc wavinfo.c $(header)      
wavrev.o:         gcc wavrev.c $(header) 
wavvol.o:     	  gcc wavvol.c $(header) 
wavautovol.o:     gcc wavautovol.c $(header)
wavecho.o:        gcc wavecho.c $(header)
wavwide.o:        gcc wavwide.c $(header)
wavcat.o:         gcc wavcat.c $(header)
wavmix.o:         gcc wavmix.c $(header)

