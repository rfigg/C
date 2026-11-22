/* Challenge - 10 - I/O - String functions
2 command line arguments, character and filename
print lines of file containing character
Use fgets or getline (or try both) and puts
Lines terminate with \n, max length 256
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 256

int main(int argc, char *argv[])
{
    char ch = '\0';
    FILE *fp = NULL;
    char *buffer = NULL;
    size_t bufSize = BUF;
    size_t numChars;

    buffer = (char *)malloc(bufSize * sizeof(char));
    if (buffer == NULL) {
        puts("Couldn't allocate buffer.");
        return 1;
    }

    if (argc != 3) {
        puts("Run with character then filename as arguments.");
        return 1;
    }

//    ch = argv[1][0];        // first char of string should be char to match. (he does this way)
    ch = *argv[1];        // first char of string should be char to match. Deref to char worked!
    
    //open file
    fp = fopen(argv[2], "r");
    if (fp == NULL) {
        puts("Can't open file.");
        return 1;
    }

    //read in a line of the file
    //loop through file until EOF
    while ((numChars = getline(&buffer, &bufSize, fp)) != -1) {
        //check if line contains character
        //print line
        if (strchr(buffer, ch)) {
            fputs(buffer, stdout);  // avoiding added newline of puts
        }
    }
    
    free(buffer);
    fclose(fp);

    return 0;
}

/* Results
Uses constant for bufsize
Writes his own strchr : int has_ch(char ch, const char *line)
    Uses cool loop while(*line) - increments deref'd char until \0
Uses array instead of malloc for buffer
Doesn't need filename pointer, just uses argv[2]
Uses fgets instead of getline (since we know no null data)
Forgot to close file.
*/

