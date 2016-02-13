#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int sreplace(char newc, char oldc, char *s);
char *stok(char *str, char ch);

int main(void)
{
  int strSize = 1024;
  int chSize = 16;
  char *temp;

  char chLine[chSize];
  char strLine[strSize]; 

  while(fgets(chLine, chSize, stdin) != NULL)
  {
    if(fgets(strLine, strSize, stdin) != NULL)
    {
      sreplace('\0', '\n', chLine);
      sreplace('\0', '\n', strLine);

      if (strLine[0] == '\0')
      {
	printf("\n");
      }
      else
      {
	printf("%s\n", stok(strLine, chLine[0]));

	temp = stok(NULL, chLine[0]);

	while (temp != NULL )
	{
	  printf("%s\n", temp);

	  temp = stok(NULL, chLine[0]);
	}
      }
    }
    else
    {
      printf("End of File\n");
      return 1;
    }
  }

  return 1;
}

int sreplace(char newc, char oldc, char *s)
{
  int count = 0;

  while (*s != '\0')
  {
    if (*s == oldc)
    {
      *s = newc;
      count++;
    }

    s++;
  }

  return(count);
}
