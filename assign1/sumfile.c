#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int total;
  int num;
  FILE *fp;

  // Check number of comman line arguments
  if (argc != 2)
  {
    fprintf(stderr,"Usage: %s <filename>\n", argv[0]);
    exit(-1);
  }

  // Open file given on command line
  fp = fopen(argv[1], "r");
  if (fp == NULL)
  {
    perror(argv[1]);
    exit(-1);
  }

  // Read one number at a time and sum all numbers in file
  total = 0;
  while (fscanf(fp, "%d", &num) == 1)
  {
    total += num;
  }

  // Print out total on stdout
  printf("Total = %d\n", total);

  exit(0);
}
