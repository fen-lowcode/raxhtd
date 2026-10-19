#include <stdarg.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int add_all(int count, ...) {

// Damn this is confusing
    int res;

    // this is where adrress to find the argument in elipsis ... is located
    va_list ap;

    // sets up ap; reads no argument yet
    va_start(ap, count);

    for (int i = 0; i != count; i++) {

        // every call to va_arg moves it to the next argument in the ellipsis its like the pointer
        // second argument ofva_arg tells the type of data in it
        res = res + va_arg(ap, int);
    };

    // cleans up ap
    va_end(ap);
    return res;
};



void fe_printf(const char string[], ...) {
    va_list ap;
    va_start(ap, string);

    //char plchldrs[] = {'c', 's', 'd', 'i', 'u', '\0'};

    for(int i = 0; true ; i++) {
        char c = string[i];
        if (c == '%') {
            if (string[i++] == 'd') {
                printf("Integer placeholder detected");
            }
        }

        if ( c =='0') {
            return;
        }
    }
}



int main() {

    int val = add_all(5, 1, 2, 3, 4, 5);

    printf("Value: %d\n", val);
    fe_printf("Hello");
    return 0;
}