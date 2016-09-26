#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int jogada_pc(){
	int jogada = (rand() % 3) + 1;
  return jogada;
}

const string pegar_nome(int jogada){
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
    cout << "\n# JOKENPO #" << endl;
		cout << "Você: " << vitoriasJogador << " | PC: " << vitoriasPC << endl;
		cout << "Round: " << round << "/ 5" << endl;
		cout << "1 - Pedra\n2 - Papel\n3 - Tesoura" << endl;

    cout << ">> ";
    cin >> jogador;
    pc = jogada_pc();

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
