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

### Feature6390
Feature Grafica.  
In questa feature andrò a descrivere le funzioni minime che servono per completare la libreria grafica per il tetris.  
Le funzioni dipendono direttamente da quante fasi/schermate di gioco esistono, sulla base di questo numero andranno a cambiare anche le funzioni grafiche.
Le scheramte di gioco sono:  
* schermata iniziale
* schermata di accesso
* schermata di registrazione
* schermata principale
* schermata statistiche
* schermata impostazioni
* schermata di gioco
* schermata di pausa gioco (?)
* schermata di carica partita (?)

Ogni schermata è stata descritta nei miei appunti.    

Verrà inoltre aggiunto un file .h che contenga tutte le lettere dell alfabeto sotto forma di matrice 5x4, in questo modo potrò scrivere scritte ovunque, grandi quanto voglio in maniera molto agile. Per questa parte qua preferirei aggiungere una nuova libreria in modo tale che sia portabile nei prossimi progetti.  
All'interno del .h della libreria posso andare a descrivere tramite un array static const (che contiene *matrici*) tutte le lettere come le preferisco.  
Oltre alle normali funzioni (getLettera, printLettera etcetc), ci sarà una funzione stampaScritta che prende un array di char (e delle impostazioni) e stampa a schermo la scritta seguendo le impostazioni date. Le impostazioni comprenderanno:
* PosX e posY che potranno anche essere null, nel caso verrà presa la posizione in quel momento del cursore nella console.
* Dimensione delle scritte, un int che rappresnta quanto espansi saranno i quadrati, la base è 2, ma inserendo un numero maggiore di 2 si va a definire quanto grande dovrà essere il quadrato per ogni 'pixel'.
* array di colori e la sua dimensione. L'array serve a dare il colore alle scritte, se c e piu di un elemento si applica il colore di quell elemento alle lettere in maniera ciclica. Quindi la prima lettera prenderà il colore presente in posizione 0, la seconda lettera prenderà il colore presente in posizione 1, etcetc fino a lettera n con colore m.
Se i colori finiscono, ri-inizia il conteggio da 0.
* valore numerico che definisce l'opacità delle lettere, per questo definirò anche  una enum che permetterà all utente di appunto chiamare brightness.HIGH, MEDIUM, oppure LOW. come primi tre valori.