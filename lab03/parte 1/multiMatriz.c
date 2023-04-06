#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int m, n;
int* A;
int* x;
int* y;

void Print_matrix(char* title, int A[], int m, int n);
void Print_vector(char* title, int y[], int m);

void *Pth_mat_vect(void* rank);


int main(int argc, char* argv[]) {
   int i, j;

   long       thread;
   pthread_t* thread_handles;
  
   thread_handles = malloc(2*sizeof(pthread_t));

   m = 6;
   n = 6;

   A = malloc(m*n*sizeof(int));
   x = malloc(n*sizeof(int));
   y = malloc(m*sizeof(int));
   
   for (i = 0; i < m; i++) 
      for (j = 0; j < n; j++)
        A[i*n+j] = j+5-i;

   Print_matrix("Matriz:", A, m, n);

   for (i = 0; i < n; i++) 
      x[i] = i + 2; 

   Print_vector("Vetor:", x, n);

   for (thread = 0; thread < 2; thread++)
      pthread_create(&thread_handles[thread], NULL,
         Pth_mat_vect, (void*) thread);

   for (thread = 0; thread < 2; thread++)
      pthread_join(thread_handles[thread], NULL);

   Print_vector("o resultado:", y, m);

   free(A);
   free(x);
   free(y);

   return 0;
}

void *Pth_mat_vect(void* rank) {
   long my_rank = (long) rank;
   int i, j;
   int local_m = m/2; 
   int my_first_row = my_rank*local_m;
   int my_last_row = (my_rank+1)*local_m - 1;

   for (i = my_first_row; i <= my_last_row; i++) {
      y[i] = 0.0;
      for (j = 0; j < n; j++)
          y[i] += A[i*n+j]*x[j];
   }

   return NULL;
} 

void Print_matrix( char* title, int A[], int m, int n) {
   int   i, j;

   printf("%s\n", title);
   for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++)
         printf(" %d ", A[i*n + j]);
      printf("\n");
   }
}  

void Print_vector(char* title, int y[], int m) {
   int   i;

   printf("%s\n", title);
   for (i = 0; i < m; i++)
      printf("%d ", y[i]);
   printf("\n");
} 