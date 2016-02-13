#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int sreplace(char newchar, char oldchar, char *str);
char *strmatch(char *str, char *s);

int main(void)
{
  int charSize = 1024;
  char *tempstr;
  char line1[charSize];
  char line2[charSize];

  line1[charSize - 1] = 'z';
  line2[charSize - 1] = 'z';
  
  while (fgets(line1, charSize, stdin) != NULL)
  {
    if (fgets(line2, charSize, stdin) != NULL)
    {
      if (line1[charSize - 1] == '\0' || line2[charSize - 1] == '\0')
      {
	fprintf(stderr, "Buffer Overflow\n");
	exit(-1);
      }

      sreplace('\0', '\n', line1);
      sreplace('\0', '\n', line2);

      tempstr = strmatch(line1, line2);
      
      if (tempstr != NULL)
      {
	printf("%s\n", tempstr);
      }
      else
      {
	printf("\n");
      }
    }
    else
    {
      printf("End of file.\n");
      exit(-1);
    }
  }

  return 0;
}
