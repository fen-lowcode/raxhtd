/*
 * Copyright (c) 2026 Dan Stephen B. Blanco
 * 
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

 
#include "../headers/feexit.h"
#include "../headers/feio.h"
#include "../headers/festr.h"

void _start() {

    char buffer[100];

    char * inp_msg = "Type any message: ";
    fewrite(0, inp_msg, festrlen(inp_msg));

    [[maybe_unused]]int x = feread(1, buffer, 100);

    char * out_msg = "Raxhtd prints back: ";
    fewrite(0, out_msg, festrlen(out_msg));

    fewrite(0, buffer, festrlen(buffer));
    feexit(0);
}