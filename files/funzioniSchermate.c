#include "../headers/funzioniSchermate.h"


#define NUMERO_COLORI 7
const int colori[NUMERO_COLORI] = {10, 11, 12, 13, 14, 3, 5};

void stampaSchIniziale(){
    srand( time(NULL) );
    //VARIABILI IMPORTANTI
    int widthSchermo = 0, heightSchermo = 0;
    getConsoleGridSize( NULL, &widthSchermo, &heightSchermo );
    int raggioStella = (heightSchermo / 8) * 3;

    system("cls");
    //Stampo le stelle.
    int posX = 0, posY = 0;
    cambiaColore( colori[rand()%NUMERO_COLORI] );
    stampaStella( &posX, &posY, raggioStella );
    posX = widthSchermo-(raggioStella*4);
    cambiaColore( colori[rand()%NUMERO_COLORI] );
    stampaStella( &posX, &posY, raggioStella );
    posX = (widthSchermo/3)-1;
    posY = heightSchermo/4;
    cambiaColore( colori[rand()%NUMERO_COLORI] );
    stampaStella( &posX, &posY, raggioStella );
}