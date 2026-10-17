/*
 * Copyright (c) 2026 Dan Stephen B. Blanco
 * 
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


#include "../../headers/feexit.h"

void feexit(int status) {

    register long edi asm("edi") = status;

    asm volatile(
        "mov rax, 60\n\t"
        "syscall\n\t"

        :
        : "r"(edi)
        : "memory"
    );
}
