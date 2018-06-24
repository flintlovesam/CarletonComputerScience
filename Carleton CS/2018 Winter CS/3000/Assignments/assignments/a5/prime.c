#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct thread_data {
   int n;
   int result; } thread_data;

   typedef struct thread_data2 {
      int n1;
      int result1; } thread_data2;

/* Inefficiently, compute successive prime numbers.
   Return the nth prime number.  */
void* compute_prime (void * arg) {
   /* dereference the parameter */
   thread_data * tdata = (thread_data *)arg;
   thread_data2 * tDangit = (thread_data2 *)arg;


   int n = tdata->n;
   int n1 = tDangit->n1;
   int candidate = 2;

   while (true) {
      int factor;
      int is_prime = true;

      /* test primality by successive division.  */
      for (factor = 2; factor < candidate; ++factor)
         if (candidate % factor == 0) {
            is_prime = false;
            break;
         }
      /* is prime number we're looking for?  */
      if (is_prime) {
         if (--n == 0) {
            /* define the result  */
		    tdata->result = candidate;
            pthread_exit(NULL);
         }
      }
      ++candidate;
   }

   while (true) {
      int factor;
      int is_prime = true;

      /* test primality by successive division.  */
      for (factor = 2; factor < candidate; ++factor)
         if (candidate % factor == 0) {
            is_prime = false;
            break;
         }
      /* is prime number we're looking for?  */
      if (is_prime) {
         if (--n1 == 0) {
            /* define the result  */
       tDangit->result1 = candidate;
            pthread_exit(NULL);
         }
      }
      ++candidate;
   }



}

int main (){
   pthread_t tid;
   thread_data tdata;
   thread_data2 tDangit;
   time_t t;

   /* intialize random number generator */
   srand((unsigned) time(&t));

   tdata.n=rand() % 5000;
   tDangit.n1=rand() % 5000;

   printf("i is:  %d ", tdata.n);
   printf("j is: %d  ", tDangit.n1);
   // printf("The %dth product of the two above numbers is", (tdata.n * tDangit.n1));

   /* start the thread, up to "tdata.n" */
   pthread_create (&tid, NULL, compute_prime, (void *)&tdata);
   pthread_create (&tid, NULL, compute_prime, (void *)&tDangit);


   /* wait for the thread to complete  */
   pthread_join (tid, NULL);

   /* print the computed prime */
   printf("pi is %d.\n", tdata.result);
   printf("pj is %d.\n1", tDangit.result1);

  printf("Their product is %d.\n", (tDangit.result1*tdata.result));
}
