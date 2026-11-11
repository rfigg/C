/* Challenge - using bit fields to pack data
10 bits - 2 flags for opaque or transparent, border shown or hidden.
2 3-bit color values, fill color and border color
2-bit value for border styles
Use padding to place fill info in one byte, border info in second byte
Colors, 0 - 7: Black, Red, Green, Yellow, Blue, Magenta, Cyan, White
border style 0 - 2: solid, dotted, dashed
*/

#include <stdio.h>
#include <stdbool.h>

#define SOLID 0
#define DOTTED 1
#define DASHED 2

#define BLACK 0
#define RED 1
#define GREEN 2
#define BLUE 4
#define YELLOW (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)

const char * colors[8] = {"black", "red", "green", "yellow", "blue", "magenta", "cyan", "white"};

struct box {
    bool opaque: 1;
    unsigned int fill_color: 3;
    unsigned int : 4;
    bool show_border : 1;
    unsigned int border_color : 3;
    unsigned int border_style: 2;
    unsigned int : 2;
};

void displaySettings(const struct box *b);

int main()
{
    struct box b = { true, RED, true, GREEN, DASHED};
    printf("Original settings:\n");
    displaySettings(&b);

    b.opaque = false;
    b.fill_color = BLUE;
    b.show_border = false;
    b.border_color = YELLOW;
    b.border_style = DOTTED;

    printf("\nModified settings:\n");
    displaySettings(&b);

    return 0;
}

void displaySettings(const struct box *b)
{
    printf("Box is %s\n", b->opaque ? "opaque" : "transparent");
    printf("Fill color: %s\n", colors[b->fill_color]);
    printf("Border %s\n", b->show_border ? "is visible" : "not shown");
    printf("Border color: %s\n", colors[b->border_color]);
    switch(b->border_style) {
        case 0:
            printf("Solid border\n");
            break;
        case 1:
            printf("Dotted border\n");
            break;
        case 2:
            printf("Dashed border\n");
            break;
    }    
}

/* Results:
He uses define constatns to represent border styles and colors instaed
of all my crazy cases and if-thens. Also uses an array of the color names
that occurred to me after the face.
Structure is almost the same: he uses bool for the flags and pads at the
end instead of beginning, counter to his lecture example.
Has a display function, but passes in struct as a const pointer.
*/
