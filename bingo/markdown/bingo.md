# Bingo: Laboratório Prático

## Introdução
Nessa prática nós vamos trabalhar apenas com:

- Estruturas de seleção
- Vetores
- Laço,
- Funções.

Vamos utilizar C, C++ e Python nesse laboratório.

Vamos criar um acordo de cavalheiros. O laboratório é realmente eficaz quando você tenta fazer sozinho e só olha as repostas pra conferir seu código ou se travar em alguma parte. Se você for só olhando e lendo as respostas, seu aprendizado vai ficar comprometido. PS: "você nunca vai virar Jedi".


## Primeiras definições

A primeira decisão é como vamos definir nosso globo e o nosso rack. Podemos utilizar:

- Um vetor **int** de marcação que representaria os estados de cada posição com 0 e 1, onde 0 = numero e 1 = "--".
- Ou utilizar uma matriz seguindo uma lógica similar da 1° ideia.
- Ou se você tiver uma ideia mais simples pode sentir-se a vontade para implementar ;).

Basicamente precisamos ser capazes de representar os estados de cada numero **sorteado** e **não sorteado**, nesse laboratório sera abordado a ideia do vetor de marcação.

Com isso em mente vamos ao trabalho em busca de se tornar um nobre ***Cavaleiro Jedi***.


## Marcando Globo e Rack

####Exemplo para um vetor com 6 posições:
Inicializado com zeros (0,0,0,0,0,0) será mostrado da seguinte forma.
- 1 2 3 4 5 6

Quando um dos estados do vetor for alterado para um (0,0,1,0,0,0) será mostrado da seguinte forma.
- 1 2 -- 4 5 6


Nosso primeiro objetivo é fazer uma função que preencha os vetores Globo com 0 e Rack com 1. Crie uma função marcar_globo_rack.

Crie a função e adicione 0 em todas as posições do globo e 1 nas do rack.

```
funcao marcar_globo_rack
	enquanto i < max_globo_rack #tamanho do globo e do rack que no caso é 75.
		globo[i] = 0
		rack[i] = 1
fim
```

[Respostas](anexos/marcar.md)

## Mostrando Globo e Rack
Nosso objetivo é fazer uma função que mostre no terminal os valores **sorteado** e **não sorteado** dos vetores globo e rack.

```

Globo:

01 02 03 04 05 06 07 08 09 10 11 12 13 14 15

16 17 18 19 20 21 22 23 24 25 26 27 28 29 30

31 32 33 34 35 36 37 38 39 40 41 42 43 44 45

46 47 48 49 50 51 52 53 54 55 56 57 58 59 60

61 62 63 64 65 66 67 68 69 70 71 72 73 74 75

Rack:

── ── ── ── ── ── ── ── ── ── ── ── ── ── ──

── ── ── ── ── ── ── ── ── ── ── ── ── ── ──

── ── ── ── ── ── ── ── ── ── ── ── ── ── ──

── ── ── ── ── ── ── ── ── ── ── ── ── ── ──

── ── ── ── ── ── ── ── ── ── ── ── ── ── ──
```


###Dica:
A ideia é utilizar um laço de repetição que irar percorrer o vetor que for passado na função, caso a posição do vetor esteja com 0 será mostrado o número correspondente aquela posição. "Lembre-se, cada índice acrescentado de mais um é exatamente o valor que aquele vetor possui ;)"


```
funcao mostrar
	enquanto i < max_globo_rack #tamanho do globo e do rack que no caso é 75.
		se(vetor[i] == 0):
			print i+1 + " "
		se não
			print "-- "
fim
```

[Respostas](anexos/mostrar.md)

##Sortear número ~('-'~)
Agora que já sabemos marcar os vetores e sabemos mostrá-los no terminal vamos implementar a função de sortear para concluir todas as funções do nosso laboratório \o/.

Como sortear números aleatóriamente ?-?. De uma pesquisada na forma de fazer isso em sua linguagem.

Pronto já sei como fazer um número ser gerado de forma aleatória, mas e ai como faço para marcar o vetor e não deixar um número repetido ser gerado?

Para marca é bem simples vejamos. Basta sortear o número de 0 a 74 que são respectivamente cada um dos indices do vetor. Sabendo disso basta olhar aquela posição se já saiu, ou seja verificar no rack[posição] se aquela posição é igual a 1.

```
funcao sortear
	num_sorteado = aleatorio(0,max_globo_rack) # será gerado números de 0 até 74 que são os indices dos vetores.

	rack[num_sorteado] = 0
	globo[num_sorteado] = 1
	sorteado = num_sorteado+1
fim
```
Simples né?

Mas caso saia algum repetido?

Calma jovem padawn

Basta fazer uma validação utilizando um while, enquanto não for sorteado um número que ainda não tenha saído ele irá continuar sorteando ;).

```
funcao sortear
	num_sorteado = aleatorio(0,max_globo_rack) # será gerado numeros de 0 até 74 que são os indices dos vetores.
	enquanto(true)
		if(rack[num_sorteado] == 1):
			break
		num_sorteado = aleatorio(0,max_globo_rack)

	rack[num_sorteado] = 0
	globo[num_sorteado] = 1
	sorteado = num_sorteado+1
fim
```

[Respostas](anexos/sortear.md)

Parabéns com isso você tem todas as ferramentas necessárias para estruturar o seu próprio bingo. Agora cabe a você juntar tudo o que foi feito até o momento e criar seu bingo.
