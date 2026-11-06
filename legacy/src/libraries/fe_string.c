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

    int i = 0;
    for(; i < sze; i++) {
         target[i] = destination[i];
    }
    target[i++] = '\0';
}

int compareStr(char string_1[], char string_2[]) {

    if(fe_strlen(string_1) != fe_strlen(string_2)){
        return 0;
    }

    for (int i = 0; i <= fe_strlen(string_1); i++){
        if(string_1[1] == string_2[i]) {
            continue;
        } else {
            return 0;
        }
    }

    return 1;
}