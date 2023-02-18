#include <stdio.h>
#include <stdlib.h>

int main(){
    int tamanho, i, j, linha, valor;

    tamanho = 4;

    int** matriz = (int**) malloc(tamanho * sizeof(int*));
    
    for (i = 0; i <= tamanho; i++)
        matriz[i] = (int*)malloc(tamanho * sizeof(int));

    for (i = 0; i <= tamanho; i++){
        for (j = 0; j < tamanho; j++){
            matriz[i][j] = j+1*10;
        }
    }

    for (i = 1; i <= tamanho; i++){
        for (j = 0; j < tamanho; j++){
            printf("| %d |", matriz[i][j]);
        }
        printf("\n");
    }

    linha =2;
    valor = 5;

    printf("\nMultiplicando linha %d e coluna %d por %d: \n", linha, linha, valor);

    for (i = 1; i <= tamanho; i++){
        matriz[linha][i] *= valor;
    }


    for (i = 1; i <= tamanho; i++){
        matriz[i][linha] *= valor;
    }

    for (i = 1; i <= tamanho; i++){
        for (j = 0; j < tamanho; j++){
            printf("| %d |", matriz[i][j]);
        }
        printf("\n");
    }
    
    for (i = 0; i < tamanho; i++){
        free(matriz[i]);
    }

    free(matriz);

    return 0;
}