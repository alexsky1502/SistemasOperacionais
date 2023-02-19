#include <stdio.h>

int main(){
    float n1, n2, n3, media;
    printf("digitar os tres numeros separados por um espaco (i.e, 3 4 5): ");
    scanf("%f %f %f", &n1, &n2, &n3);
    media = (n1 + n2*2 + n3*3)/7;
    if(media < 4){
        printf("E\n");
    } else if (media < 6){
        printf("D\n");
    } else if (media < 7.5){
        printf("C\n");
    } else if (media < 9) {
        printf("B\n");
    } else {
        printf("A\n");
    }
}