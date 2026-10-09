#include <stdio.h>
#define MAXLINE 1000

/* 1-19: Write reverse(s) function to reverse character string.
Use to write program that reverses input one line at a time.*/

void reverse(char s[]);
int mygetline(char line[], int lim);

int main()
{
  int len;
  char line[MAXLINE];

  while ((len = mygetline(line, MAXLINE)) > 0) {
    reverse(line);
    printf("%s", line);
  }
  return 0;
}

void reverse(char s[])
{
  int i, c, len;

  len = 0;
  while (s[len] != '\0')
    ++len;  // len should end as index of null char at end of string (equal to length pre null char)
  --len;	// set len to index of last char of string
  if (s[len] == '\n')
    --len; // ok, don't flip new line, i guess :)
  for (i=0; i < len; ++i) {
    c = s[i];
    s[i] = s[len];
    s[len] = c;
    --len;
  }
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
