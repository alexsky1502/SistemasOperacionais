
## Valor real de pi
```
mutexes
com n = 100000000 termos,
pi = 3.14159265
```

## Sem mutex e busy wait
```
com race condition
com n = 100000000 termos,
com 1 threads,
pi estimado = 3.141592643589325994923910911893
```
```
com race condition
com n = 100000000 termos,
com 2 threads,
pi estimado = 3.141592643590250588658818742260
```
```
com race condition
com n = 100000000 termos,
com 5 threads,
pi estimado = 3.141592643589816713500795231084
```
## Com busy wait
```
busy wait
com n = 100000000 termos,
com 1 threads,
pi estimado = 3.141592643589325994923910911893
```
```
busy wait
com n = 100000000 termos,
com 2 threads,
pi estimado = 3.141592643590250588658818742260
```
```
busy wait
com n = 100000000 termos,
com 5 threads,
pi estimado = 3.141592643589816713500795231084
```

## Com mutexes
```
mutexes
com n = 100000000 termos,
com 1 threads,
pi estimado = 3.141592643589325994923910911893
```
```
mutexes
com n = 100000000 termos,
com 2 threads,
pi estimado = 3.141592643590250588658818742260
```
```
mutexes
com n = 100000000 termos,
com 5 threads,
pi estimado = 3.141592643589816713500795231084
```

## Explicações

O uso de mutexes ou busy wait evita race conditions no acesso à variável sum. Dessa forma, o resultado final torna-se mais preciso. Além disso, conforme aumentamos o número de termos, aumentar o número de threads nos aproxima mais do resultado correto.
