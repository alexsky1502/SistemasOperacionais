
## Valor real de pi
```
mutexes
com n = 100000000 termos,
pi = 3.14159265
```

## Sem mutex e busy wait
```
com n = 100000000 termos,
com 1 threads,
pi estimado = 3.14159264
```
```
com n = 100000000 termos,
com 2 threads,
pi estimado = 3.14159264
```
## Com busy wait
```
busy wait
com n = 100000000 termos,
com 1 threads,
pi estimado = 3.14159264
```
```
busy wait
com n = 100000000 termos,
com 2 threads,
pi estimado = 3.14159264
```

## Com mutexes
```
mutexes
com n = 100000000 termos,
com 1 threads,
pi estimado = 3.14159264
```
```
mutexes
com n = 100000000 termos,
com 2 threads,
pi estimado = 3.14159264
```

## Explicações

O uso de mutexes ou busy wait evita race conditions no acesso à variável sum. Dessa forma, o resultado final torna-se mais preciso. Além disso, conforme aumentamos o número de termos, aumentar o número de threads nos aproxima mais do resultado correto.
