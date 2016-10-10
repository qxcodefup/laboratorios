## C99

```c

void mostrar_matriz(int matriz[][3]){
	for (int i = 0; i < max_linha; i++){
		for (int j = 0; j < max_coluna; j++){
			if(matriz[i][j] == 0)
				printf("| - |");
			if(matriz[i][j] == jog_x)
				printf("| X |");
			if(matriz[i][j] == jog_o)
				printf("| O |");
			if((j+1) % 3 == 0)
				printf("\n");
		}
	}
}

```

## Python2

```python
def mostrar_matriz(matriz):

	for i in xrange (0,max_linha):
		string = ""
		for j in xrange (0,max_coluna):
			if(matriz[i][j] == 0):
				string += "| - |"
			if(matriz[i][j] == jog_x):
				string += "| X |"
			if(matriz[i][j] == jog_o):
				string += "| O |"
		print(string)
		
```
