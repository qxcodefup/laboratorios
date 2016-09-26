#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int jogada_pc(){
	int jogada = (rand() % 3) + 1;
  return jogada;
}

const char * pegar_nome(int jogada){
  if(jogada == 1)
    return "Pedra";
  if(jogada == 2)
    return "Papel";
  return "Tesoura";
}

int checkGame(int jogador, int pc) {
	if(jogador == 1 && pc == 2)
		return 2;
	if(jogador == 1 && pc == 3)
		return 1;

	if(jogador == 2 && pc == 1)
		return 1;
	if(jogador == 2 && pc == 3)
		return 2;

	if(jogador == 3 && pc == 1)
		return 2;
	if(jogador == 3 && pc == 2)
		return 1;

  return 0;
}

int main() {
  srand(time(NULL));
  int round = 1, pc = 0, jogador = 0, vitoriasPC = 0, vitoriasJogador = 0, continuar = 0;
  while(round <= 5){
    printf("\n# JOKENPO #\n");
		printf("Você: %d | PC: %d\n", vitoriasJogador, vitoriasPC);
		printf("Round: %d / 5\n", round);
		printf("1 - Pedra\n2 - Papel\n3 - Tesoura\n");

    printf(">> ");
    scanf("%d", &jogador);
    pc = jogada_pc();

    printf("\nVocê jogou: %s e o PC: %s\n", pegar_nome(jogador), pegar_nome(pc));

    if(checkGame(jogador, pc) == 1){
      printf("Você ganhou!\n");
      vitoriasJogador++;
    }else if(checkGame(jogador, pc) == 2){
      printf("O PC ganhou!\n");
      vitoriasPC++;
    }else{
      printf("Ninguém ganhou!\n");
    }

    if(round == 5){
      printf("\nPLACAR FINAL:\n");
			printf("Você: %d | PC: %d\n", vitoriasJogador, vitoriasPC);
			printf("\nJOGAR NOVAMENTE?\n1 - SIM | 0 - NÃO\n");
			printf(">> ");
			scanf("%d", &continuar);
      if(continuar == 1){
				system("clear");
        round = 0, pc = 0, jogador = 0, vitoriasPC = 0, vitoriasJogador = 0, continuar = 0;
      }
    }
    round++;
  }
	return 0;
}
