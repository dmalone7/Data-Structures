#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *strmatch(char *str, char *s)
{
  if (*s == '\0')
  {
    return str;
  }

  char *a, *b;
  a = str;
  b = s;

  while (*str != '\0')
  {
    while (*a == *b)
    {
      a++;
      b++;

      if (*b == '\0')
      {
	return a;
      }
    }
    str++;
    a = str;
    b = s;
  }
  return NULL;
}
