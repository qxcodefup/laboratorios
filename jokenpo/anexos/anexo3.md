## C99

```c
#include <stdio.h>

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

```

## C++11

```c++
#include <iostream>
using namespace std;

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

```

## Python2

```python
def checkGame(jogador, pc):
	if jogador == 1 and pc == 2:
		return 2
	if jogador == 1 and pc == 3:
		return 1

	if jogador == 2 and pc == 1:
		return 1
	if jogador == 2 and pc == 3:
		return 2

	if jogador == 3 and pc == 1:
		return 2
	if jogador == 3 and pc == 2:
		return 1

	return 0
```
