import random

AS = 1
VALETE = 11
DAMA = 12
REI = 13

class Jogador:
    nome = ""
    mao = []
    total = 0


nomes_cartas = ["", "As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"]

def carta_pegar_nome(carta):
    return nomes_cartas[carta]

def carta_pegar_valor(carta):
    if carta == AS:
        return 11
    if (carta >= 2) and (carta <= 10):
        return carta
    return 10

def jogador_recalcular_mao(jog):
    total = 0
    n_as = 0
    for carta in jog.mao:
        total += carta_pegar_valor(carta)
        if carta == AS:
            n_as += 1

    while(total > 21 and n_as > 0):
        total -= 10
        n_as -= 1

    jog.total = total

def jogador_imprimir(jog):
    print "Total ", jog.nome, ": ", jog.total, "[ ",
    for carta in jog.mao:
        print carta_pegar_nome(carta), " ",
    print "]"


def jogador_pedir_carta(jog):
    carta = int(random.uniform(1, 13))
    jog.mao.append(carta)
    jogador_recalcular_mao(jog)
    print "|---Foi puxada a carta ", carta_pegar_nome(carta),
    print " para ", jog.nome


def logica_jogar_humano(jogador):
    opcao = 0
    while(jogador.total <= 21):
        jogador_imprimir(jogador)
        opcao = int(input("Menu: 1 - Pedir Carta, 2 - Parar:\n>>"))
        if opcao == 1:
            jogador_pedir_carta(jogador)
        else:
            return

def esperar():
    print "Digite 1 para continuar:\n>>",
    input()

def logica_jogar_maquina(jogador, mesa):
    while (mesa.total < jogador.total and mesa.total <= 21):
        jogador_pedir_carta(mesa)
        jogador_imprimir(mesa)
        esperar()


'''Inicio da funcao principal '''

mesa = Jogador()
mesa.nome = "Mesa"
mesa.mao = []
mesa.total = 0

jogador = Jogador()
jogador.nome = "Jogador"
jogador.mao = []
jogador.total = 0

print "Inicio do jogo"
jogador_pedir_carta(mesa)
jogador_pedir_carta(jogador)
jogador_pedir_carta(jogador)

jogador_imprimir(mesa)

logica_jogar_humano(jogador)
if jogador.total > 21:
    print "Mesa Ganhou"
else:
    logica_jogar_maquina(jogador, mesa)
    if mesa.total > 21:
        print "Jogador Ganhou"
    else:
        print "Mesa Ganhou"
