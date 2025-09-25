#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "../headers/funzioni.h"
#include "../headers/elemento.h"
#include "../headers/figure.h"
#include "../headers/funzioniGrafiche.h"


int main( int argc, char *argv[]  ){
    //Valori di default per impostazioni
    int figura = 1;
    int modalita = 0;
    if( argc == 3 ){
      figura = atoi( argv[1] );
      modalita = atoi( argv[2] );
    }
    else if( argc != 1){
      termina(stderr, "Uso errato del programma. Usare come:\n\tTetris x y\n\tCon:\n\t x = figura da visualizzare\n\t y = modalita", __FILE__, __LINE__);
    }

    int mpr = 5, mpc = 6;
    int valori[5][6] = {
      {0, 0, 0, 0, 1, 1},
      {0, 0, 0, 1, 1, 0},
      {1, 0, 0, 0, 1, 1},
      {1, 1, 0, 0, 1, 1},
      {0, 1, 0, 0, 1, 0},
    };
    
int **matrice = malloc(mpr * sizeof(int *));
    for (int i = 0; i < mpr; i++) {
        matrice[i] = malloc(mpc * sizeof(int));
    }
    // copia valori
    for (int i = 0; i < mpr; i++) {
        for (int j = 0; j < mpc; j++) {
            matrice[i][j] = valori[i][j];
        }
    }

    stampaMatriceBella( NULL , NULL, matrice, mpr, mpc );

    /*
    system("cls");
    char c = 0;
    elemento *e = getFigura(figura);
    stampaElemento(e, &modalita, NULL, NULL);
    printf("\nPremi un tasto per continuare..");
    do{
      c = getche();
      if( c == 'd' || c == 'D'){
        system("cls");
        e = ruotaOrario( e );
        stampaElemento(e, &modalita, NULL, NULL);
      printf("\nPremi un tasto per continuare..");
      }
      else if( c == 'a' || c == 'A'){
        system("cls");
        e = ruotaAntiOrario( e );
        stampaElemento(e, &modalita, NULL, NULL);
      printf("\nPremi un tasto per continuare..");
      }
    }while( c != 27 );
    distruggiElemento(e);
    */

    return 0;
}
