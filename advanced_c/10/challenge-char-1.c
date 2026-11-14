/* Challenge: char I/O functions challenge 1
Count number of words and characters in file or standard input
0 or 1 command line arguments: stdin if 0, file name if 1
Instructions don't mention it, but only count non space chars
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    int ch = '\0';
    int charCount = 0, wordCount = 0;
    int i = 0;
    bool inWord = false;

    // set fp to file or stdin
    if (argc > 1) {
        // open file in argv[1]
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            printf("File ain't found!\n");
            exit(EXIT_FAILURE);
        }
    } else {
        fp = stdin; 
    }

    // loop reading in one char at a time
    // if not a space, add to charCount
    // and if not in word, now you are.
    // if a space, and if in a word, now you aren't
    // and add to wordCount
    while ((ch = getc(fp)) != EOF) {
        if (!isspace(ch)) {
            charCount++;
            if (!inWord)
                inWord = true;
        } else {
            if (inWord) {
                inWord = false;
                wordCount++;
            }
        }
    }
    // case of last char being non space, count last word
    if (inWord && !isspace(ch))
        wordCount++;
    
    printf("Number of characters: %d\n", charCount);
    printf("Number of words: %d\n", wordCount);

    if (fp != stdin)
        fclose(fp);
    return 0;
}
