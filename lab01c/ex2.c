#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	char texto;
	FILE *old, *new;

	if (argv[1] == NULL || argv[2] == NULL) {
		printf("modo de uso: ./cp /path/to/file /path/to/file");
		exit(1);
	} 
	
	old = fopen(argv[1], "r");
    new = fopen(argv[2],"w");
   
	texto = fgetc(old);
    while (texto != EOF){
        fputc(texto, new);
        texto = fgetc(old);
    }
    
	fclose(old);
    fclose(new);
}
