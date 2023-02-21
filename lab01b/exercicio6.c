#include <stdio.h>

int main(void) {
    int matriz[2][3], aux, matrizT[3][2];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            printf("digite o valor: ");
            scanf("%d", &matriz[i][j]);
        }
    }

    //print matriz de entrada
    printf("\n");
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", matriz[i][j]);
        } printf("\n");
    }

    //mudar para transposta
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            matrizT[j][i] = matriz[i][j];
        }
    }

    //print da transposta
    printf("\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            printf("%d ", matrizT[i][j]);
        }
        printf("\n");
    }
}