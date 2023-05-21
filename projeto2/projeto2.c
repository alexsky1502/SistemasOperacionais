#define _GNU_SOURCE
#include <stdlib.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sched.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

// 64kB stack
#define FIBER_STACK 1024*64
#define VALOR_TRANSFERENCIA 10
#define NUMERO_TRANSFERENCIAS 100

struct c {
  int saldo;
  char id;
};
typedef struct c conta;

pthread_mutex_t mutex;

conta A, B;
int valor = VALOR_TRANSFERENCIA;

void transferA(){
    
    printf("Transferindo %d da conta %c para conta %c\n", valor, A.id, B.id);
    if (A.saldo >= valor){                  
      A.saldo -= valor;
      B.saldo += valor;
      printf("Transferencia concluída com sucesso!\n");
    }else{
      printf("saldo insuficiente!\n");  
    }
    
}

void transferB(){
    
    printf("Transferindo %d da conta %c para conta %c\n", valor, B.id, A.id);
    if (B.saldo >= valor){                  
      B.saldo -= valor;
      A.saldo += valor;
      printf("Transferencia concluída com sucesso!\n");
    }else{
      printf("saldo insuficiente!\n");  
    }
    
}


// The child thread will execute this function
void *transferencia( void *origem)
{
    pthread_mutex_lock(&mutex);
    
    char *contaOrigem = (char*) origem;
    printf("------\n");
    printf("Saldo da conta %c: %d\n", A.id, A.saldo);
    printf("Saldo da conta %c: %d\n", B.id, B.saldo);
    
    
    if (*contaOrigem == 'A')
        transferA();
    else
        transferB();
    
    pthread_mutex_unlock(&mutex);
}

int main()
{
    pthread_t threads[NUMERO_TRANSFERENCIAS];

    pthread_mutex_init(&mutex, NULL);
    
    // Todas as contas começam com saldo 100
    A.saldo = 100;
    A.id = 'A';
    
    B.saldo = 100;
    B.id = 'B';
    
    char contas[2]= {'A','B'};
    char contaSorteada;
    int numAleatorio;
    srand((long) time(NULL));

    for (int i = 0; i < NUMERO_TRANSFERENCIAS; i++) {
        numAleatorio = rand()%2;
        contaSorteada = contas[numAleatorio];
        pthread_create(&threads[i], NULL, *transferencia, (void *) &contaSorteada);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}

