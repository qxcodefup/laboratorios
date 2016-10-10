#include <stdio.h>
#include <stdlib.h>

const int max_linha = 3;
const int max_coluna = 3;
const int jog_x = 1;
const int jog_o = -1;


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

int marcar_matriz(int matriz[][3], int l, int c, int marca){
	if(matriz[l][c] == 0){
		matriz[l][c] = marca;
		return 0;
	}
	return 1;
}


void iniciar_matriz(int matriz[][3]){
	for (int i = 0; i < max_linha; i++){
		for (int j = 0; j < max_coluna; j++){
			matriz[i][j] = 0;
		}
	}
}

int main(){
	int matriz[3][3];
	iniciar_matriz(matriz);
	
	int l = 0;
	int c = 0;


	while(1){
		
		mostrar_matriz(matriz);
		
		do{
			printf("jogador X: 'digite a linha e a coluna'\n");
			scanf("%d %d",&l,&c);
		}while(marcar_matriz(matriz,l-1,c-1,jog_x));
		
		if(verificar_se_ganhou(matriz,jog_x)){
			printf("jogador X ganhou\n");
			break;
		}
		
		
		mostrar_matriz(matriz);
		
		do{
			printf("jogador O: 'digite a linha e a coluna'\n");
			scanf("%d %d",&l,&c);
		}while(marcar_matriz(matriz,l-1,c-1,jog_o));
		
		if(verificar_se_ganhou(matriz,jog_o)){
			printf("jogador O ganhou\n");
			break;
		}
	}

	mostrar_matriz(matriz);


	return 0;
}