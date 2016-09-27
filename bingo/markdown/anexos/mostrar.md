## C99

```c

const int max_globo_rack = 75; // tente evitar números magicos no seu código ;)

void mostrar(int * vetor){
	int i = 0;
	for (i = 0; i < max_globo_rack; i++){
		if(vetor[i] == 0)
			printf("%.2d ",i+1);
		else
			printf("-- ");
		if((i+1) % 15 == 0)
			printf("\n");
	}
}

```

## C++11

```c++
#include <vector> 
// para utilizar o vector importe essa blibioteca

const int max_globo_rack = 75; // tente evitar números magicos no seu código ;)


void mostrar(vector<int> vetor){
	int i = 0;
	for (i = 0; i < max_globo_rack; i++){
		if(vetor[i] == 0){
			cout << i+1 << " ";
		}
		else
			cout <<"-- ";
		if((i+1) % 15 == 0)
			cout << "\n";
	}
}

```

## Python2

```python
max_globo_rack = 75; # tente evitar números magicos no seu código ;)

def mostrar(vetor):
	string = ""
	for i in xrange(0,max_globo_rack):
		if(vetor[i] == 0):
			string += str(i+1) + " "
		else:
			string = string + "-- "
		if((i+1) % 15 == 0):
			print(string)
			string = ""
```
