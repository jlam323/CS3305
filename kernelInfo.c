/*
 * Jonathan Lam
 * This program displays the CPU info and kernel info when executed.
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

int main()
{
  execlp("cat", "cat", "/proc/cpuinfo", "/proc/version", NULL);

}

