## C99

```c

const int max_globo_rack = 75; // tente evitar números magicos no seu código ;)

void marcar_globo_rack(int * globo , int * rack){
	int i = 0;
	for (i = 0; i < max_globo_rack; i++){
		globo[i] = 0;
		rack[i] = 1;	
	}
}

```

## C++11

```c++
#include <vector> 
// para utilizar o vector importe essa blibioteca

const int max_globo_rack = 75; // tente evitar números magicos no seu código ;)

void marcar_globo_rack(vector<int> & globo, vector<int> & rack){
	for (int  = 0; i < max_globo_rack; i++){
		globo.push_back(0);
		rack.push_back(1);	
	}
}

```

## Python2

```python
max_globo_rack = 75; # tente evitar números magicos no seu código ;)

def marcar_globo_rack(globo, rack):
	
	for i in xrange(0,max_globo_rack):
		globo.append(0)
		rack.append(1)	
```
