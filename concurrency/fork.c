#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/wait.h>

int main(int argc, char*argv[]) {
  int pid;
  pid_t childwait;
  int n = 0;

  printf("Before fork: n = %d\n", n);
  sleep(1);

  // Fork the process - the PID of the child process will be 0
  pid = fork();
  sleep(2);

  if(pid == 0) {
    printf("\t\t\t\tChild process:\n");
    printf("\t\t\t\t   n=%d, PID=%d\n",n, pid);
    while(n < 10) {
      printf ("\t\t\t\tC%d\n", n);
      sleep(1);
      n++;
    }
    sleep(2);
    printf("\nChild process: complete, n = %d\n", n);
  }
  else {
    printf("\tParent process:\n");
    printf("\t   n=%d, Child PID=%d\n",n, pid);
    while(n < 5) {
      printf ("\tP%d\n", n);
      sleep(1);
      n++;
    }
    printf("Parent process: waiting for child to complete\n");
    wait(&childwait);
    printf("Parent process: child complete\n");
    sleep(2);
    printf("\nParent process: complete, n = %d\n", n);
  }

  printf("PID %d complete\n", pid);
  exit(0);
}
