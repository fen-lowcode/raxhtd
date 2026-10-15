#include "../lib/exit_status.h"
#include "../lib/festr.h"

int _start() {

    feprintf("Hello World!\n");
    feexit_success();
}