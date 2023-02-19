#include <stdio.h>
#include <stdlib.h>

int** transposta(int **matriz, int n, int m){ //(*matriz)[3] isso ocorre quando nao mandamos um ponteiro
    int** matrizT = (int **)malloc(n * sizeof(int*));
    for(int a = 0; a < n; a++){
        matrizT[a] = (int *)malloc(m * sizeof(int));
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            matrizT[i][j] = matriz[j][i];
        }
    }
    return matrizT;
}

int** criaMatriz(){
    int** matriz = (int **)malloc(2 * sizeof(int*));
    for(int a = 0; a < 2; a++){
        matriz[a] = (int *)malloc(3 * sizeof(int));
    }

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
    return matriz;
}

int main(void){
    int** matriz;
    int **p;
    
    matriz = criaMatriz();
    //print matriz de entrada
    printf("\n");
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", matriz[i][j]);
        } printf("\n");
    }

    p = transposta(matriz, 3, 2);

    //print matriz transposta 
    printf("\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++){
            printf("%d ", p[i][j]);
        } printf("\n");
    }
}