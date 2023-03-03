#include <stdio.h>

int main(int argc, char *argv[]){
	char texto[100];
	FILE* file;
	if (argv[1] == NULL) {
		printf("colocar o caminho do arquivo entrada.txt");
	} //"/SistemasOperacionais/LabAula02/entrada.txt"
	file = fopen(argv[1], "r");
	fgets(texto, sizeof(texto), file);
	printf("%s", texto);

}
