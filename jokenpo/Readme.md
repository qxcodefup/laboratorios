<img src="imagens/header.png" />

# Jokenpô: Laboratório Prático

## Introdução
Nessa prática nós vamos trabalhar apenas com:

- Estruturas de seleção.
- Laços.
- Funções.

Vamos utilizar C, C++ e Python nesse laboratório.

Vamos criar um acordo de cavalheiros/damas. Ao final de cada tópico existe uma link com uma solução, mas lembre-se, o laboratório é realmente eficaz quando você tenta fazer sozinho e só olha as repostas pra conferir seu código ou se travar em alguma parte. Se você for só olhando e lendo as respostas, seu
aprendizado vai ficar comprometido. PS: "você nunca vai virar Jedi".

---

## Primeiras definições

O jogo Jokenpô (ou Pedra, Papel e Tesoura) é jogado por um jogador contra o PC,
em que o jogador escolhe uma jogada e o PC gera aleatoriamente uma jogada dentre
as três opções, o jogo se divide em cinco rounds, onde a cada round é mostrado
na tela as opções dos jogadores, quem venceu a rodada (ou empate caso as jogadas
sejam iguais) e quantas rodadas faltam para terminar a partida. As regras que
definem as vitórias são as seguintes:

1. **Pedra** ganha da **tesoura**.
2. **Tesoura** ganha do **papel**.
3. **Papel** ganha da **pedra**.

Para facilitar você pode definir uma variável **int** de 1 a 3 representando respectivamente pedra, papel e tesoura.

Este trabalho tem como objetivo que você desenvolva habilidades de
desenvolvimento de jogos, como contagem de pontos, jogadas aleatórias, rounds e
início e fim do game.

---

## Sorteando a jogada do PC

Nosso primeiro objetivo é fazer uma função que gere aleatóriamente uma jogada
válida. Vamos apenas gerar um valor válido aleatório entre 1 e 3.

Em C e C++ você pode usar a função **rand()** para gerar um número aleatório.

Crie uma função jogada_pc que gera e retorna um número entre 1 e 3. Dê uma pesquisada na internet pra descobrir como fazer isso na sua linguagem. Teste pra ver se ela funciona mesmo e se a cada vez que seu código é executado, ela gera um valor diferente.
```
funcao jogada_pc
	carta = gerar valor aleatorio entre 1 e 3
	retornar jogada
fim
```

Caso você esteja fazendo em C ou C++ vocẽ só precisa chamar a função **srand(time(NULL))** (Esta função irá inicializar  a aleatoriedade) uma única vez no seu código. Normalmente, durante a inicialização das variáveis.

[Respostas](anexos/anexo1.md)

---

## Mostrando a jogada

Precisamos ser capazes de mostrar o número como uma jogada. Se nossa jogada é um 1, queremos imprimir pedra e não o 1.

Vamos criar uma função **pegar_nome()** que recebe o número inteiro e retorna uma string.

```
funcao pegar_nome(jogada)
	se jogada == 1
		retorne "Pedra"
	se jogada == 2
		retorne "Papel"
	retorne "Tesoura"
fim
```

[Respostas](anexos/anexo2.md)

---

## Checagem do vencedor

Você precisará verificar quem foi o vencedor da rodada, para isso você deverá criar a função **checkGame()** que receberá a jogada do Jogador e a do PC e verificará quem foi o vencedor retornando 0 para empate, 1 para vitória do Jogador e 2 para vitória do PC.

```
funcao checkGame(jogador, pc)
	se jogador == 1 and pc == 2
		retorne 2
	se jogador == 1 and pc == 3
		retorne 1

	se jogador == 2 and pc == 1
		retorne 1

	....
fim
```

Continue até terminar todos os casos e lembre-se de deixar um retorno padrão.

[Respostas](anexos/anexo3.md)

---

## Sistema de rodadas

Antes de iniciar as iterações, você deverá criar algumas variaveis que guardarão informações importantes, são essas:

- A jogada do Jogador;
- A jogada do PC;
- A quantidade de vitórias do Jogador;
- A quantidade de vitórias do PC;
- O round atual;
- Uma variável que guarda a opção de contuar jogando ou não.

Lembre-se de atualizá-las a cada iteração.

Agora, iremos criar um sistema de rodadas, essa parte pode ser feita na função **main()**, para fazermos um sistema iterativo precisaremos de um laço que rode 5 vezes para simular os rounds.

Em linguagens como C e C++ existe uma função principal **main()** que é executada automaticamente a cada vez que o programa é iniciado, em Python você poderá usar "<code>if __name__ == '__main__':</code>" como sua função principal, assim não será necessário criar esta função e depois chama-lá, pois ela será executada automaticamente.

A cada round será mostrado a seguinte interface abaixo:

```
# JOKENPO #
Você: "Nº vitórias do Jogador" | PC: "Nº vitórias do PC"
Round: "Nº round atual" / 5"
1 - Pedra
2 - Papel
3 - Tesoura
```

Logo após, o sistema irá espera que o jogador digite sua jogada, depois que isso acontecer você chamará a função **jogada_pc()** onde seu retorno deverá ser armazenado na variável que guarda as jogadas do PC. Depois de possuir as duas jogadas você deverá imprimir uma mensagem informando quais foram as jogadas dos dois jogadores, para isso você deverá usar a função **pegar_nome()**.

Depois você deverá chamar a função **checkGame()** que permitirá identificar o vencedor da rodada. Na tela deverá ser impresso uma mensagem informando quem ganhou ou "Ninguem ganhou" caso dê empate. Lembre-se de atualizar a variável que indica a quantidade de vitória dos dois jogadores.

Se você já estiver no 5º round então deverá ser impresso na tela as seguintes informações:

```
PLACAR FINAL:
Você: "Nº vitórias do Jogador" | PC: "Nº vitórias do PC"

JOGAR NOVAMENTE?
1 - SIM | 0 - NÃO
```

Caso o Jogador escolha jogar novamente então você deverá zerar o contador e todas as outras informações para que um novo jogo seja iniciado.

[Respostas](anexos/anexo4.md)
