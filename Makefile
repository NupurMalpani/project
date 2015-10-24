main_c.o: main_c.c main.h errhand.h bitio.h
	cc -c main_c.c
main_e.o: main_e.c main.h errhand.h bitio.h
	cc -c main_e.c
read1.o:bitio.c buildtreei.c treelist.c list.c
	cc -c read1.c bitio.c buildtreei.c treelist.c list.c
bitio.o:bitio.c bitio.h errhand.h errhand.c
	cc -c bitio.c
errhand.o:errhand.h
	cc -c errhand.c

