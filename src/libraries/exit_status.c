/*
 * Copyright (c) 2026 Dan Stephen B. Blanco
 * 
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


#include "exit_status.h"

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