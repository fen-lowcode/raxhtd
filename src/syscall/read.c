/*
 * Copyright (c) 2026 Dan Stephen B. Blanco
 * 
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

 
#define size_t __SIZE_TYPE__

int read(int fd, char* buf, size_t count) {

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