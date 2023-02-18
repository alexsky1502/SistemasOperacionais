#include <stdio.h>
#include <stdlib.h>

int main(){
    int total = 9, i, j;

    for (i = 1; i <= (total/2) +1; i++){
        printf("%*s", i-1, "");
        for (j = i; j <= (total-i)+1; j++){
            printf("%d", j);
        }
        printf("\n");
    }

    return 0;
}