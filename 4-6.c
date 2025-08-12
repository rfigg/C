/* Add variables to the calculator.
26 single letter variables and one variable for most recently printed variable.
Plan:
add command for assign, '='
add case for VAR, lowercase a to z, use L for last printed value
undefined vars?

Let's see what they do.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0' // code for a number

int getop(char []);
void push(double);
double pop(void);

int main() {
    int i, type, var = 0;
    double op2, L;  // second operand for where order matters, L for last printed value
    char s[MAXOP];
    double variable[26];

    for (i = 0; i < 26; i++)
        variable[i] = 0.0;
    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("Can't divide by zero, dude.\n");
            break;
        case '=':
            pop(); // copying this, not sure what value is being discarded here
            if (var >= 'a' && var <= 'z') {
                variable[var - 'a'] = pop();
            } else {
                printf("Error: no variable name.\n");
            }
            break;
        case '\n': // on newline, pop last value and print, saving in L
            L = pop();
            printf("\t%.8g\n", L);
            break;
        default: 
            if (type >= 'a' && type <= 'z') 
                push(variable[type - 'a']);
            else if (type == 'L')
                push(L);
            else
                printf("Error! Unknown command %s\n", s);
            break;
        }
        var = type;
    }
    return 0;
}

/*
Pretty close, using L was weird.
getop changes not listed.
Guessing the line 52 pop is getting rid of the =? No, getting rid of the variable name on stack to get
to value under it, pop it, and put it in a variable.
*/
