# tetrisC
Scrivo Tetris in C sulla console.

## Idee:
Vedo il campo di tetris come una matrice di boolean:
true = presente un blocco.
false = non è presente un blocco.
Quando un blocco non può più scendere perché è presente un blocco sotto (nella posizione blocco.x blocco.y +1) allora il blocco si ferma dal scendere e viene ricalcolata la matrice.
Se la matrice ha delle righe tutte ad uno, allora vengono messe a 0 , e le righe che stanno sopra vengono fatte scendere di una posizione nelle y (Considerando che il blocco in alto a sinistra è 0,0)
Per gli oggetti che vengono creati userò delle matrici più piccole che, tramite un timer, faranno aumentare la posizione di tutti i blocchi che contengono di 1.

### Rotazione
