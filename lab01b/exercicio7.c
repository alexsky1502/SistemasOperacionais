#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa{
    char nome[10];
    int idade;
} Pessoa;

int main(){
    int i;

    Pessoa* lista = malloc (3 * sizeof(Pessoa));

    strncpy(lista[0].nome, "JOSE", 10);
    lista[0].idade = 20;

    strncpy(lista[1].nome, "JOSIAS", 10);
    lista[1].idade = 33;
    
    strncpy(lista[2].nome, "JOSUE", 10);
    lista[2].idade = 22;
    
    for(i = 0; i < 3; i++){
        printf("Nome: %s\nIdade: %d\n\n", lista[i].nome, lista[i].idade);
    }

    free(lista);

    return 0;
}