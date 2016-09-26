#include <stdio.h>
#include <string.h>
#include <time.h>//time
#include <stdlib.h>//rand e srand


const int AS = 1;
const int VALETE = 11;
const int DAMA = 12;
const int REI = 13;

#define MAX 22
typedef struct{
    char * nome;
    int mao[MAX];
    int qtd;//quantas cartas tem na mao
    int total;
}Jogador;

//----------------- Funcoes relacionadas à carta
char * nomes_cartas[] = {"", "As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

const char * carta_pegar_nome(int carta){
    return nomes_cartas[carta];
}

int carta_pegar_valor(int carta){
    if(carta == AS)
        return 11;
    if(carta >=2 && carta <=10)
        return carta;
    return 10;
}
//----------------- Funcoes relacionadas ao Jogador
//imprime o jogador, o total e as cartas
void jogador_recalcular_mao(Jogador * jog){
    int total = 0;
    int n_as = 0;
	for(int i = 0; i < jog->qtd; i++){
		int carta = jog->mao[i];
        total += carta_pegar_valor(carta);
        if(carta == AS)
            n_as++;
    }
    while(total > 21 && n_as > 0){
        total -= 10;
        n_as--;
    }
    //atualizando valor total
    jog->total = total;
}

void jogador_imprimir(Jogador * jog){
    printf("Total %s: %d[", jog->nome, jog->total);
    for(int i = 0; i < jog->qtd; i++)
		printf("%s ", carta_pegar_nome(jog->mao[i]));
    printf("]\n");
}

//retorna uma carta como um número entre 1 e 13 e diz para quem vai a carta
void jogador_pedir_carta(Jogador * jog){
    int carta = (rand() % 13) + 1;
    jog->mao[jog->qtd] = carta;
    jog->qtd += 1;
    jogador_recalcular_mao(jog);
    printf("|---Foi puxada a carta %s", carta_pegar_nome(carta));
    printf(" para %s \n", jog->nome);
}

void logica_jogar_humano(Jogador * jogador){
	int opcao = 0;
	while(jogador->total <= 21){
        jogador_imprimir(jogador);
        printf("Menu: 1 - Pedir Carta, 2 - Parar:\n>>");
        scanf("%d", &opcao);
        srand(time(NULL));
        if(opcao == 1)
            jogador_pedir_carta(jogador);
        else
            return;
    }
}

void esperar(){
	printf("Digite 1 para continuar:\n>>");
	int valor;
	scanf("%d", &valor);
}

void logica_jogar_maquina(Jogador * jogador, Jogador * mesa){
	while(mesa->total < jogador->total && mesa->total <= 21){
		jogador_pedir_carta(mesa);
		jogador_imprimir(mesa);
		esperar();
		srand(time(NULL));
	}
}

//##################### Funcao Principal ###################################

int main() {
	puts("O momento do enter influencia na aleatoriedade da carta");
    srand(time(NULL)); //inicializando a aleatoriedade

    Jogador mesa    = {"Dealer", {}, 0}; //inicializacao na mesma linha
    Jogador jogador = {"Player", {}, 0};

	puts("Inicio do jogo");
	jogador_pedir_carta(&mesa);
	jogador_pedir_carta(&jogador);
	jogador_pedir_carta(&jogador);
    
    jogador_imprimir(&mesa);

	logica_jogar_humano(&jogador);
    if(jogador.total > 21){
        puts("Mesa Ganhou");
        return 0;
    }
    logica_jogar_maquina(&jogador, &mesa);
	if(mesa.total > 21)
		puts("Jogador Ganhou");
	else
		puts("Mesa Ganhou");
	
    return 0;
}



