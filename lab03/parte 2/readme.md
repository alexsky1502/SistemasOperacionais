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
pi estimado = 3.141592643589326
```
```
busy wait
com n = 100000000 termos,
com 2 threads,
pi estimado = 3.141592643589817
```

## Com mutexes
```
mutexes
com n = 100000000 termos,
com 1 threads,
pi estimado = 3.141592643589326
```
```
mutexes
com n = 100000000 termos,
com 2 threads,
pi estimado = 3.141592643589817
```

## Valor de pi
```
mutexes
com n = 100000000 termos,
pi = 3.14159265
```


Conforme aumentamos o número de termos, aumentar o número de threads nos aproxima mais do resultado correto.
