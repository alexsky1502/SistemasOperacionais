#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define TOTAL_FILOSOFOS 5

pthread_t filosofos[TOTAL_FILOSOFOS]; // array de pthreads com 5 posições
pthread_mutex_t garfos[TOTAL_FILOSOFOS]; // array de mutex (o numero de garfos sempre é o mesmo dos filosofos nesse problema)

void executa(void *arg)
{
    int n = (int) arg;
    int direita = (n + 1) % TOTAL_FILOSOFOS; // ( ex: filosofo 3 => 3 + 1 mod 5 = 4 )
    int esquerda = n;

    while (1){
        printf("\n filosofo %d pensando! ", n);
        sleep((rand() % 10)); // pensa por um tempo aleatório entre 1 e 10 segundos

        // pega o garfo da esquerda 
        pthread_mutex_lock(&garfos[esquerda]);

        // pega o garfo da direita 
        pthread_mutex_lock(&garfos[direita]);

        // quando para de esperar os garfos, começa a comer por 5 segundos
        printf("\n filosofo %d  comendo! ", n);
        sleep((rand() % 10));  // come por um tempo aleatório entre 1 e 10 segundos

        // devolve garfos 
        pthread_mutex_unlock(&garfos[esquerda]);
        pthread_mutex_unlock(&garfos[direita]);

        // encerra esse ciclo (termina de comer)
        printf("\n filosofo %d ja comeu! ", n);
    }
} 

int main()
{
  // Criamos o array de garfos (recursos que serão disputados pelas threads)
  for (int i = 1; i <= TOTAL_FILOSOFOS; i++){
    int erro = pthread_mutex_init(&garfos[i], NULL); // NULL significa que iniciamos com os parametros default do mutex
    if (erro != 0){
      printf("\n erro criando garfo %d \n", i);
      exit(1);
    }
  }

  /* Cria as cinco threads que representam os 5 filosofos
     passamos a função de comer para cada thread        */
  for (int i = 1; i <= TOTAL_FILOSOFOS; i++){

    /* inicializamos a thread passando o endereço da thread, 
        os atributos (NULL),
        um ponteiro para a função (void *)executa,
        os parametros da função (ponteiro para int)
    */ 
    int erro = pthread_create(&filosofos[i], NULL, (void *)executa, (void*)(size_t) i);
    if (erro != 0){
      printf("\n erro criando filosofo %d \n", i);
      exit(1);
    }
  }

  /* espera a execução das threads
   o segundo parametro é o código de retorno da execução 
   e não é utilizado nesse caso */
  for (int i = 1; i <= TOTAL_FILOSOFOS; i++){
    int erro = pthread_join(filosofos[i], NULL);
    if (erro != 0){
      printf("\n erro finalizando thread %d \n", i);
      exit(1);
    }
  }

  // esperamos os mutexes estarem unlocked e os removemos
  for (int i = 1; i <= TOTAL_FILOSOFOS; i++){
    int erro = pthread_mutex_destroy(&garfos[i]);
    if (erro != 0){
      printf("\n erro finalizando semaforo %d\n", i);
      exit(1);
    }
  }
  return 0;
}

/* REFERENCIAS

https://cs.gordon.edu/courses/cs322/lectures/transparencies/dining_phil.html
https://man7.org/linux/man-pages/man3/pthread_mutex_destroy.3p.html
https://linuxhint.com/pthread-join-multiple-threads-example/
https://embarcados.com.br/threads-posix/
https://stackoverflow.com/questions/22751762/how-to-make-compiler-not-show-int-to-void-pointer-cast-warnings
https://pt.stackoverflow.com/questions/59369/quando-usar-size-t

*/