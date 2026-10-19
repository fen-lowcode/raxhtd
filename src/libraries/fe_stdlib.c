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
