/* Challenge - 10 - I/O - String functions
2 command line arguments, character and filename
print lines of file containing character
Use fgets or getline (or try both) and puts
Lines terminate with \n, max length 256
*/

#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
#include <string.h>


int main(int argc, char *argv[])
{
    char ch = '\0';
    char *filename;
    FILE *fp = NULL;
    char *buffer = NULL;
    size_t bufSize = 256;
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

//    ch = argv[1][0];        // first char of string should be char to match
    ch = *argv[1];        // first char of string should be char to match. Deref to char worked!
    filename = argv[2];
    
    //printf("%c, %s\n", ch, filename);
    //open file
    fp = fopen(filename, "r");
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
            //puts(buffer);
            fputs(buffer, stdout);  // avoiding added newline of puts
        }
    }
    
    //printf("%zu\n", (size_t)-1);

    free(buffer);

    return 0;
}
