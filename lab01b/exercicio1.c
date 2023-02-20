#include <stdio.h>
#include <stdlib.h>

int main(){
    int tamanho, i, j, linha, menor;

    tamanho = 4;

    int** matriz = (int**) malloc(tamanho * sizeof(int*));
    
    for (i = 0; i <= tamanho; i++)
        matriz[i] = (int*)malloc(tamanho * sizeof(int));

    for (i = 0; i <= tamanho; i++){
        for (j = 0; j < tamanho; j++){
            matriz[i][j] = 1*10*i+j;
        }
    }

    int* valores = (int*) malloc(tamanho * sizeof(int*));

    for (i = 0; i < tamanho; i++){
        for (j = 0; j < tamanho; j++){
            valores[i] += matriz[i][j];
        }
    }

    for (i = 0; i < tamanho; i++){
        if (valores[i] < menor){
            menor = valores[i];
            linha = i;
        }
    }

    for (i = 0; i < tamanho; i++){
        for (j = 0; j < tamanho; j++){
            printf("| %d |", matriz[i][j]);
        }
        printf("\n");
    }
    
    printf("\nA menor soma é %d na linha %d\n", menor, linha);

    for (i = 0; i < tamanho; i++){
        free(matriz[i]);
    }

    free(matriz);
    free(valores);


    return 0;
}