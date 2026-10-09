#include <stdio.h>
#define MAXLINE 1000

/* remove trailing blanks and tabs from input and output, delete entirely blank lines */
/* quick peeked solution: gets line like usual, uses function to trim end and return length (and status)*/

int mygetline(char s[], int m);
int trim(char s[]);

int main()
{
  char line[MAXLINE];

  while (mygetline(line, MAXLINE) > 0)
    if (trim(line) > 0)
      printf("%s", line); 
  return 0;
}

int mygetline(char line[], int lim)
{
  int i, j, c;

  j = 0;
  for (i=0; (c = getchar())!=EOF && c!='\n'; ++i)
    if (i < lim-2) {
      line[j] = c;
      ++j;
    }
  if (c == '\n') {
    line[j] = c;
    j++;
    ++i;
  }
  line[j] = '\0';
  return i;
}

int trim(char line[])
{
  int i;

  i = 0;
  while (line[i] != '\n') // find end of line
    ++i;
  //pseudo: look at prev char. if space or tab, copy \n there, \0 here, decrement i. repeat.
  while ( i>0 && (line[i-1]==' ' || line[i-1]=='\t')) {
    line[i-1] = '\n';
    line[i] = '\0';
    --i;
  }
  return i;  
}

/* Fascinating, return and side effect functions happily not oop */
/* Book answer does things differently, returning -1 for no line or size including \n
where mine returns zero for no line, and size without \n. Seems to not matter since
value isn't used beyond >0 to print.
Mine does do more writes to memory and leave a trail of null characters. Maybe this
is bad form? */
