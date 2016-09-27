from random import randint
import os

max_globo_rack = 75

class Ambiente:
	globo = []
	rack = []
	sorteado = 0


def sortear(ambiente):
	num_sorteado = randint(0,max_globo_rack-1)
	while(1):
		if(ambiente.rack[num_sorteado] == 1):
			break
		num_sorteado = randint(0,max_globo_rack-1)
	
	ambiente.rack[num_sorteado] = 0
	ambiente.globo[num_sorteado] = 1
	ambiente.sorteado = num_sorteado+1


def show(vetor):
	string = ""
	for i in xrange(0,max_globo_rack):
		if(vetor[i] == 0):
			string += str(i+1) + " "
		else:
			string = string + "-- "
		if((i+1) % 15 == 0):
			print(string)
			string = ""
	

def marcar_globo_rack(ambiente):
	
	for i in xrange(0,max_globo_rack):
		ambiente.globo.append(0)
		ambiente.rack.append(1)	
	


def show_globo_rack(ambiente):
	print("Globo:")
	show(ambiente.globo)
	print("Rack:")
	show(ambiente.rack)
	print "Numero sorteado: " + str(ambiente.sorteado)


def opcao(ambiente):
	opc = input("Escolha 1 para pedir bola e 0 para sair:")

	if(opc == 1):
		sortear(ambiente)
		return 1
	return 0


def bingo(ambiente):
	qt_vezes = 0
	while(qt_vezes < max_globo_rack):
		os.system("clear")
		show_globo_rack(ambiente)
		if(opcao(ambiente) == 0):
			break;
		qt_vezes += 1;
	
	os.system("clear")
	show_globo_rack(ambiente)
	print("Obrigado e volte sempre.")


if __name__ == "__main__":
	ambiente = Ambiente()
	marcar_globo_rack(ambiente)
	bingo(ambiente)
