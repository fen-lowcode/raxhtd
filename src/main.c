/*
 * Copyright (c) 2026 Dan Stephen B. Blanco
 * 
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

 
#include "../headers/fe_exit.h"
#include "./syscall/fe_io_syscall.h"
#include "../headers/fe_string.h"
#include "../headers/fe_stdio.h"
#include "banner.h"


__attribute__((always_inline))
inline void showHelper() {
    DisplayConsoleStr("Type /h to list commands\n\n");
}

__attribute__((always_inline))
inline void inputListener() {
    char cmd[100];
    while(1) {
        DisplayConsoleStr("~ ● -- ❯❯❯ ");
        ReadConsoleStr(cmd, sizeof(cmd));
    }   
}

__attribute__((always_inline))
inline void cliLoop() {

    DisplayConsoleStr(banner);
    showHelper();
    inputListener();

}


void _start() {

    cliLoop();
    feexit(0);
}