#include <stdio.h>
#include <string.h>

int main(){
    char nome[50], nome2[50];
    printf("digitar dois nomes separados em espaco (i.e, [Alex Gabriel]): ");
    scanf("%s %s", &nome, &nome2);
    if(strcmp(nome, nome2) < 0){
        printf(nome);
        printf(nome2);
    } else if (strcmp(nome, nome2) > 0){
        printf(nome2);
        printf(nome);
    } else {
        printf(nome);
        printf(nome2);
    }
}