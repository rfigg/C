/* Challenge - Char functions 2 - fgetc and fputc
convert upper to lowercase and vice versa in a file
Take the filename in by command line or ask user
Create temp file to store result, then rename over original
Can use isupper(), tolower(), toupper() (or use ascii value)
*/

#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    char filename[100];
    FILE *fpIn = NULL, *fpOut = NULL;

    // get filename from user if not give in command line
    if (argc == 1) {
        printf("File to flip case? ");
        scanf("%s", filename);
        fpIn = fopen(filename, "r");
    } else {
        fpIn = fopen(argv[1], "r");
    }

    fpOut = fopen("tmp.tmp", "w");

    if (fpIn == NULL || fpOut == NULL) {
        printf("File troubles.\n");
        return(1);
    }

    char c;     // supposedly can use char not int with fget/put and EOF

    // walk through input file char by char
    // if uppercase, write lower to output file
    // if lower, write upper to output file
    while ((c = fgetc(fpIn)) != EOF)
        if (isupper(c))
            fputc(tolower(c), fpOut);
        else
            // toupper returns same char if not lowercase char 
            fputc(toupper(c), fpOut);

//    if (c == EOF)
//        fputc(c, fpOut);  // seemed to add an extra

    fclose(fpIn);
    fclose(fpOut);
    
    if (rename("tmp.tmp", filename) == 0)
        printf("Case converted.\n");
    else
        printf("Couldn't write the file.\n");

    return 0;
}

/* Results:
Challenge wanted me to pick one method of input, made it more complex by
allowing for either.
He uses a char[] for input, where I used pointer. I'm probably lucky it worked,
don't quite understand why yet.
Looks like I wrote to an uninitialized pointer and did get lucky. Fixing to avoid
in the future and learn.
He has a function to convert case, sends it file pointer and path. Seems about
the same.
He also deletes the old file first with "remove()", where my rename seemed to do the same
*/
