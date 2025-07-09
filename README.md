# LD_Reload-Example

Steps:
1. `gcc -O0 -no-pie -o hello hello.c`
2. `gcc -fPIC -shared -o printf_hook.so printf_hook.c -ldl`
3. `./hello`
4. `LD_PRELOAD=$PWD/printf_hook.so ./hello`
