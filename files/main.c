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

#define N 10
#define M 10

int switchaFigura(int v, int incremento);
int switchaModalita(int m, int incremento);
void mostraBlocchi(int figura, int modalita);
void gestioneUtenti();

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
    (void)figura;
    (void)modalita;

    
    
    pila *p = getPila();
    
    
    stampaPila(p);
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

void bullshits(){
  /*
  int mpr = N, mpc = M;
    
    int valori[N][M] = {
        {0, 0, 0, 1, 1, 0, 1, 0, 0, 1},
        {0, 1, 1, 1, 0, 1, 0, 0, 1, 0},
        {1, 0, 0, 1, 1, 0, 1, 1, 0, 0},
        {1, 1, 0, 0, 1, 1, 0, 0, 1, 1},
        {0, 1, 0, 1, 0, 0, 1, 0, 1, 0},
        {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
        {0, 0, 1, 1, 0, 1, 1, 0, 0, 1},
        {1, 1, 0, 0, 1, 0, 0, 1, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 0}
    };

    int valori[N][M] = {
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
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

    stampaMatriceBella( NULL , NULL, matrice, mpr, mpc, modalita);

    
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