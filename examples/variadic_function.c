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

// __attribute__((warning("fe_itoa is only intended to work with pre-compiled values, not with unknown values during runtime")))
char fe_itoa(long long int number, char ln[] ,size_t lenght) {
  
    // by uisng modular operation by 10 i can get the most left number
    // and then  by dividing by 10 i can remove the most left number

    // by doing this in a loop while the whole input is greator than 10 then i can individually isolate each digits 
    // to convert them to ascii by simply summing them to number 48 (48 represents 0 in asciiii!!! )

    // but the order will be reversed if if i store each digits right away after conversing them to ascii so i have
    // to reverse the strings again

    #define NOT_SET 0

    char ctoa;
    int rvrs = NOT_SET;
    int edge;
    int remain;

    // char ln[lenght];

    while (number > 0) {
        edge = number % 10;
        remain = number / 10;
        number = remain;
    
        if(number >= 10 && rvrs == NOT_SET) {
            rvrs = edge;
        } 
        
        else if (number >= 10 && rvrs != NOT_SET ) {
            rvrs = rvrs * 10;
            rvrs = rvrs + edge;
        }

        else if (number < 10) {
            rvrs = rvrs * 10;
            rvrs = rvrs + edge;
        }
    }

    int i = 0;
    for(; rvrs > 0; i++) {
        edge = rvrs % 10;
        remain = rvrs / 10;
        rvrs = remain;
         
        ctoa = edge + 48;
        ln[i] = ctoa;
    }
    
    // ln[i] = remain + 48;
    ln[++i] = '\0';
    // printf("Output: %s\n", ln);
    // printf("size: %d\n", lenght);
}



int main() {

    // int val = add_all(5, 1, 2, 3, 4, 5);
    // printf("Value: %d\n", val); 

    // char buffer[20] = {'%', 'd'};
    // fe_printf("%d", 5);
  
    long long int x = 457012139;
    char ln[10];

    printf("Integer: %d\n", x);
    fe_itoa(x, ln , 10);
    printf("Converted by fe_itoa: %s\n", ln);
    return 0;
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
