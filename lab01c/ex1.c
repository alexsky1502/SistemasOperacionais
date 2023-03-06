#include <stdio.h>

int main(int argc, char *argv[]){
	char texto[100];
	FILE* file;
	if (argv[1] == NULL) {
		printf("modo de uso: cat /path/to/file");
	} 
	file = fopen(argv[1], "r");
	fgets(texto, sizeof(texto), file);
	printf("%s", texto);
	fclose(file);
}
