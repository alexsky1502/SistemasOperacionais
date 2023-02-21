#include <stdio.h>
#include <string.h>

int achaCara(char string[], char carac){
    for(int i = 0; string[i] != '\0'; i++){
        // if(strcmp(string[i], carac) == 0){
        //     return i;
        // }
        if(string[i] == carac){
            return i;
        }
    } return 0;
}

int main(void){
    char string[50], carac;
    printf("digite uma string: ");
    fgets(string, sizeof(string), stdin);
    printf("digite um caractere a ser pesquisado: ");
    scanf("%c", &carac);
    if(achaCara(&string[0], carac) > 0){
        printf("esta na posicao: %d", achaCara(string, carac)+1);
    } else {
        printf("nao encontrado");
    }
}