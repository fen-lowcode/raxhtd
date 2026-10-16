/*
 * Copyright (c) 2026 Dan Stephen B. Blanco
 * 
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


#include "../../headers/feio.h"
#include "../../headers/festr.h"

// refator this to follow write convetion  like feread()
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

// Protoype!!

int feread(int fd, char* buf, size_t count) {

    long int sze = 0;

    asm volatile(
        "mov rax, 0\n\t"
        "syscall\n\t"
    
        "mov %3, rax\n\t"
    
        : "+D"(fd), "+S"(buf), "+d"(count), "=a"(sze) 
        :
        : "rcx", "r11", "memory"
    );
}