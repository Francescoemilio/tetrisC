# tetrisC
Scrivo Tetris in C sulla console.

## Idee:
Vedo il campo di tetris come una matrice di boolean:  
true = presente un blocco.  
false = non è presente un blocco.  
Quando un blocco non può più scendere perché è presente un blocco sotto (nella posizione blocco.x blocco.y +1) allora il blocco si ferma dal scendere e viene ricalcolata la matrice.  
Se la matrice ha delle righe tutte ad uno, allora vengono messe a 0 , e le righe che stanno sopra vengono fatte scendere di una posizione nelle y (Considerando che il blocco in alto a sinistra è 0,0).  
Per gli oggetti che vengono creati userò delle matrici più piccole che, tramite un timer, faranno aumentare la posizione di tutti i blocchi che contengono di 1.

### Rotazione
Per la rotazione potrei scrivere una funzione che prende come parametro un elemento e ne restituisce un altro.  
All'interno della funzione creo una nuova matrice che abbia larghezza e altezza invertite rispetto all elemento originale, poi vado a
copiare gli elementi dell elemento originale all interno del nuovo elemento ruotato ma cercando di stare attento ad inserire gli elementi
nei "punti corretti", cioe ricordandomi appunto della rotazione della matrice.  
Infine distruggo il vecchio oggetto e restituisco il nuovo?  
Oppure no ?  
Idealmente nella parte principale del gioco quando uso degli elementi sono dei puntatori a zone di memoria riempite tramite la funzoine
creaElemento. Quindi l utilizzo della funzione potrebbe essere qualcosa tipo:  
elemento = ruotaOrario(elemento);  
E poi l elemento viene distrutto (il precedente) e viene restituita la nuova zona di memoria in cui puntare.  
Questo è inevitabile, in quanto gli array hanno dimensioni diverse finita la rotazione.

### Funzione grafica
Anzichè inserire una nuova modalita di stampa degli elementi posso creare una nuova funzione a parte che va a disegnare le matrici in un dato modo a seconda di com'è composta la matrice  (matrice che deve essere composta da 1 e 0).  
Per esemmpio una matrice composta come:  
1 0  
1 0  
1 1  
verrà stampata in questo modo:  
┌─┐  
├─┤  
├─┼─┐  
└─┴─┘  


## Features:
Qui inserisco le features che andrò ad inserire nel codice.  
Ogni feature è associata ad un codice, in modo tale che i branch corrispondenti alla feature si possano semplicemente chiamare "feature#ID" , questo per trovare piu facilmente le features e le loro descrizioni , e viceversa.

### Feature2390
In questa feature andrò ad inserire la rotazione e la modalita grafica nuova.  
La rotazione permetterà di ruotare una piccola matrice (quelle che compongono gli elementi) in senso orario o insenso anti-orario, andando a restituire una  nuova matrice con altezza e larghezza inverse rispetto alla matrice di partenza.  
La funzione grafica invece permetterà di disegnare una matrice composta di 0 e 1 sulla console in una versione compatta e graficamente soddisfacente per essere sulla console.