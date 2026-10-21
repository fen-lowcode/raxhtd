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


int fe_atoi(char number[]) {

    const char base = '0';
    int buffer;

    for(int i = 0; i < strlen(number); i++) {

        if (i == 0) {
            buffer = number[i] - base;
        } else {
            buffer = buffer * 10;
            int temp =  number[i] - base;
            buffer = buffer + temp;
        }
    }

    return buffer;
}


// WIP!!!

__attribute__((warning("fe_itoa is only intended to work with pre-compiled values, not with unknown values during runtime")))
char fe_itoa(int number) {
  
    // by uisng modular operation by 10 i can get the most left number
    // and then  by dividing by 10 i can remove the most left number

    // by doing this in a loop while the whole input is greator than 10 then i can individually isolate each digits 
    // to convert them to ascii by simply summing them to number 48 (48 represents 0 in asciiii!!! )

    while(number > 10) {
        int edge = number % 10;
        int remain = number / 10;


        number = remain;

        printf("edge: %d\n", edge);
        printf("remain: %d\n", remain);
    }
}


// WIP!!

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
                // snprintf(buf, sizeof(buf), "%d", n);     /* the standard way */
                printf("%d", int_i);
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

    // int val = add_all(5, 1, 2, 3, 4, 5);
    // printf("Value: %d\n", val); 

    // char buffer[20] = {'%', 'd'};
    // fe_printf("%d", 5);

  
    fe_itoa(1231);

    return 0;
}