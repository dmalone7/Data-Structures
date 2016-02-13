#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int sreplace(char newc, char oldc, char *s);
static char *nexttok;

char *stok(char *str, char ch)
{
  if (ch == '\0')
  {
    ch = ' ';
  }

  if (str != NULL)
  {
    while (*str == ch)
    {
      str++;
    }

    if (*str == '\0')
    {
      return NULL;
    }

    nexttok = str;

    while (*nexttok != ch)
    {
      nexttok++;

      if (*nexttok == '\0')
      {
	return str;
      }
    }

    *nexttok = '\0';
    nexttok++;

    return str;
  }
  else
  {
    char *temptok = nexttok;

    while (*temptok == ch)
    {
      temptok++;
    }

    if (*temptok == '\0')
    {
      return NULL;
    }

    nexttok = temptok;

    while (*nexttok != ch)
    {
      nexttok++;

      if (*nexttok == '\0')
      {
	return temptok;
      }
    }

    *nexttok = '\0';
    nexttok++;

    return temptok;
  }

  return 1;
}
