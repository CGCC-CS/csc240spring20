#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> 

/* gcc pthread.c -lpthread */

void *count_to_ten(void *x) {
    int ii;
    printf("\t\t\t\tThread:\n");
    for (ii=0;ii<10;ii++) {
        printf("\t\t\t\tx=%d\n", (*(int *)x)++);
        fflush(stdout);  /* Force all output to the console */
        sleep(1);
    }
    printf("\nThread finished!\n");
    return NULL;
}

int main() {
  int x = 0;
  int y = 0;
  int ii;
  int rc;

  pthread_t new_thread;

  printf("Before:\n");
  printf("  x=%d at %p\n",x, (void *) &x);
  printf("  y=%d at %p\n\n",y, (void *) &y);

  /* Create a thread & check that it was successfully created 
       the thread will execute the count_to_ten function with 
       x as a parameter */
  rc = pthread_create(&new_thread, NULL, count_to_ten, &x);
  if (rc) {
      fprintf(stderr, "ERROR code %d calling pthread_create\n",rc);
      return 1;
  }

  /* This code will execute concurrently with the thread */
  printf("\t\t\tMain:\n");
  for (ii=0;ii<5;ii++) {
      printf("\t\t\ty=%d\n", y++);
      fflush(stdout);
      sleep(1);
  }

  /* Wait for the thread to exit */
  if (pthread_join(new_thread, NULL)) {
      fprintf(stderr, "Error joining pthread\n");
      return 1;
  }

  printf("After - both x & y are modified:\n");
  printf("  x=%d at %p\n",x, (void *) &x);
  printf("  y=%d at %p\n",y, (void *) &y);

  return(0);
}
