#ifndef UTENTE_H
#define UTENTE_H

#include "figure.h"
#include "funzioni.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define DIMENSIONE_NOMI 20

struct utente_s{
    char nome[DIMENSIONE_NOMI +1];
    int punteggioMax;
    int durataMax;
    int durataMedia;
    int nPartiteGiocate;
    int bloccoPreferito;
    int blocchiVincenti[FIGURES];
    int coloriGrafica;
    int modalitaGrafica;
};
typedef struct utente_s utente;

//FUNZIONI UTENTE
utente *creaUtenteVuoto();
utente *creaUtente(const char *nome );
void distruggiUtente( utente * u );
void salvaUtente( const char* path, utente *u );
int salvaUtenti( const char* path, utente **u, const int numeroUtenti  );
utente **caricaUtenti( const char* path, int *dimensione );
void distruggiUtenti( utente **lista, const int dimensioneLista );
#endif