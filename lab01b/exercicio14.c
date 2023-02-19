#include <stdio.h>
#include <string.h>

int main(void){
    char string[100], carac; 
    int pos, i;
    printf("digite uma string: ");
    fgets(string, sizeof(string), stdin);
    printf("digite uma posicao e um caractere[1 C]: ");
    scanf("%d %c", &pos, &carac);
    printf("%c ", string[0-1]);
    for(int i = strlen(string)-1; i >= 0; i--){
        string[i] = string[i-1];
        if(i == pos+1){
            string[i-1] = carac;
            break;
        } 
    }
    // for(int i = strlen(string)-1; i >= 0; i--){
    //     string[i] = string[i-1];
    //     if(i == pos){
    //         string[i] = carac;
    //         break;
    //     } 
    // }
    printf("%s", string);
}