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