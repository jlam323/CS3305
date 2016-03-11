/*
** Jonathan Lam
** Based on source code. Compares the amount of time to make a system
** call verses a call to a simple empty function.
*/

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


void minfunction(){
        /*do nothing*/
}

int main(int argc, char *argv[])
{
  /*
  struct timespec start, end;
  uint64_t elapsedTime;
  int i,s;


  clock_gettime(CLOCK_ID, &start);
     for (i=0; i < 10; i++)
        s = 0;
  clock_gettime(CLOCK_ID, &end);
  elapsedTime = diff(start,end);
  printf("elapsed process CPU time is %llu\n",(long long unsigned int) elapsed
Time);
  */

  struct timespec start, end;
  uint64_t elapsedTime1, elapsedTime2;

  /*measure time for the system call*/
  clock_gettime(CLOCK_ID, &start);
  execl("getpid", "", NULL);
  clock_gettime(CLOCK_ID, &end);
  elapsedTime1 = diff(start, end);

  /*measure the time for the simple function call*/
  clock_gettime(CLOCK_ID, &start);
  minfunction();
  clock_gettime(CLOCK_ID, &end);
  elapsedTime2 = diff(start, end);

  printf("getpid() system call CPU time is %llu\n",(long long unsigned int) elapsedTime1);
  printf("minimal function call CPU time is %llu\n",(long long unsigned int) elapsedTime2);

}




