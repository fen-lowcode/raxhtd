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




void _start() {

    // char cpy[1024];
    // char buffer[] = "Hello Worlddd\n";

    // fe_strcpy(buffer, cpy, fe_strlen(buffer));
    // DisplayConsoleStr(cpy);

    char *cmd;

    DisplayConsoleStr(banner);
    DisplayConsoleStr(":> ");
    feread(0, cmd, 1);
    
    feexit(0);
}