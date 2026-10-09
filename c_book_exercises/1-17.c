#include <stdio.h>
#define TOOSMALL 80
#define MAXLINE 1000

/* Print all input lines that are longer than 80 characters */
/* Pseudo: read a line (func). if size > 80, print it. */

int mygetline(char line[], int lim);

int main()
{
  char line[MAXLINE];
  int len;

  while ((len = mygetline(line, MAXLINE)) > 0)
    if (len > TOOSMALL)
      printf("%s", line);
/*  if ((line[len] != '\n') && (len > TOOSMALL))
    putchar('\n'); */
  return 0;
}

int mygetline(char line[], int lim)
{
  int c, i;

  for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    line[i] = c;
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;  
}

/*
Book answer uses the more advanced getline with j.
Leaving, shouldn't matter: any line near limit is over minimum. Not printing count.
*/
