#include <stdio.h>

int main(int argc, char *argv[]){
	char texto[100];
	FILE *old, *new;
	if (argv[1] == NULL || argv[2] == NULL) {
		printf("modo de uso: ./cp /path/to/file /path/to/file");
	} 
	old = fopen(argv[1], "r");
	fgets(texto, sizeof(texto), old);

    new = fopen(argv[2],"w");
    fprintf(new,"%s",texto);
    
	fclose(old);
    fclose(new);
}
