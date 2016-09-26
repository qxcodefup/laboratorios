# Blackjack: Laboratório Prático

## Introdução
Nessa prática nós vamos trabalhar apenas com:

- Estruturas de seleção
- Vetores
- Laço,
- Funções.
- Structs
- Ponteiros
- Strings 
- Aleatoriedade

Vamos mostrar exemplos em C, C++11 e Python2 nesse laboratório.

Vamos criar um acordo de cavalheiros. O laboratório é realmente eficaz quando você tenta fazer seu código e só olha as repostas pra conferir ou se travar em alguma parte. Se você for só olhando e lendo as respostas, seu aprendizado vai ficar comprometido, ou seja, você nunca vai virar um mestre Yoda da programação.

## Primeiras definições

A primeira decisão é como vamos definir uma carta. Nossa escolha será:

- Uma variável **int** de 1 a 13 representando as cartas.

Em C e C++ poderíamos usar **enum**, mas vamos usar um **int** simples aqui. Pesquise um pouco sobre enums depois.

Como vamos fazer várias comparações de valores, não fica muito profissional ficar escrevendo:

    se carta == 12
        faça tal coisa
    end

Usar números mágicos no código é uma péssima ideia. Vamos criar umas constantes para tratar cartas como As, Valete, Dama e Rei. É uma convenção que nomes de constantes sejam todo em MAIUSCULO. Veja como ficaria definir constantes em: 
[c](c/constantes.md),
[cpp](cpp/constantes.md),
[py](py/constantes.md).

Basicamente precisamos ser capazes de sortear, imprimir e manipular nossas cartas.  As duas primeiras opções são boas. Vamos escolher definir a carta como
um inteiro.  

## Sorteando a carta

Nosso primeiro objetivo é fazer uma função que gere aleatóriamente uma carta
válida.  Por enquanto, não vamos montar o baralho todo. Vamos apenas gerar um valor válido aleatório entre 1 e 13.

Em C e C++ você pode usar a função \code{rand()} para gerar um número aleatório.

Crie uma função sortear_carta que retorna um número entre 1 e 13. Dê uma pesquisada na internet pra descobrir como fazer isso na sua linguarem.
```
funcao sortear_carta
	carta = gerar valor aleatorio entre 1 e 13
	retornar carta
fim
```

[Respostas](anexos/rand.md)

Você só precisa chamar a função \code{srand(time(NULL))} uma única vez no seu
código. Normalmente, durante a inicialização das variáveis. Faça uma função
\code{int sortear_carta();}que gera um número entre 1 e 13 usando \code{rand}.
Teste pra ver se ela funciona mesmo e se a cada vez que seu código é executado,
ela gera um valor diferente.

# Mostrando a carta

Precisamos ser capazes de mostrar o número como uma carta. Se nossa carta é um 12, queremos imprimir Q e não o 12.
Vamos criar uma função que recebe o número inteiro e retorna uma string.

```
funcao pegar_nome(carta)
	se carta == 1
		retorne "A"
	senao se(carta > 1 e carta < 11)
		retorne carta como string
	senao se ...
fim
```

[Respostas](anexos/pegar_nome.md)

O método \code{string to_string(value)} to C++ recebe um int, char, float,
double e retorna uma string.

\subsection{Calculando mão de cartas}

Vai ser útil se você tiver uma função que recebe a carta e retorna o valor.

%\begin{mdframed}[nobreak=true]
	\begin{lstlisting}
	int pegar_valor(int carta){
		if(carta == 1)
			return 11;
		else if( //termine o codigo ok...
	}
	\end{lstlisting}
%\end{mdframed}

Para nós, o A vale 11, a não ser que isso estoure a mão do jogador. Mas por favor,
não faça um \code{if} para cada carta, ok? Observe a lógica e veja que 10, J, Q
e K, possuem o mesmo valor, portanto podem ficar no mesmo \code{if}. Os números
de 2 a 9 também podem ficar no mesmo \code{if}.

\subsection{Calculando a mão}

Agora o caldo engrossa! Aqui temos provavelmente a parte mais interessante do
código. Nosso objetivo é assumir que o A vale 11 e calcular o valor da mão. Ao
mesmo tempo contamos quantos As tem na nossa mão. Após termos o total, se ele
passar de 21, vamos descontando nossas cartas As, para fazer o valor baixar.

\begin{mdframed}[nobreak=true]
	\centering{Pseudocódigo para calcular o valor de uma mao}
	\begin{lstlisting}
	int contar_mao(vector<int> mao){
		total = 0
		n_as = 0
		Para cada carta na mao:
			incremente total do valor da carta
			Se a carta for um A:
				n_as aumenta de 1
		Enquanto o total > 21 e n_as > 0:
			decrementa total de 10
			decremente n_as de 1
		retorne total
	}
	\end{lstlisting}
\end{mdframed}

Perceba que fazer o A voltar de 11 para 1 significa retirar 10 pontos do valor
da mão. Você pode fazer isso, quantas vezes você precisar(enquanto tiver
estourado) e ainda tiver A pra trocar.

\subsection{Vamos JOGAAAAAAAAARRRRRR!!!}

O dealer\note{O funcionário que coordena a mesa} pede uma carta
para mesa e duas para o jogador deixando todas viradas para cima. O jogador vai
pedindo cartas à mesa. Seu objetivo é chegar o mais perto que puder de ter uma
mão com valor 21. Se ele passar de 21 ele automaticamente perde. Se ele fizer
exatos 21 pontos ele ganha.

Após o jogador parar sua jogada, supondo que ele não estourou o limite, a
mesa(máquina) vai puxar as cartas para tentar vencer o jogador. A mesa tem a
vantagem do empate. Se ela fizer a mesma pontuação do jogador ela ganha. Se ela
estourar, ela perde. \note{No nosso modelo, a mesa ou ganha ou estoura, porque
ela não vai se contentar em perder.}

Vou lhe ajudar com a lógica ok?

\begin{mdframed}[nobreak=true]
	\centering{Pseudocódigo para lógica do jogo}
	\begin{lstlisting}
		_mao_mesa comeca vazia
		_mao_jogador comeca vazia
		puxa uma carta para _mao_mesa
		puxa duas cartas para _mao_jogador
		Enquanto jogador nao estourar
			mostrar maos
			pergunta opcao ao jogador
			Se opcao for pedir
				puxa carta para _mao_jogador
			Senao se opcao for parar
				quebre o laco
            Fim
        Fim
        Se jogador estourou
            jogador perdeu
        Senao
            Enquanto mesa nao ganhar e nao estourar
                puxar carta para mesa
                mostrar maos
            Fim
        Fim

	\end{lstlisting}
\end{mdframed}

Sugiro que crie uma função que mostre a mão de um jogador. Algo como \code{string mostrar_mao(vector<int> mao)}.
A saída pode ser parecida \code{Total 17 [2 A 4 K]}. A seguir, um exemplo de possível aparência do jogo.

\begin{mdframed}[nobreak=true]
	\centering{Exemplo: Jogador perdendo.}

	\begin{verbatim}
	Iniciando Rodada:
	# Mesa recebe  7 - Total  7 [ 7 ]
	# Voce recebe  A - Total 11 [ A ]
	# Voce recebe  2 - Total 13 [ A 2 ]
	Pedir = 1, Parar = 2
	>> 1

	# Voce recebe  3 - Total 16 [ A 2 3 ]
	Pedir = 1, Parar = 2
	>> 2

	# Mesa recebe  2 - Total  9 [ 7 2 ]
	# Mesa recebe  7 - Total 16 [ 7 2 7 ]
	# Mesa (16), Voce (16)
	Voce perdeu!
	\end{verbatim}
\end{mdframed}

\section{Melhorias}

Deixo aqui algumas sugestões pra sua diversão.
\begin{enumerate}
	\item Implementar um laço no qual o jogador continua jogando até que decida parar.
	\item Implementar um esquema de apostas no qual o jogador decide quanto quer apostar antes da rodada. O jogador pode começar com uma quantia fixa de dinheiro. Se ele ganhar a rodada, o dinheiro é adicionado na conta dele. Se ele perde, então, a, um, então ele perde.
	\item Montar um ou dois baralhos com as cartas e embaralhar. Retirar então as cartas, e após a rodada, elas vão para o montante até que o baralho termine.
	\item Implementar o jogo com mais de um jogador. Nele, a mesa vai precisar de regras um pouco diferentes. Consulte a wiki sobre Blackjack para entender mais.
\end{enumerate}

\end{document}
