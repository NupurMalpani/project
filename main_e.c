#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "bitio.h"
#include "errhand.h"
#include "main.h"
#ifdef_STDC_
void usage_exit(char *prog_name);
#else
void usage_exit();
#endif

int main(int argc, char *argv[]) {
	FILE *output;
	BIT_FILE *input;
	setbuf(stdout, NULL);
	if(argc < 3)
		usage_exit(argv[0]);
	input = OpenInputBitFile(argv[1]);
	if(input == NULL)
		fatal_error("error in opening %s for input\n", argv[1]);
	output = fopen(argv[2], "wb");
	if(output == NULL) {
		fatal_error(error in opening %s for output\n", argv[2]);
	printf("expanding %s to %s for output\n", argv[2]);
	argc = argc - 3;
	argv = argv + 3;
	ExpandFile(input, output, argc, argv);
	CloseInputBitFile(input);
	fclose(output);
	putc("\n", stdout);
	return 0;
}
void usage_exit(char *prog_name) {
	char *short_name;
	char *extension;
	short_name = strrchr(prog_name, '\\');
	if(short_name == NULL)
		short_name = strrchr(prog_name, '/');
	if(short_name == NULL)
		short_name = strrchr(prog_name, ':');
	if(short_name != NULL)
		short_name++;
	else
		short_name = prog_name;
	extension = strrchr(short_name, '.');
	if(extension != NULL)
		*extension = '\0';
	printf("\n Usage: %s %s\n",short_name, Usage);
	exit(0);
}
