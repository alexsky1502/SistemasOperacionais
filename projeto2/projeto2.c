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

// Struct de conta que sera usada nas transferencias
struct c {
  int saldo;
  char id;
};
typedef struct c conta;

// mutex global usado para evitar race condition
pthread_mutex_t mutex;

// criamos duas contas e definimos o valor padrao de transferencia
conta A, B;
int valor = VALOR_TRANSFERENCIA;

// funcao que transfere da conta A para conta B
void transferA(){
    
    printf("Transferindo %d da conta %c para conta %c\n", valor, A.id, B.id);
    // verifica se o saldo da conta A Ã© suficiente para transferencia
    if (A.saldo >= valor){                  
      A.saldo -= valor;
      B.saldo += valor;
      printf("Transferencia concluÃ­da com sucesso!\n");
    }else{
      printf("saldo insuficiente!\n");  
    }
    
}

// funcao que transfere da conta B para conta A
void transferB(){
    
    printf("Transferindo %d da conta %c para conta %c\n", valor, B.id, A.id);
    // verifica se o saldo da conta A Ã© suficiente para transferencia
    if (B.saldo >= valor){                  
      B.saldo -= valor;
      A.saldo += valor;
      printf("Transferencia concluÃ­da com sucesso!\n");
    }else{
      printf("saldo insuficiente!\n");  
    }
    
}


// The child thread will execute this function
void *transferencia( void *origem)
{
    // travamos o mutex para evitar race condition
    pthread_mutex_lock(&mutex);
    
    // convertemos o parametro void para um char valido
    char *contaOrigem = (char*) origem;

    printf("------\n");
    printf("Saldo da conta %c: %d\n", A.id, A.saldo);
    printf("Saldo da conta %c: %d\n", B.id, B.saldo);
    
    
    // caso o valor passado como parametro seja A, transferimos da conta A -> B
    // caso contrario, transferimos da conta B -> A
    if (*contaOrigem == 'A')
        transferA();
    else
        transferB();
      

    // apÃ³s a funÃ§Ã£o acima realizar a transferencia, destravamos o mutex
    pthread_mutex_unlock(&mutex);
}

int main()
{
    // criamos um array de threads com o numero de transferencias
    pthread_t threads[NUMERO_TRANSFERENCIAS];

    // iniciamos o mutex global criado no inicio do codigo
    pthread_mutex_init(&mutex, NULL);
    
    // Todas as contas comeÃ§am com saldo 100
    A.saldo = 100;
    A.id = 'A';
    
    B.saldo = 100;
    B.id = 'B';


    // declaramos as variaveis que serao usadas para sortear uma conta
    // que sera usada como origem em cada transferencia 
    char contas[2]= {'A','B'};
    char contaSorteada;
    int numAleatorio;
    srand((long) time(NULL));

    for (int i = 0; i < NUMERO_TRANSFERENCIAS; i++) {
        // sorteamos um numero aleatorio 0 ou 1 e usamos o numero para sortear uma conta de orgeim
        numAleatorio = rand()%2;

        // posicao 0 = 'A'
        // posicao 1 = 'B' 
        contaSorteada = contas[numAleatorio];

        // criamos uma thread passando a funcao transferencia() e a conta de origem sorteada acima 
        pthread_create(&threads[i], NULL, *transferencia, (void *) &contaSorteada);
    }

    // destruimos o mutex criado anteriormente
    pthread_mutex_destroy(&mutex);

    return 0;
}
