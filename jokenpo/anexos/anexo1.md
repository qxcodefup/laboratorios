## C99

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int jogada_pc(){
	int jogada = (rand() % 3) + 1;
  return jogada;
}

int main(){
  srand(time(NULL));
}

```

## C++11

```c++

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int jogada_pc(){
  int jogada = (rand() % 3) + 1;
  return jogada;
}

int main(){
  srand(time(NULL));
}

```

## Python2

```python

import random

def jogada_pc():
    jogada = int(random.uniform(1, 4))
	#Você tem que colocar o intervalo de 1 à 4 pois
	#em python o random irá até o último valor -1, nesse caso o 3.
    return jogada

def main:
    pc = sortear_jogada()
```
