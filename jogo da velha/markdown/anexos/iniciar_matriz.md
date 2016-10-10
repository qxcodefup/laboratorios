## C99

```c

void iniciar_matriz(int matriz[][3]){
	for (int i = 0; i < max_linha; i++){
		for (int j = 0; j < max_coluna; j++){
			matriz[i][j] = 0;
		}
	}
}

```

## Python2

```python
def iniciar_matriz(matriz):
	for i in xrange (0,max_linha):
		linha = []
		for j in xrange (0,max_coluna):
			linha.append(0)
		matriz.append(linha)
		
```
