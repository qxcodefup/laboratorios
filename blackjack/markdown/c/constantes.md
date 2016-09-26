# C

Em C normalmente definimos constantes usando
define ou const int.

Dê a preferência ao const int. Alguns casos especiais, compiladores e arquiteturas vão exigir que você precise do #define.

Se preferir, pesquise mais sobre o significado do const e como o #define, que é um comando de preprocessameto, funciona.

### Exemplo utilizando const int
```c
const int AS = 1;
const int VALETE = 11;
const int DAMA = 12;
const int REI = 13;

```

### Exemplo utilizando #define:

```c
#define AS 1
#define VALETE 11
#define DAMA 12
#define REI 13

```
