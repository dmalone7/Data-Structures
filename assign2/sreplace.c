#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
