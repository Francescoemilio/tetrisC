#ifndef FUNZIONI_PROGRAMMAA_H
#define FUNZIONI_PROGRAMMA_H
#define VERSIONE "1.15"

#include "../enums/statiDiGioco.h"
#include "pila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funzioniSchermate.h"
#include "utente.h"

struct gioco_s {
    pila *p;
    utente **listaUtenti;
    int dimensionePila;
    int dimensioneUtenti;
    char *versione;
    utente *utenteLoggato;
    utente *utenteIscritto;

};
typedef struct gioco_s statoGiocoTetris;

char *getNomeByCodice(int codice);
void gst_schermataIniziale( );
void gst_schermataAccesso( statoGiocoTetris *sgt  );
statoGiocoTetris *setUp();
void spegni( statoGiocoTetris *sgt );




#endif