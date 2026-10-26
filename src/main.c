/*
 * Copyright (c) 2026 Dan Stephen B. Blanco
 * 
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

 
#include "../headers/fe_exit.h"
#include "./syscall/fe_io_syscall.h"
#include "../headers/fe_string.h"




void _start() {

    char buffer[] = "Hello World";
    char cpy[100];

    fe_strcpy(buffer, cpy, festrlen(buffer));
    fewrite(1, cpy, 11);
    
    feexit(0);
}