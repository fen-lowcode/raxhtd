#include "festr.h"

size_t festrlen(char string[]) {

    size_t sze = 0;

    int i = 0;
    while(1) {
        if (string[i] != '\0') {
            sze++;
            i++;

        } else {

            sze++;
            break;
        }
    }
    
    return sze;
}

void feprintf(char string[]) {

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