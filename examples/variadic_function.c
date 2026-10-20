#include <stdarg.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
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


// int atoi(char number[]) {

//     const char base = '0';
//     int buffer;

//     for(int i = 0; i < strlen(number); i++) {

//         if (i == 0) {
//             buffer = number[i] - base;
//         } else {
//             buffer = buffer * 10;
//             int temp =  number[i] - base;
//             buffer = buffer + temp;
//         }
//     }

//     return buffer;
// }

// char itoa(int number) {
    
    
// }



void fe_printf(char string[], ...) {
    va_list ap;
    va_start(ap, string);


    char buf[1];
    int int_i;
    char char_i;
    float float_i;
    double double_i;

    for(int i = 0; true ; i++) {
        char c = string[i];
        if (c == '%') {

            int n = ++i;

            if (string[n] == 'd' ) {
                int_i = va_arg(ap, int);
                snprintf(buf, sizeof(buf), "%d", n);     /* the standard way */
                string[n] = *buf;
            }

            if(string[n] == 'f') {
               float_i = va_arg(ap, double);
            }

            if(string[n] == 'D') {
                double_i = va_arg(ap, double);
            }

            if(string[n] == 'c') {
                char_i = va_arg(ap, int);
            }
        }

        if ( c =='\0') {
            return;
        }
    }
}



int main() {

    int val = add_all(5, 1, 2, 3, 4, 5);
    printf("Value: %d\n", val);

    fe_printf("%d", 1);
    return 0;
}