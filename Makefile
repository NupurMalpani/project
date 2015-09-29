main_c.o: main_c.c main.h errhand.h bitio.h
	cc -c main_c.c
main_e.o: main_e.c main.h errhand.h bitio.h
	cc -c main_e.c
bitio.o:bitio.c bitio.h errhand.h
	cc -c bitio.c
