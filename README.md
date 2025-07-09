# LD_Reload-Example

Steps:
1. `gcc -O0 -no-pie -o hello hello.c`
2. `gcc -fPIC -shared -o printf_hook.so printf_hook.c -ldl`
3. `./hello`
4. `LD_PRELOAD=$PWD/printf_hook.so ./hello`


## References
+ https://stackoverflow.com/a/426260
+ https://medium.com/@mayankshah1607/docker-security-backdooring-images-with-dockerscan-ace5ff65bd39
