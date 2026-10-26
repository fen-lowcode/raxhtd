#!/bin/bash

printf "Select a C source file (without .c) to convert into an Object: "
read fileObj

c_="${fileObj}.c"
o_="${fileObj}.o"

gcc $c_ -c -o ../../lib/$o_ -nostdlib -ffreestanding -masm=intel -O3 -flto