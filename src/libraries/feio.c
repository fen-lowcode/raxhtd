/*
 * Copyright (c) 2026 Dan Stephen B. Blanco
 * 
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


#include "../../headers/feio.h"
#include "../../headers/festr.h"

void feprints(char string[]) {

   size_t sze = festrlen(string);

   asm volatile(
    "mov rax, 1\n\t"
    "mov rdi, 1\n\t"
    "mov rsi, %0\n\t"
    "mov rdx, %1\n\t"
    "syscall\n\t"

    : 
    : "S"(string), "d"(sze)
    : "rcx", "r11", "memory"
    
    );
}