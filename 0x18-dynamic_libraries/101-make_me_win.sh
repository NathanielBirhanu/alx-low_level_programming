#!/bin/bash

# Create a shared library to intercept the `printf` function
cat <<EOF > win.c
#include <stdio.h>

int printf(const char *format, ...) {
    return 0;  // Return 0 to suppress the output of printf
}
EOF

# Compile the shared library
gcc -shared -o win.so win.c

# Set LD_PRELOAD to load the shared library when executing `gm`
export LD_PRELOAD=./win.so

# Remove the shell script itself
rm \$0
