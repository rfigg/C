// Share variable between files
// This calls display to show the iterator
// Started with iteration in display, changed to iterate here

int lp_counter = 0;
extern void display();

int main() {
    for (lp_counter = 0; lp_counter < 5; ) {
        lp_counter++;
        display();
    }

    return 0;
}

/*
Result
They didn't use extern here for function, must be the default.
-tested and it's true
They made the loop simple, incrementing in for loop, and display just prints the
value + 1, not incrementing there or where I did here.
Also should probably get used to using shorter var names, this ain't java or js
*/

