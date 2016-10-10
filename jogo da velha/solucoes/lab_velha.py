

max_linha = 3
max_coluna = 3
jog_x = 1
jog_o = -1


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


def marcar_matriz(matriz, l, c, marca):
	if(matriz[l][c] == 0):
		matriz[l][c] = marca
		return 0
	
	return 1



def iniciar_matriz(matriz):
	for i in xrange (0,max_linha):
		linha = []
		for j in xrange (0,max_coluna):
			linha.append(0)
		matriz.append(linha)
		
	


def main():
	matriz= []
	iniciar_matriz(matriz)
	
	l = 0;
	c = 0;


	while(1):
		#system("clear");
		mostrar_matriz(matriz)

		cont1 = 1
		while(cont1):
			print("jogador X: 'digite a linha e a coluna'")
			l = input()
			c = input()
			cont1 = marcar_matriz(matriz,l-1,c-1,jog_x)
		
		if(verificar_se_ganhou(matriz,jog_x)):
			print("jogador X ganhou")
			break
		
		
		#system("clear");
		mostrar_matriz(matriz)
		
		cont2 = 1
		while(cont2):

			print("jogador O: 'digite a linha e a coluna'")
			l = input()
			c = input()
			cont2 = marcar_matriz(matriz,l-1,c-1,jog_o)
		
		if(verificar_se_ganhou(matriz,jog_o)):
			print("jogador O ganhou")
			break
		

	mostrar_matriz(matriz)


main()