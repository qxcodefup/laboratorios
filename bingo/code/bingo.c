#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int max_globo_rack = 75;

struct{
	int globo[75];
	int rack[75];
	int sorteado;
}typedef Ambiente;

void sortear(Ambiente * ambiente){
	int num_sorteado = rand()%max_globo_rack;
	while(1){
		if(ambiente->rack[num_sorteado] == 1)
			break;
		num_sorteado = rand()%max_globo_rack;
	}
	ambiente->rack[num_sorteado] = 0;
	ambiente->globo[num_sorteado] = 1;
	ambiente->sorteado = num_sorteado+1;
}

void show(int * vetor){
	int i = 0;
	for (i = 0; i < max_globo_rack; i++){
		if(vetor[i] == 0)
			printf("%.2d ",i+1);
		else
			printf("── ");
		if((i+1) % 15 == 0)
			printf("\n");
	}
}

void marcar_globo_rack(Ambiente * ambiente){
	int i = 0;
	for (i = 0; i < max_globo_rack; i++){
		ambiente->globo[i] = 0;
		ambiente->rack[i] = 1;	
	}
}

void show_globo_rack(Ambiente  ambiente){
	printf("└──Globo:\n");
	show(ambiente.globo);
	printf("\n└──Rack:\n");
	show(ambiente.rack);
	printf("\nNumero sorteado: %d\n", ambiente.sorteado);
}

int opcao(Ambiente * ambiente){
	int opc = 0;
	printf("Escolha 1 para pedir bola e 0 para sair:\n");
	scanf("%d",&opc);
	if(opc == 1){
		sortear(ambiente);
		return 1;
	}
	return 0;
}

void bingo(Ambiente * ambiente){
	int qt_vezes = 0;
	while(qt_vezes < max_globo_rack){
		system("clear");
		show_globo_rack(*ambiente);
		if(opcao(ambiente) == 0)
			break;
		qt_vezes++;
	}
	system("clear");
	show_globo_rack(*ambiente);
	printf("\nObrigado e volte sempre.\n\n");
}

int main(){
	srand(time(NULL));
	
	Ambiente ambiente;
	ambiente.sorteado = 0;
	marcar_globo_rack(&ambiente);
	bingo(&ambiente);

	return 0;
}