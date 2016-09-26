# -*- coding: utf-8 -*-
import random
import os

def jogada_pc():
    jogada = int(random.uniform(1, 4))
    return jogada

def pegar_nome(jogada):
    if jogada == 1:
        return "Pedra"
    if jogada == 2:
        return "Papel"
    return "Tesoura"

def checkGame(jogador, pc):
    if jogador == 1 and pc == 2:
        return 2
    elif jogador == 1 and pc == 3:
		return 1
    elif jogador == 2 and pc == 1:
		return 1
    elif jogador == 2 and pc == 3:
		return 2
    elif jogador == 3 and pc == 1:
		return 2
    elif jogador == 3 and pc == 2:
		return 1
    return 0

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

        print "\nVocê jogou: " + pegar_nome(jogador) + " e o PC: " + pegar_nome(pc)

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
