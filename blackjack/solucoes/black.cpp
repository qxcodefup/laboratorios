#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>


using namespace std;

const int AS = 1;
const int VALETE = 11;
const int DAMA = 12;
const int REI = 13;

struct Jogador{
    string nome;
    vector<int> mao;
    int total;
};

//----------------- Funcoes relacionadas à carta
vector<string> nomes_cartas {"", "As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

string carta_pegar_nome(int carta){
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

void jogador_recalcular_mao(Jogador &jog){
    int total = 0;
    int n_as = 0;
    for(int carta : jog.mao){
        total += carta_pegar_valor(carta);
        if(carta == AS)
            n_as++;
    }
    while(total > 21 && n_as > 0){
        total -= 10;
        n_as--;
    }
    //atualizando valor total
    jog.total = total;
}

void jogador_imprimir(Jogador &jog){
    cout << "Total " << jog.nome << ": " << jog.total << "[ ";
    for(auto &carta : jog.mao)
        cout << carta_pegar_nome(carta) << " ";
    cout << "]" << endl;
}

//retorna uma carta como um número entre 1 e 13 e diz para quem vai a carta
void jogador_pedir_carta(Jogador &jog){
    int carta = (rand() % 13) + 1;
    jog.mao.push_back(carta);
    jogador_recalcular_mao(jog);
    cout << "|---Foi puxada a carta " << carta_pegar_nome(carta);
    cout << " para " << jog.nome << endl;
    
}

void logica_jogar_humano(Jogador &jogador){
	int opcao = 0;
	while(jogador.total <= 21){
        jogador_imprimir(jogador);
        cout << "Menu: 1 - Pedir Carta, 2 - Parar:" << endl << ">>";
        cin >> opcao;
        srand(time(NULL));
        if(opcao == 1)
            jogador_pedir_carta(jogador);
        else
            return;
    }
}

void esperar(){
	cout << "Digite 1 para continuar:\n>>";
	int valor;
	cin >> valor;
}

void logica_jogar_maquina(Jogador &jogador, Jogador &mesa){
	while(mesa.total < jogador.total && mesa.total <= 21){
		jogador_pedir_carta(mesa);
		jogador_imprimir(mesa);
		esperar();
		srand(time(NULL));
	}
}

//##################### Funcao Principal ###################################

int main() {
	cout << "O momento do enter influencia na aleatoriedade da carta\n";
    srand(time(NULL)); //inicializando a aleatoriedade

    Jogador mesa    = {"Dealer", {}, 0}; //inicializacao na mesma linha
    Jogador jogador = {"Player", {}, 0};

	cout << "Inicio do jogo" << endl;
	jogador_pedir_carta(mesa);
	jogador_pedir_carta(jogador);
	jogador_pedir_carta(jogador);
    
    jogador_imprimir(mesa);

	logica_jogar_humano(jogador);
    if(jogador.total > 21){
        cout << "Mesa Ganhou" << endl;
        return 0;
    }
    logica_jogar_maquina(jogador, mesa);
	if(mesa.total > 21)
		cout << "Jogador Ganhou" << endl;
	else
		cout << "Mesa Ganhou" << endl;
	
    return 0;
}

