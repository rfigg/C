#include <stdio.h>
#define MAXLINE 1000

/* modify main routine of longest line program to correctly print length of arbitrarily long input lines, and as much as possible of the text.*/

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
  int len, max;
  char line[MAXLINE], longest[MAXLINE];

  max = 0;
  while ((len = mygetline(line, MAXLINE)) > 0)
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  printf("Length: %d\n", max);
  if (max > 0)
    printf("%s", longest);
  return 0;
}

int mygetline(char s[], int lim)
{
  int c, i;

  for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void copy(char to[], char from[])
{
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i; 
}

/* troubleshooting confilct with 'getline' name. apparently conflict with stdio.h */
