#include <stdio.h>
#include <stdlib.h>

int main(){
    int tamanho, i, j;

    tamanho = 4;

    int** matriz = (int**) malloc(tamanho * sizeof(int*));
    
    for (i = 0; i <= tamanho; i++)
        matriz[i] = (int*)malloc(tamanho * sizeof(int));

    for (i = 0; i <= tamanho; i++){
        for (j = 0; j < tamanho; j++){
            matriz[i][j] = -1*10*i+j;
        }
    }

    printf("Antes:\n");
    for (i = 0; i < tamanho; i++){
        for (j = 0; j < tamanho; j++){
            printf(" %d  ", matriz[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < tamanho; i++){
        for (j = 0; j < tamanho; j++){
            matriz[i][j] = abs(matriz[i][j]);
        }
    }

    printf("\nDepois:\n");
    for (i = 0; i < tamanho; i++){
        for (j = 0; j < tamanho; j++){
            printf(" %d  ", matriz[i][j]);
        }
        printf("\n");
    }



    for (i = 0; i < tamanho; i++){
        free(matriz[i]);
    }

    free(matriz);
}