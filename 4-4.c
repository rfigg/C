/* Add commands to 1. print top element of stack without popping,
2. dulpicate it 3. swap top 2 elements 4. Clear the stack
*/

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

/* Print top element of stack without popping it */
void printtop(void)
{
    if (sp > 0)
        printf("Top element of the stack is: %g\n", val[sp]);
    else
        printf("Stack is empty, nothing to see.\n");
}

/* Duplicate the stack */
void dupestack(double dest[]) // not sure you can do this
{
    int i;
    
    for (i = 0; i < sp; i++)
        dest[i] = val[i];
}

/* Swap top two elements of stack */
void swaptop2(void)
{
    double s, t;

    if (sp > 1) {   // at least two elements
        t = pop();
        s = pop();
        push(t);
        push(s);
    } else
        printf("Need at least 2 in stack to swap.\n");
}

/* Clear the stack */
void clearstack(void) {
    sp = 0;
}

