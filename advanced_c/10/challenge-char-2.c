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
    char *filename;
    FILE *fpIn = NULL, *fpOut = NULL;

    // get filename from command line or user
    if (argc > 1) {
        filename = argv[1];
    } else {
        printf("File to flip case? \n");
        scanf("%s", filename);
    }

    fpIn = fopen(filename, "r");
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
//        fputc(c, fpOut);

    fclose(fpIn);
    fclose(fpOut);
    
    if (rename("tmp.tmp", filename) == 0)
        printf("Case converted.\n");
    else
        printf("Couldn't write the file.\n");

    return 0;
}

