/*
 * Copyright (c) 2026 Full Name
 * 
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


// #pragma once
// #define size_t __SIZE_TYPE__


#include "../../headers/fe_string.h"

int atoi(char number[]) {

    const char base = '0';
    int buffer;

    for(int i = 0; i < festrlen(number); i++) {

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


// __attribute__((warning("fe_itoa is only intended to work with compile-time values, nand not for runtime value")))
void fe_itoa(long long int number, char ln[] ,size_t lenght) {
  
    // by uisng modular operation by 10 i can get the most left number
    // and then  by dividing by 10 i can remove the most left number

    // by doing this in a loop while the whole input is greator than 10 then i can individually isolate each digits 
    // to convert them to ascii by simply summing them to number 48 (48 represents 0 in asciiii!!! )

    // but the order will be reversed if if i store each digits right away after conversing them to ascii so i have
    // to reverse the strings again
    char ctoa;
    int edge;
    int remain;
    lenght--;

    int i = 0;
    for(; number > 0; i++) {
        edge = number % 10;
        remain = number / 10;
        number = remain;

        ctoa = edge + 48;
        ln[lenght] = ctoa;
        lenght = lenght - 1;
    }
    
   
    ln[++i] = '\0';
}

