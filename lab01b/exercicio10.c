#include <stdio.h>
#include <stdlib.h>

int** multiplicaLinha(int **matriz, int n, int m, int linha_multi, int n_multiplica){ //(*matriz)[3] isso ocorre quando nao mandamos um ponteiro

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(linha_multi == i){
                matriz[i][j] = matriz[i][j]*n_multiplica;
            }
        }
    }
    printf("entrou");
    return matriz;
}

int** multiplicaColuna(int **matriz, int n, int m, int coluna_multi, int n_multiplica){ //(*matriz)[3] isso ocorre quando nao mandamos um ponteiro

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(j == coluna_multi){
                matriz[i][j] = matriz[i][j]*n_multiplica;
            }
        }
    }
    return matriz;
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

    matriz = multiplicaLinha(matriz, 2, 3, 1, 2);
    matriz = multiplicaColuna(matriz, 2, 3, 1, 2);

    //print matriz transposta 
    printf("\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++){
            printf("%d ", matriz[i][j]);
        } printf("\n");
    }
}