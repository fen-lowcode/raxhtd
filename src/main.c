/*
 * Copyright (c) 2026 Dan Stephen B. Blanco
 * 
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

 
#include "../headers/exit_status.h"
#include "../headers/feio.h"

int _start() {

    char buffer[100];
    feread(1, buffer, 100);
    feprints(buffer);
    feexit_success();
}