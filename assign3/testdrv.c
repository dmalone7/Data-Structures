#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *stok(char *str, char ch);

//  This is a simple driver to test stok() independent of the
//  student's driver which will be tested later.
//  Used in grade4

int main(){
  char ch1 = ' ';
  char ch2 = 'a';
  char str1[] = "wl w2aend";
  char str2[] = "  wl    w2aaaaend   ";
  char *str;
  char *tok;
  int i;

  str = str1;
  for ( i = 0; i < 2; i++ ) {
    tok  = stok(str,ch1);
    if ( tok != NULL )
      printf("%s\n",tok);
    else {
      printf("ERROR: First token pointer is NULL\n");
      printf("       Discontinuing current test\n");
      str = str2;
      continue;
    }
    fflush(stdout);
    
    tok  = stok(NULL,ch2);
    if ( tok != NULL )
      printf("%s\n",tok);
    else {
      printf("ERROR: Second token pointer is NULL\n");
      printf("       Discontinuing current test\n");
      str = str2;
      continue;
    }
    fflush(stdout);
    
    tok  = stok(NULL,ch1);
    if ( tok != NULL )
      printf("%s\n",tok);
    else {
      printf("ERROR: Third token pointer is NULL\n");
      printf("       Discontinuing current test\n");
      str = str2;
      continue;
    }
    fflush(stdout);
    
    tok = stok(NULL,ch1);
    if ( tok == NULL )
      printf("NULL\n");
    else {
      printf("ERROR: Last token return is not NULL\n");
      printf("       Discontinuing current test\n");
    }
    str = str2;
  }
  return 0;
}
