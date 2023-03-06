#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	char texto;
	FILE* file;

	if (argv[1] == NULL) {
		printf("modo de uso: ./cat /path/to/file");
		exit(1);
	} 

	file = fopen(argv[1], "r");

	texto = fgetc(file);
    while (texto != EOF){
        printf("%c", texto);
        texto = fgetc(file);
    }
  
	fclose(file);
}
