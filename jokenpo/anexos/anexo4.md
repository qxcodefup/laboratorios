## C99

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

```

## C++11

```c++
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
  srand(time(NULL));
  int round = 1, pc = 0, jogador = 0, vitoriasPC = 0, vitoriasJogador = 0, continuar = 0;
  while(round <= 5){
    cout << "\n# JOKENPO #" << endl;
		cout << "Você: " << vitoriasJogador << " | PC: " << vitoriasPC << endl;
		cout << "Round: " << round << "/ 5" << endl;
		cout << "1 - Pedra\n2 - Papel\n3 - Tesoura" << endl;

    cout << ">> ";
    cin >> jogador;
    pc = jogada_pc();

		cout << jogador << " " << pc << endl;

    cout << "\nVocê jogou: " << pegar_nome(jogador) << " e o PC: " << pegar_nome(pc) << endl;

    if(checkGame(jogador, pc) == 1){
      cout << "Você ganhou!" << endl;
      vitoriasJogador++;
    }else if(checkGame(jogador, pc) == 2){
      cout << "O PC ganhou!" << endl;
      vitoriasPC++;
    }else{
      cout << "Ninguém ganhou!" << endl;
    }

    if(round == 5){
      cout << "\nPLACAR FINAL:" << endl;
			cout << "Você: " << vitoriasJogador << " | PC: " << vitoriasPC << endl;

      cout << "\nJOGAR NOVAMENTE?\n1 - SIM | 0 - NÃO" << endl;
			cout << ">> ";
			cin >> continuar;

      if(continuar == 1){
				system("clear");
        round = 0, pc = 0, jogador = 0, vitoriasPC = 0, vitoriasJogador = 0, continuar = 0;
      }
    }
    round++;
  }
  return 0;
}

```

## Python2

```python

# -*- coding: utf-8 -*-

import random
import os

if __name__ == '__main__':
    round = 1
    pc = 0
    jogador = 0
    vitoriasPC = 0
    vitoriasJogador = 0
    continuar = 0

    while(round <= 5):
        print "\n# JOKENPO #\n"
        print "Você: " + str(vitoriasJogador) + " | PC: " + str(vitoriasPC) + "\n"
        print "Round: " + str(round) + " / 5\n"
        print "1 - Pedra\n2 - Papel\n3 - Tesoura\n"

        jogador = input(">> ")
        pc = jogada_pc();

        print "\nVocê jogou: " + pegar_nome(jogador) + " e o PC: " + pegar_nome(pc);

        if checkGame(jogador, pc) == 1:
            print "Você ganhou!\n"
            vitoriasJogador += 1
        elif checkGame(jogador, pc) == 2:
            print "O PC ganhou!\n"
            vitoriasPC += 1
        else:
            print "Ninguém ganhou!\n"

        if round == 5:
            print "\nPLACAR FINAL:\n"
            print "Você: " + str(vitoriasJogador) + " | PC: " + str(vitoriasPC)
            print "\nJOGAR NOVAMENTE?\n1 - SIM | 0 - NÃO\n"

            continuar = input(">> ")

            if continuar == 1:
                os.system("clear");
                round = 0
                pc = 0
                jogador = 0
                vitoriasPC = 0
                vitoriasJogador = 0
                continuar = 0
        round += 1

```
