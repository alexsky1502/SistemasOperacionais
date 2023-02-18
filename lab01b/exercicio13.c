#include <stdio.h>

int main(){
    char str[100] = "Faca um rotina que remova um caracter de uma string do tipo char",aux;
    int remover = 3, i;

    printf("Removendo posicao 34\n");

    printf("Antes:  [ %s ]\n", str);

    for(i = remover; i < 100; i++){
        str[i] = str[i+1];
    }
    
    printf("Depois: [ %s  ]\n", str);

    return 0;
}