#include <stdio.h>

int main(){
    char str[26] = "abcdefghijklmnopqrstuvwxyz", letra;
    int i, posicao = -1;

    letra = 'p';

    printf("Array: %s\nLetra escolhida: %c\n", str, letra);

    for (i = 0; i < 26; i++){
        if (str[i] == letra)
            posicao = i;
    }

    posicao != -1 ? printf("A letra %c esta na posicao %d\n", letra, posicao) : printf("A letra %c nao esta no array.\n", letra);

    return 0;
}