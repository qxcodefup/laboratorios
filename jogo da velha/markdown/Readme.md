# Jogo da Velha: Laboratório Prático

## Introdução
Nessa prática iremos trabalhar apenas utilizando:

- Estrutura de seleção
- Matriz
- Laço
- Funções

Vamos criar um acordo de cavalheiros. O laboratório é realmente eficaz quando você tenta fazer sozinho e só olha as repostas pra conferir seu código ou se travar em alguma parte. Se você for só olhando e lendo as respostas, seu aprendizado vai ficar comprometido. PS: "você nunca vai virar Jedi".


## Primeiras definições

A primeira decisão é como iremos representar os jogadores O e X:

Nesse laboratório proponho utilizarmos a seguinte ideia:
- Utilizar uma matriz 3x3 do tipo **int** onde o jogador X é representado por 1 e o jogador O é representado por -1.
- Ou se você tiver uma ideia mais simples pode sentir-se a vontade para implementar ;).

Basicamente precisamos ser capazes de representar os estados de cada **jogada** dos *jogadores* , nesse laboratório sera abordado a ideia de matriz de marcação.

Com isso em mente vamos ao trabalho em busca de se tornar um nobre ***Cavaleiro Jedi***.


## Inicializando a matriz

Para podermos representar os estados de jogada é preciso que antes exista um estado default na matriz, no nosso caso iremos preencher cada posição da matriz com zeros.

Exemplo * matriz 3x3 *:

    0 0 0
    0 0 0
    0 0 0

A matriz inicialmente deverá está prenchida para que dessa forma possamos trabalhar com ela.

Crie uma função * **iniciar_matriz** * para preencher a matriz com zeros.

<details><summary> _Clique para ver a dica_ </summary>

```
funcao iniciar_matriz
  enquanto l < qtd_linhas #quantidade de linhas da matriz
    enquanto c  < qtd_colunas #quantidade de colunas da matriz
      matriz[l][c] = 0
fim
```
</details>

[Respostas](anexos/iniciar_matriz.md)

## Marcar matriz
Nosso objetivo é fazer uma função que marque uma posicação da matriz dado uma linha, uma coluna e qual jogador marcou.

Exemplo:

    jogador O passa a linha e a coluna:
    >> 1 1
    << O - -
       - - -
       - - -


<details><summary> _Clique para ver a dica_ </summary>
    
     A ideia é simplesmente passar a linha e a coluna que o jogador digitou para a função marcar_matriz, onde além dos paramentos linha e coluna também iremos passar a qual jogador pertence a jogada e claro é necessário passar a refêrencia ou o ponteiro para a matriz para podermos acessa-lá na função:
---

     marcar_matriz(matriz,linha, coluna ,jog) o jog é 1 ou -1 que são respectivamente os jogadores X e O.

---

```
funcao marcar_matriz(matriz,l,c,j): 
  se matriz[l][c] == 0
    matriz[l][c] = j
    return 1
  return 0
fim

```
</details>


Lembre-se de confirmar se o jogador realmente conseguiu marcar a matriz caso ele tenha retorne 1 caso contrario retorne 0;

[Respostas](anexos/marcar_matriz.md)


## Mostra matriz
O nosso objetivo agora é conseguir mostrar a matriz para que os jogadores possam se orientar. Então crie uma função que mostra a matriz 
na tela com as seguintes retrições caso o valor de um determinado indece for igual a 0 deve-se mostrar '-', caso seja igual a 1 deve-se mostrar 'X' e caso igual a -1 deve-se mostrar 'O'. 

Exemplo:

- Matriz marcada:


    0 0 -1
    0 1 -1
    0 0 1

---
- Matriz mostrada para o usuário:


    - - O
    - X O
    - - X

<details><summary> _Clique para ver a dica_ </summary>

    Você deve verificar todos os indeces para ver qual caracter deve ser mostrado

---

```
funcao mostrar_matriz(matriz)
  
  enquanto (i = 0; i < max_linha; i++)
    enquanto (j = 0; j < max_coluna; j++)
      se(matriz[i][j] == 0)
        printf("| - |")
      se(matriz[i][j] == jog_x)
        printf("| X |")
      se(matriz[i][j] == jog_o)
        mostrar("| O |")

fim
```
</details>

[Respostas](anexos/mostrar_matriz.md)

## Verificar ganhador

Logo após um dos jogadores fazer a sua jogada, devemos verificar se o mesmo ganhou a partida. Para isso é necessario criar uma função para verificar todas as possibilidades, e caso o jagador tenha ganhado ela deve retornar 1 caso contrario 0. 

<details><summary> _Clique para ver a dica_ </summary>

    Você deve verificar todas as possibilidades daquele jogador ter ganho a partida

---

```
funcao verificar_se_ganhou(matriz,j)

  se(matriz[0][0] == j && matriz[0][1] == j && matriz[0][2] == j)
    return 1;
  se(matriz[1][0] == j && matriz[1][1] == j && matriz[1][2] == j)
    return 1;
  se(matriz[2][0] == j && matriz[2][1] == j && matriz[2][2] == j)
    return 1;
  se(matriz[0][0] == j && matriz[1][0] == j && matriz[2][0] == j)
    return 1;
  se(matriz[0][1] == j && matriz[1][1] == j && matriz[2][1] == j)
    return 1;
  se(matriz[0][2] == j && matriz[1][2] == j && matriz[2][2] == j)
    return 1;
  se(matriz[0][0] == j && matriz[1][1] == j && matriz[2][2] == j)
    return 1;
  se(matriz[0][2] == j && matriz[1][1] == j && matriz[2][0] == j)
    return 1;
  return 0;

fim
```
</details>

[Respostas](anexos/verificar_ganhador.md)

# Juntar tudo e botar pra rodar \\( '-' )/

Depois de imprementado todas as partes funcionais do código fica fácil juntar tudo e executar o jogo. Então fique a vontade para implementar.

<details><summary> _Sugestão camarada ;)_ </summary>

    Você deve verificar todos os indeces para ver qual caracter deve ser mostrado

---

```
enquanto(true)

    mostrar_matriz(matriz)
    faça{

      mostrar("jogador X: 'digite a linha e a coluna'\n")
      ler(l,c)
    
    }enquanto(marcar_matriz(matriz,l-1,c-1,jog_x))
    
    se(verificar_se_ganhou(matriz,jog_x))
      mostra("jogador X ganhou\n");
      break
    
    mostrar_matriz(matriz);
    
    faça{
      
      mostrar("jogador O: 'digite a linha e a coluna'\n")
      ler(l,c);
    
    }enquanto(marcar_matriz(matriz,l-1,c-1,jog_o));
    
    se(verificar_se_ganhou(matriz,jog_o))
      mostar("jogador O ganhou\n")
      break
    
    mostrar_matriz(matriz);

```
</details>
