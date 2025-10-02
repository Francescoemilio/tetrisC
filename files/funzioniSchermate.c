#include "../headers/funzioniSchermate.h"


#define NUMERO_COLORI 7
const int colori[NUMERO_COLORI] = {10, 11, 12, 13, 14, 3, 5};

void stampaSchIniziale(){
    srand( time(NULL) );
    //VARIABILI IMPORTANTI
    int widthSchermo = 0, heightSchermo = 0;
    getConsoleGridSize( NULL, &widthSchermo, &heightSchermo );
    int raggioStella = (heightSchermo / 8) * 3;
    const char *titolo = "Tetris";
    const char *scrittaPremi = "Premi un tasto per continuare..";
    int lunghezzaTitolo = strlen(titolo);
    int lunghezzaScrittaPremi = strlen(scrittaPremi);
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
    //Stampo la scritta, adattiva
    int dimensioneScritta = (widthSchermo / 5) * 4;
    int miaVariabile = NUMERO_COLONNE_CARATTERE*lunghezzaTitolo+lunghezzaTitolo;
    int larghezzaCarattere = dimensioneScritta/miaVariabile;
    posX = widthSchermo/5-larghezzaCarattere;
    posY = (heightSchermo/2)-(larghezzaCarattere/2)*3;
    stampaScritta( titolo, &posX, &posY, larghezzaCarattere, colori, NUMERO_COLORI, 4);
    posY += larghezzaCarattere/2*NUMERO_RIGHE_CARATTERE+3;
    posX += (dimensioneScritta-lunghezzaScrittaPremi)/3;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    if(h == INVALID_HANDLE_VALUE)
        termina(stderr, "Handle non valida.", __FILE__, __LINE__);
    COORD coordinate;
    coordinate.X = posX;
    coordinate.Y = posY;
    SetConsoleCursorPosition(h, coordinate);
    SetConsoleTextAttribute(h, 15); 
    printf("%s",scrittaPremi);
    coordinate.X = 0;
    coordinate.Y = 0;
    SetConsoleCursorPosition(h, coordinate);
}

