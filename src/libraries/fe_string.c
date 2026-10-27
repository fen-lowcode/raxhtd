/*
 * Copyright (c) 2026 Dan Stephen B. Blanco
 * 
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


#include <stddef.h>


size_t fe_strlen(char string[]) {

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



void fe_strcpy(char destination[], char target[], size_t sze) {

    for(int i = 0; i < sze; i++) {
        char c = destination[i];
        if(c != '\0') {
            target[i] = c;
        } else {
            target[i] = '0';
            return;
        }
    }
}