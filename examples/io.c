/*
 * Copyright (c) 2026 Dan Stephen B. Blanco
 * 
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


typedef __SIZE_TYPE__ size_t; 

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


unsigned char string[255];
char* fereads() {

    size_t sze = 255;

    asm volatile(
        "mov rax, 0\n\t"
        "mov rdi, 0\n\t"
        "mov rsi, %0\n\t"
        "mov rdx, %1\n\t"
        "syscall\n\t"

        :
        : "S"(string), "d"(sze)
        : "rcx", "r11", "memory"
    );

    return string;
}


void feexit_success() {
    asm volatile(
        "mov rax, 60\n\t"
        "mov rdi, 0\n\t"
        "syscall"

        :
        : 
        : "memory"
    );
}


void feexit_failure() {


    asm volatile(
        "mov rax, 60\n\t"
        "mov rdi, 1\n\t"
        "syscall"
        ""
        :
        :
        : "memory"
    );
}

void _start() {

    // char* string = fereads();
    // feprintf(string);

    char buf[100];
    read(1, &buf, 100);
    feexit_success();
}


