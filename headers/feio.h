/*
 * Copyright (c) 2026 Full Name
 * 
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */


#pragma once
#define size_t __SIZE_TYPE__

int fewrite(int fd, const char buf[], size_t count);
int feread(int fd, char* buf, size_t count);