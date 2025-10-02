#ifndef FUNZIONI_FONT_H
#define FUNZIONI_FONT_H

#include "../constants/mioFont.h"
#include "funzioni.h"
#include "funzioniGrafiche.h"

void stampaScritta( const char *msg, int *posX, int *posY, int dimensione, const int *colori, int dimColori, int durezza );
void stampaCarattere(const char carattere, int *posX, int *posY, const char simbolo);
void stampaCarattereSizeable(const char carattere, int *posX, int *posY, const char simbolo, int dimensione);

#endif