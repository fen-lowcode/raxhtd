#include <stdio.h>
#include <string.h>

size_t festrlen(char string[]) {

    size_t sze = 0;

    int i = 0;
    while(1) {
        if (string[i] != '\0') {
            sze++;
            i++;

        } else {

            break;
        }
    }
    
    return sze;
}


int atoi(char number[]) {

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


int main() {

    const char base = '0';
    printf("%d\n", atoi("500") + atoi("500"));
    return 0;
}