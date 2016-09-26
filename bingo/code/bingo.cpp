#include <iostream>
#include <cstdlib>
#include <vector>
#include <time.h>


using namespace std;

const int max_globo_rack = 75;

struct Ambiente{
	vector<int> globo;
	vector<int> rack;
	int sorteado;

	Ambiente(){
		sorteado = 0;
	}
};

void sortear(Ambiente & ambiente){
	int num_sorteado = rand()%max_globo_rack;
	while(1){
		if(ambiente.rack[num_sorteado] == 1)
			break;
		num_sorteado = rand()%max_globo_rack;
	}
	ambiente.rack[num_sorteado] = 0;
	ambiente.globo[num_sorteado] = 1;
	ambiente.sorteado = num_sorteado+1;
}

void show(vector<int> vetor){
	int i = 0;
	for (i = 0; i < max_globo_rack; i++){
		if(vetor[i] == 0){
			cout.precision(2);
			cout << i+1 << " ";
		}
		else
			cout <<"── ";
		if((i+1) % 15 == 0)
			cout << "\n";
	}
}

void marcar_globo_rack(Ambiente & ambiente){
	int i = 0;
	for (i = 0; i < max_globo_rack; i++){
		ambiente.globo.push_back(0);
		ambiente.rack.push_back(1);	
	}
}

void show_globo_rack(Ambiente  ambiente){
	cout << "└──Globo:\n";
	show(ambiente.globo);
	cout << "\n└──Rack:\n";
	show(ambiente.rack);
	cout << "\nNumero sorteado: " <<  ambiente.sorteado << endl;
}

int opcao(Ambiente & ambiente){
	int opc = 0;
	cout << "Escolha 1 para pedir bola e 0 para sair:\n";
	cin >> opc;
	if(opc == 1){
		sortear(ambiente);
		return 1;
	}
	return 0;
}

void bingo(Ambiente & ambiente){
	int qt_vezes = 0;
	while(qt_vezes < max_globo_rack){
		system("clear");
		show_globo_rack(ambiente);
		if(opcao(ambiente) == 0)
			break;
		qt_vezes++;
	}
	system("clear");
	show_globo_rack(ambiente);
	cout << "\nObrigado e volte sempre.\n\n";
}

int main(){
	srand(time(NULL));
	
	Ambiente ambiente;
	marcar_globo_rack(ambiente);
	bingo(ambiente);

	
	return 0;
}