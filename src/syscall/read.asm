/*
 * Copyright (c) 2026 Dan Stephen B. Blanco
 * 
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


section .text
    global read;

read:
    ; function prologue
    push rbp
    mov rbp, rsp
    sub rsp, 16
    
    mov r9, rdi
    mov r8, rsi


    ; function epilogue 
    mov rsp, rbp    
    pop rbp         
    ret             

