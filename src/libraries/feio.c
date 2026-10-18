/*
 * Copyright (c) 2026 Dan Stephen B. Blanco
 * 
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


#include "../../headers/feio.h"
#include "../../headers/festr.h"


int fewrite(int fd, const char buf[], size_t count) {


    long int sze = 0;

    register long rdi asm("rdi") = fd;
    register long rsi asm("rsi") = (long)buf;
    register long rdx asm("rdx") = count;

    asm volatile(
        "mov rax, 1\n\t"
        "syscall\n\t"

        "mov %3, rax\n\t"

        : 
        : "r"(rdi), "r"(rsi), "r"(rdx), "a"(sze)
        : "rcx", "r11", "memory"
    );

    return sze;

}

int feread(int fd, char* buf, size_t count) {

    long int sze = 0;

    register long rdi asm("rdi") = fd;
    register long rsi asm("rsi") = (long)buf;
    register long rdx asm("rdx") = count;

    asm volatile(
        "mov rax, 0\n\t"
        "syscall\n\t"
    
        "mov %3, rax\n\t"
    
        : "+r"(rdi), "+r"(rsi), "+r"(rdx), "=a"(sze) 
        :
        : "rcx", "r11", "memory"
    );

    return sze;
}