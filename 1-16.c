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
  while ((len = mygetline(line, MAXLINE)) > 0) {
    printf("%d, %s", len, line);
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }
  printf("Length: %d\n", max);
  if (max > 0)
    printf("%s", longest);
  return 0;
}

int mygetline(char s[], int lim)
{
  int c, i, j;

  j = 0;
  for (i=0; (c=getchar())!=EOF && c!='\n'; ++i)
    if (i < lim-2) {
      s[j] = c; //copy and increment j only until limit while i keeps counting
      ++j;
    }
  if (c == '\n') { //if file ends on newline, add newline and increment for null char termination
    s[j] = c;
    ++i;
    ++j;
  }
  s[j] = '\0';
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
/* misunderstood question. want to print length and text of each line, and longest at end.
Also question only specifies modify main routine, answer modifies getline like I thought.
Uses second counter in getline along with loop i to track position in array, stop at limit,
and keep counting with i. Leaves space for newline and null char or just null char.*/
