#include <stdio.h>

int main(void) {
    int matriz[2][3], aux, matrizT[3][2];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    //mudar para transposta
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            matriz[i][j] = matrizT[j][i];
        }
    }

    //print
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            printf("%d ", matrizT[i][j]);
        }
        printf("\n");
    }
}