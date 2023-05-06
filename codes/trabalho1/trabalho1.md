# Resumo

Compilando shared object usando o gcc:

```sh
    gcc -c -fPIC [arquivo.c] -o [arquivo.o]
    gcc [arquivo.o] -shared -o [arquivo.so]
```
