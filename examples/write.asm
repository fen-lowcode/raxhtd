section .data
    message db "Hello World!",0x0a
    count dd 13

section .text
    global _start

_start:
    mov rax, 1
    mov rdi, 1
    mov rsi, message
    mov rdx, [count]
    syscall

    mov rax, 60
    mov rdi, 0
    syscall