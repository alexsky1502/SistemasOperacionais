
#include <stdio.h>
#include <stdlib.h>
 

struct reg {
    int conteudo; 
    struct reg *prox; 
}; 
typedef struct reg celula;

void imprime(celula *p){
    printf(" %d ", p->conteudo);
    
    if (p->prox == NULL){
        printf("\n");
        return;
    }
    
    imprime(p->prox);
}

int tamanho(celula x){
    return sizeof(x);
}

void removeItem(celula *head, int valor){
    printf("removendo item %d\n", valor);
    
    celula *atual, *prox;
    atual = head;
    while(atual->prox != NULL){
        prox = atual->prox;

        if (prox->conteudo == valor){
            atual->prox = prox->prox;
            printf("item %d removido com sucesso\n", valor);
            return;
        }
        atual = prox;
    }
    
    printf("item %d nao foi encontrado\n", valor);
}

int maximo(int tamanho){
    FILE *meminfo = fopen("/proc/meminfo", "r");

    char line[256];
    while(fgets(line, sizeof(line), meminfo))
    {
        int ram;
        if(sscanf(line, "MemTotal: %d kB", &ram) == 1)
        {
            fclose(meminfo);
           
            return  ram/tamanho;
        }
    }

    fclose(meminfo);
    return -1;
}

int main()
{
    celula head;
    celula a; 
    celula b; 
    celula c; 
    a.conteudo = 1;
    b.conteudo = 2;
    c.conteudo = 3;
    
    a.prox = &b;
    b.prox = &c;
    c.prox = NULL;
    
    int tam = tamanho(a);
    printf("\ntamanho da celula: %d\n", tam);
    
    imprime(&a);
    removeItem(&a, 2);
    imprime(&a);
    
    int max = maximo(2);
     printf("maximo de celulas: %d\n", max);
    return 0;
}

