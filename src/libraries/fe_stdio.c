/*
 * Copyright (c) 2026 Full Name
 * 
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


// #pragma once
// #define size_t __SIZE_TYPE__


#include "../../headers/fe_stdio.h"
#include "../../headers/fe_string.h"
#include "../syscall/fe_io_syscall.h"

// #include <stdarg.h>

void DisplayConsoleStr(char string[]) {
    fewrite(1, string, fe_strlen(string));
}