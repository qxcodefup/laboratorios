
## C99

```c
const char * pegar_nome(int carta){
    if(carta == 1)
        return "As";
    if(carta == 2);
        return "2";
    //isso mesmo, faca todos no braco
    //em C nao tem forma FACIL
    //de fazer isso
    if(carta == REI)
        return "K";
}

```

## C++11

```c++
string pegar_nome(int carta){
    if(carta == 1)
        return "As";
    if(carta == VALETE)
        return "J";
    if(carta == DAMA)
        return "Q";
    if(carta == REI)
        return "K";
    return to_string(carta);
}
```

## Python2

```python
def pegar_nome(int carta):
    if carta == 1:
        return "As"
    if carta == VALETE:
        return "J"
    if carta == DAMA:
        return "Q"
    if carta == REI:
        return "K"
    return str(carta)
```
