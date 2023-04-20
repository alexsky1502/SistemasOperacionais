
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

A) Conforme aumentamos o numero de N, o desempenho com apenas uma thread melhora. 

B) O busy wait continua usando o processador mesmo sem realizar nenhum trabalho útil enquanto espera a liberação. Os mutexes liberam o processador para que outras tarefas possam usá-lo.
