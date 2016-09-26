## C99

```c

#include <stdlib.h> //rand e srand
#include <time.h> //funcao time

int pedir_carta(){
    int carta = (rand() % 13) + 1;
    return carta
}

int main(){
    srand(time(NULL));//iniciar a aleatoriedade
}

```

## C++11

```c++

#include <cstdlib> //rand e srand
#include <ctime> //funcao time

int pedir_carta(){
    int carta = (rand() % 13) + 1;
    return carta
}

int main(){
    srand(time(NULL));//iniciar a aleatoriedade
}

```

## Python2

```python

import random

def pedir_carta():
    carta = int(random.uniform(1, 13))
    return carta

def main:
    carta = pedir_carta()
```
