#include <stdio.h>

int main()
{
  int c, nl, blanks, tabs;
  
  nl = blanks = tabs = 0;
  while ((c = getchar()) != EOF)
    if (c == '\n')
      ++nl;
    else if (c == '\t')
      ++tabs;
    else if (c == ' ')
      ++blanks;
  printf("%d blanks, %d tabs, %d newlines\n", blanks, tabs, nl);
}