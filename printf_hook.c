#define _GNU_SOURCE
#include <stdio.h>
#include <stdarg.h>
#include <dlfcn.h>

// Constructor to confirm that the hook loads
__attribute__((constructor))
void init() {
    fprintf(stderr, "[+] printf_hook.so loaded\n");
}

int printf(const char *format, ...) {
    static int (*real_printf)(const char *, ...) = NULL;
    if (!real_printf)
        real_printf = dlsym(RTLD_NEXT, "printf");

    real_printf("[HOOKED] printf was called!\n");

    va_list args;
    va_start(args, format);
    int ret = vfprintf(stdout, format, args);
    va_end(args);
    return ret;
}
