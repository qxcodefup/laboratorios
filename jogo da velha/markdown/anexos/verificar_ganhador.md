## C99

```c

int verificar_se_ganhou(int matriz[][3], int j){
	if(matriz[0][0] == j && matriz[0][1] == j && matriz[0][2] == j)
		return 1;
	if(matriz[1][0] == j && matriz[1][1] == j && matriz[1][2] == j)
		return 1;
	if(matriz[2][0] == j && matriz[2][1] == j && matriz[2][2] == j)
		return 1;
	if(matriz[0][0] == j && matriz[1][0] == j && matriz[2][0] == j)
		return 1;
	if(matriz[0][1] == j && matriz[1][1] == j && matriz[2][1] == j)
		return 1;
	if(matriz[0][2] == j && matriz[1][2] == j && matriz[2][2] == j)
		return 1;
	if(matriz[0][0] == j && matriz[1][1] == j && matriz[2][2] == j)
		return 1;
	if(matriz[0][2] == j && matriz[1][1] == j && matriz[2][0] == j)
		return 1;
	return 0;
}

```

## Python2

```python
def verificar_se_ganhou(matriz, j):
	if(matriz[0][0] == j and matriz[0][1] == j and matriz[0][2] == j):
		return 1
	if(matriz[1][0] == j and matriz[1][1] == j and matriz[1][2] == j):
		return 1
	if(matriz[2][0] == j and matriz[2][1] == j and matriz[2][2] == j):
		return 1
	if(matriz[0][0] == j and matriz[1][0] == j and matriz[2][0] == j):
		return 1
	if(matriz[0][1] == j and matriz[1][1] == j and matriz[2][1] == j):
		return 1
	if(matriz[0][2] == j and matriz[1][2] == j and matriz[2][2] == j):
		return 1
	if(matriz[0][0] == j and matriz[1][1] == j and matriz[2][2] == j):
		return 1
	if(matriz[0][2] == j and matriz[1][1] == j and matriz[2][0] == j):
		return 1
	return 0
		
```
