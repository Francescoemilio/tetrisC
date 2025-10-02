#include "../headers/funzioniFont.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>

void stampaCarattere(const char carattere, int *posX, int *posY, const char simbolo){
    int posArray = tolower( carattere )-97;
    if( posArray < 0 || posArray > 25)
        termina(stderr, "Carattere passato non valido.", __FILE__, __LINE__);
    int coordinateX, coordinateY;
    if( posX != NULL && posY != NULL ){
        coordinateX = *posX;
        coordinateY = *posY;
    }
    else
        getConsolePosition(&coordinateX, &coordinateY);
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = coordinateX;
    coord.Y = coordinateY;
    SetConsoleCursorPosition(h, coord);
    for(int i = 0; i<NUMERO_RIGHE_CARATTERE; i++){
        for(int j = 0; j<NUMERO_COLONNE_CARATTERE; j++){
            if( nuovoFont[posArray][i][j] != ' ' ){
                SetConsoleCursorPosition(h, coord);
                printf("%c%c",simbolo,simbolo);
                }
            coord.X +=2;
        }
        coord.X = coordinateX;
        coord.Y += 1;
    }
}


void stampaScritta( const char *msg, int *posX, int *posY, int dimensione, const int *colori, int dimColori, int durezza ){
    int dimensioneParola = strnlen(msg, 20);
    if( durezza < 0 || durezza > 5 )
        termina(stderr, "Durezza non valida per la stampa della parola. Minimo 0 massimo 5.", __FILE__, __LINE__);
    char simbolo;
    switch(durezza){
        case 5: simbolo = 219; break;
        case 4: simbolo = 178; break;
        case 3: simbolo = 177; break;
        case 2: simbolo = 176; break;
        case 1: simbolo = 221; break;
        case 0: simbolo = 58; break;
        default: simbolo = 219;
    }
    int coordinateX, coordinateY;
    if( posX != NULL && posY != NULL ){
        coordinateX = *posX;
        coordinateY = *posY;
    }
    else
        getConsolePosition(&coordinateX, &coordinateY);
    if( (colori == NULL && dimColori != 0) || (colori != NULL && dimColori < 1))
        termina(stderr, "I colori non corrispondono alla quantita", __FILE__, __LINE__);
    //Inizio a stampare la parola.
    int coloreScelto = 0;
    for(int i = 0; i<dimensioneParola; i++){
        if(dimColori > 0){
            cambiaColore(colori[coloreScelto]);
            coloreScelto += 1;
            if(coloreScelto ==  dimColori )
                coloreScelto = 0;
            }
        stampaCarattereSizeable( msg[i], &coordinateX, &coordinateY, simbolo, dimensione );
        coordinateX += dimensione*NUMERO_COLONNE_CARATTERE + 1;
    }
}



void stampaCarattereSizeable(const char carattere, int *posX, int *posY, const char simbolo, int dimensione){
    int posArray = tolower( carattere )-97;
    if( posArray < 0 || posArray > 25)
        termina(stderr, "Carattere passato non valido.", __FILE__, __LINE__);
    int coordinateX, coordinateY;
    if( posX != NULL && posY != NULL ){
        coordinateX = *posX;
        coordinateY = *posY;
    }
    else
        getConsolePosition(&coordinateX, &coordinateY);
    int xBackUp = coordinateX ; 
    int dimQuadrato = 2;
    if(dimensione > 2)
        dimQuadrato = dimensione%2 == 0 ?dimensione:dimensione-1;
    for(int i = 0; i<NUMERO_RIGHE_CARATTERE; i++){
        for(int j = 0; j<NUMERO_COLONNE_CARATTERE; j++){
            if( nuovoFont[posArray][i][j] != ' ' )
                //Devo stampare un quadrato dimQuadrato*dimQuadrato/2
                stampaQuadrato( &coordinateX, &coordinateY, dimQuadrato, simbolo );
            coordinateX += dimQuadrato;
        }
        coordinateX = xBackUp;
        coordinateY += dimQuadrato / 2;
    }
}
