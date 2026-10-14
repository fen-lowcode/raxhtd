typedef __SIZE_TYPE__ size_t; 


void feprintf(char* string, size_t size) {
   asm volatile(
    "mov rax, 1\n\t"
    "mov rdi, 1\n\t"
    "mov rsi, %0\n\t"
    "mov rdx, %1\n\t"
    "syscall\n\t"

    : 
    : "S"(string), "d"(size)
    : "rcx", "r11", "memory"
    
    );
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
    feprintf("Hello world!\n", 13);
    feexit_failure();
}


