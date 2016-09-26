## C99

```c
#include <time.h>
// biblioteca para poder inicializar o aletório

const int max_globo_rack = 75; // tente evitar números magicos no seu código ;)

void sortear(int * globo, int * rack, int * sorteado){
	int num_sorteado = rand()%max_globo_rack;
	while(1){
		if(rack[num_sorteado] == 1)
			break;
		num_sorteado = rand()%max_globo_rack;
	}
	rack[num_sorteado] = 0;
	globo[num_sorteado] = 1;
	*sorteado = num_sorteado+1;
}

```

## C++11

```c++
#include <vector> 
// para utilizar o vector importe essa blibioteca

#include <ctime>
// biblioteca para poder inicializar o aletório

const int max_globo_rack = 75; // tente evitar números magicos no seu código ;)

void sortear(vector<int> & globo, vector<int> & rack, int & sorteado){
	int num_sorteado = rand()%max_globo_rack;
	while(1){
		if(rack[num_sorteado] == 1)
			break;
		num_sorteado = rand()%max_globo_rack;
	}
	rack[num_sorteado] = 0;
	globo[num_sorteado] = 1;
	sorteado = num_sorteado+1;
}

```

## Python2

```python
import random # para importar a blibioteca para gerar os números aleatório

max_globo_rack = 75; # tente evitar números magicos no seu código ;)

def sortear(globo, rack, sorteado):
	num_sorteado = randint(0,max_globo_rack-1)
	while(1):
		if(rack[num_sorteado] == 1):
			break
		num_sorteado = randint(0,max_globo_rack-1)
	
	rack[num_sorteado] = 0
	globo[num_sorteado] = 1
	sorteado = num_sorteado+1
```
