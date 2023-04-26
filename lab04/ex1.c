/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

struct reg {
    int conteudo; 
    struct reg *prox; 
}; 
typedef struct reg celula;

void imprime(celula *p){
    printf(" %d ", p->conteudo);
    
    if (p->prox == NULL){
        return;
    }
    
    imprime(p->prox);
}

void printTamanho(celula x){
    printf("\ntamanho: %ld\n", sizeof(x));
}

void remove()

int main()
{

    celula a; 
    celula b; 
    celula c; 
    a.conteudo = 1;
    b.conteudo = 2;
    c.conteudo = 3;
    
    a.prox = &b;
    b.prox = &c;
    c.prox = NULL;
    imprime(&a);
    printTamanho(a);
    return 0;
}

