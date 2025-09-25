#include <stdio.h>
#include <stdlib.h>
#include "../headers/funzioni.h"
#include "../headers/elemento.h"
#include "../headers/figure.h"


int main( int argc, char *argv[]  ){
    //Valori di default per impostazioni
    int figura = 0;
    int modalita = 0;
    if( argc == 3 ){
      figura = atoi( argv[1] );
      modalita = atoi( argv[2] );
    }
    else if( argc != 1){
      termina(stderr, "Uso errato del programma. Usare come:\n\tTetris x y\n\tCon:\n\t x = figura da visualizzare\n\t y = modalita", __FILE__, __LINE__);
    }

    elemento *e = getFigura( figura );
    stampaMatrice(e->matrice, e->width, e->height);
    
    stampaElemento(e, &modalita, NULL, NULL);
    distruggiElemento(e);

    return 0;
}
