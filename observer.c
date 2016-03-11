#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <math.h>

#define BILLION  1000000000L

#define CLOCK_ID CLOCK_PROCESS_CPUTIME_ID

/*Compute the difference between two time stamps returned by clock_gettime */

uint64_t diff(struct timespec start, struct timespec end)
{
  uint64_t diff;

  diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;

  return diff;
}


int main(int argc, char *argv[])
{

  pid_t pid;

  struct timespec start, end;
  uint64_t elapsedTime;
  

  if (pid == 0)
  {
    /*measure time for the system call*/
    clock_gettime(CLOCK_ID, &start);
    execvp(argv[1], "");
    clock_gettime(CLOCK_ID, &end);
    elapsedTime = diff(start, end);

    printf("The executable CPU time is %llu\n",(long long unsigned int) elapsedTime);

    execlp("cat", "cat", "/proc/pid/stat", NULL);
  }
  else
  {
    wait(NULL);
  }
  return 0;
}




