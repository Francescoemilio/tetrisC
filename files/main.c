#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "../enums/caratteriGrafica.h"
#include "../headers/funzioni.h"
#include "../headers/elemento.h"
#include "../headers/figure.h"
#include "../headers/utente.h"
#include "../headers/funzioniGrafiche.h"
#include "../headers/pila.h"
#include "../headers/funzioniProgramma.h"
#include "../enums/statiDiGioco.h"
#include "../headers/funzioniFont.h"
#include <string.h>
#include "../headers/funzioniSchermate.h"

#define N 10
#define M 10

int switchaFigura(int v, int incremento);
int switchaModalita(int m, int incremento);
void mostraBlocchi(int figura, int modalita);
void gestioneUtenti();

int main( int argc, char *argv[]  ){
    //Valori di default per impostazioni
    int raggio = 5;
    char durezza = 6;
    if( argc == 3 ){
      raggio = atoi( argv[1] );
      durezza = atoi( argv[2] );
    }
    else if( argc != 1){
      termina(stderr, "Uso errato del programma. Usare come:\n\tTetris x y\n\tCon:\n\t x = dimensione caratteri\n\t y = simbolo", __FILE__, __LINE__);
    }
    (void)raggio;
    (void)durezza;
    
    stampaSchIniziale();
    



    
    return 0;
}



int switchaFigura(int v, int incremento){
  if(incremento != 0){
    if(v+1 > FIGURES)
      v = 1;
    else v+=1;
  }
  else{
    if( v-1 < 1 )
      v = FIGURES;
    else v -= 1;
  }
  return v;
}

int switchaModalita( int m, int incremento ){
  if(incremento != 0){
    if(m+1 == NUMERO_OPZIONI )
      m = 0;
    else m+=1;
  }
  else{
    if( m-1 < 0 )
      m = NUMERO_OPZIONI-1;
    else m -= 1;
  }
  return m;
}

void mostraBlocchi(int figura, int modalita){
  char tastoPremuto = 10;
    elemento *e = getFigura( figura );
    while( tastoPremuto != 27 ){
      system("cls");
      stampaMatriceBella( NULL, NULL, e->matrice, e->width, e->height, modalita );
      tastoPremuto = toupper( getch() );
      switch( tastoPremuto ){
        case 'D': figura = switchaFigura( figura, 0 ); free(e); e = getFigura(figura); break;
        case 'A': figura = switchaFigura( figura, 1 ); free(e); e = getFigura(figura);break;
        case 'W': modalita = switchaModalita(modalita, 0); break;
        case 'S': modalita = switchaModalita( modalita, 0 ); break;
        case 'Q': e = ruotaAntiOrario( e ); break;
        case 'E': e = ruotaOrario( e ); break;
      }
    }
}


void gestioneUtenti(){
    printf("Prova\n\n");
    int dimensione;
    utente **listaUtenti = caricaUtenti("listaUtenti.txt", &dimensione);
    if(listaUtenti == NULL)
      termina(stdout, "Lista utenti non caricata bene nel main.", __FILE__, __LINE__);
    for(int i = 0; i<dimensione; i++)
      stampaUtente(listaUtenti[i]);
    salvaUtenti("ProvaUtentei2.txt", listaUtenti, dimensione);
    printf("spengo tutto.\n");

}