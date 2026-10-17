/*
 * Copyright (c) 2026 Dan Stephen B. Blanco
 * 
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


#include "../../headers/festr.h"

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
