## C99

```c
#include <stdio.h>

const char * pegar_nome(int jogada){
  if(jogada == 1)
    return "Pedra";
  if(jogada == 2)
    return "Papel";
  return "Tesoura";
}

```

## C++11

```c++
#include <iostream>
using namespace std;

string pegar_nome(int jogada){
  if(jogada == 1)
    return "Pedra";
  if(jogada == 2)
    return "Papel";
  return "Tesoura";
}
```

## Python2

```python
def pegar_nome(jogada):
  if jogada == 1:
    return "Pedra"
  if jogada == 2:
    return "Papel"
  return "Tesoura"
```
