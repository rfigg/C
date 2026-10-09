/* Add commands to 1. print top element of stack without popping,
2. dulpicate it 3. swap top 2 elements 4. Clear the stack
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);
void clear(void);

int sp = 0;

int main()
{
    int type;
    double op1, op2;
    char s[MAXOP];

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
            if (op2 == 0.0)
                printf("No can do, divide by zero.\n");
            else
                push(pop() / op2);
            break;
        case '?':       // They use this to print top spot without popping
            op2 = pop();
            printf("\t%.8g\n", op2);
            push(op2);
            break;
        case 'c':
            clear();
            break;
        case 'd':
            op1 = pop();
            push(op1);
            push(op1);
            break;
        case 's':
            op2 = pop();
            op1 = pop();
            push(op2);
            push(op1);
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("Unknown command: %s\n", s);
            break;
        }
    }
    return 0;
}

void clear(void)
{
    sp = 0;
}

/* Misunderstood problem. They wanted commands added to the polish calc
like operations, inline in that switch statement. Only use push, pop, in main
so not accessing sp or val. Their clear stack is like mine. Logic of swap is the same.
Misunderstood duplicate, they want to dupe top stack item and push, not copy whole stack. 
print top uses ? command and just pops, prints, pushes.
*/

