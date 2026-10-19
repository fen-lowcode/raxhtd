/*
 * Copyright (c) 2026 Full Name
 * 
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


// #pragma once
// #define size_t __SIZE_TYPE__


#include "../../headers/fe_stdio.h"
#include <stdarg.h>

void fe_printf(const char string[], ...) {
    va_list ap;
    va_start(ap, string);

    for(char* i; i != '\0'; i++) {
        if (string[i] == 'a') {
            
        }
    }
}