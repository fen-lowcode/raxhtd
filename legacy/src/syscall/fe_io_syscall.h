/*
 * Copyright (c) 2026 Full Name
 * 
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


#pragma once
#include <stddef.h>

static inline int fewrite(int fd, const char buf[], size_t count);
static inline int feread(int fd, char* buf, size_t count);

 

// My own System call wrapper for write
__attribute__((always_inline)) static inline 
int fewrite(int fd, const char buf[], size_t count) {


    long int sze = 0;

    register long rdi __asm__("rdi") = fd;
    register long rsi __asm__("rsi") = (long)buf;
    register long rdx __asm__("rdx") = count;

    __asm__ __volatile__ (
        "mov rax, 1\n\t"
        "syscall\n\t"

        "mov %3, rax\n\t"

        : 
        : "r"(rdi), "r"(rsi), "r"(rdx), "a"(sze)
        : "rcx", "r11", "memory"
    );

    return sze;

}

// My own System call wrapper for read
__attribute__((always_inline)) static inline 
int feread(int fd, char* buf, size_t count) {

    long int sze = 0;

    register long rdi __asm__("rdi") = fd;
    register long rsi __asm__("rsi") = (long)buf;
    register long rdx __asm__("rdx") = count;

    __asm__ __volatile__(
        "mov rax, 0\n\t"
        "syscall\n\t"
    
        "mov %3, rax\n\t"
    
        : "+r"(rdi), "+r"(rsi), "+r"(rdx), "=a"(sze) 
        :
        : "rcx", "r11", "memory"
    );

    return sze;
}