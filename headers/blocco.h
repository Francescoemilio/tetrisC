#ifndef BLOCCO_H
#define BLOCCO_H


#include <stdlib.h>
#include <stdio.h>

struct blocco_s{
    int posX;
    int posY;
};
typedef struct blocco_s blocco;

//DICHIARAZIONE FUNZIONI
blocco* creaBlocco();
blocco* creaBloccoByPos(int x, int y);
void stampaBlocco(blocco *b);
void distruggiBlocco(blocco *b);
int confrontaAltezzaBlocco(blocco *b1, blocco *b2);

#endif