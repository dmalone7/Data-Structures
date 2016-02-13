#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
  if (argc != 5)
  {
    perror(argv[0]);
    return -1;
  }

  FILE *fp;

  fp = fopen(argv[4], "r");

  int baseX = atoi(argv[1]);
  int baseY = atoi(argv[2]);
  int baseZ = atoi(argv[3]);

  double dis;

  int x, y, z;

  while (fscanf(fp, "(%d, %d, %d)\n", &x, &y, &z) == 3)
  {
    dis = sqrt(pow((x - baseX), 2) + pow((y - baseY), 2) + pow((z - baseZ), 2));
    printf("(%d,%d,%d)   %.1f\n", x, y, z, dis);
  }

  return 0;
}
