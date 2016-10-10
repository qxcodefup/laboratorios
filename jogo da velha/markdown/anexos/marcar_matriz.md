## C99

```c

int marcar_matriz(int matriz[][3], int l, int c, int marca){
	if(matriz[l][c] == 0){
		matriz[l][c] = marca;
		return 0;
	}
	return 1;
}
```

## Python2

```python
def marcar_matriz(matriz, l, c, marca):
	if(matriz[l][c] == 0):
		matriz[l][c] = marca
		return 0
	
	return 1

```
