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

### Feature3390
In questa Feature andrò ad aggiungere la gestione account degli utenti.  
Un utente sarà gestito come una struct che contiene:  
* Nome
* PunteggioRecord
* Durata massima di una partita
* Durata media delle partite giocate
* Numero partite giocate
* Blocco preferito (il blocco che ha permesso al giocatore di fare punti più frequentemente)
* Colori Grafica
* Modalità della grafica
Tutto questo verrà salvato in un file txt all interno della cartella data/utenti.txt.

### Feature4390
In questa feature andrò a costruire la parte di gestione del gioco.  
Utilizzerò una pila per gestire gli "eventi", quindi l'evento base sarà la schermata di inizio: "Premi un tasto per iniziare...".  
Questo rimarrà sempre nello stack e quando un evento deve essere aggiunto basta usare semplicemente la funzione push.  
Se l'evento è finito basterà utilizzare la funzione pop.  
Nel caso della schermata di inizio, appena si clicca un tasto verrà agguinta tramite la push una nuova schermata.
Le schermate sono:
* Schermata iniziale (Premi un tasto per iniziare..)
* Se non è loggato allora scelta utente, o aggiungi utente.
* Se l'utente è loggato (o dopo che logga/crea un profilo) si va alla schermata Principale. Da qui tutto il menu.  
Nella schermata principale sarà possibile:  
    * Iniziare una nuova partita
    * Aprire le impostazioni (per la grafica)
    * Vedere le proprie statistiche
    * Fare logout ed uscire
* Impostazioni durante il gioco
Essenzialmente ogni volta che si sceglie qualcosa viene fatto un push, ogni volta che una selle schermate della schermata principale viene completata viene eseguito un pop.

### Feature5390
Infine la feature di gioco.  
Il gioco di svolgerà all interno di un while finché il giocatore non perde oppure non si arrende (quindi comunque perde).  
Il giocatore partirà con 0 punti, ed ogni volta che l'elemento che stava sulla griglia in precedenza non può più muoversi (Ha incontrato un ostaccolo sotto di se)
in automatico verrà controllato se una delle righe in cui si è fermato è "completa" quindi ci sono blocchi in tutta la riga.
Nel caso la riga viene distrutta e le righe soprastanti scendono finché non possono fermarsi, e viene ricalcolato.
Nella schermata di gioco devono essere presenti le seguenti informazioni:
* Nome giocatore 
* Lista dei tasti che può utilizzare
* Griglia di gioco
* Prossimo elemento che verrà spownato
* Punteggio attuale
* Tempo di gioco Attuale
Il gioco verrà svolto tramite un potente while. la guardia andrà appunto a controllare se l utente ha perso continuamente oppure se si è arreso.
All interno del while diversi timer gestiranno il gioco:
* Il primo timer è per i tasti premuti, l'utente può premere un tasto solo ogni 100 millisecondi, altrimenti viene cancellato quello che ha cliccato.
* Il secondo timer è per il movimento dell'elemento, aumentando il tempo di gioco aumenta anche il livello di difficolta, quindi diminuisce il delay del movimento del blocco
fino a 400 milliseconddi, partendo da 1500 (andando a diminuire di 100 ogni 2 minuti di gioco).