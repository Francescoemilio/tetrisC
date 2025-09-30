#ifndef FUNZIONI_GRAFICHE_H
#define FUNZIONI_GRAFICHE_H
#include <windows.h>
#include <stdio.h>
#include "../headers/funzioni.h"
#include "../enums/caratteriGrafica.h"

void stampaMatriceBella( int *posX, int *posY, int **matrice, const int RIGHE, const int COLONNE, const int scelta);
void stampaMatriceBella2( int *posX, int *posY, int **matrice, const int RIGHE, const int COLONNE );
void stampaMatriceBella3( int *posX, int *posY, int **matrice, const int RIGHE, const int COLONNE );
void stampaCubo2x2(int posX, int posY, int scelta);
void stampaCubo3x3(int posX, int posY, int scelta);
void stampaQuadrato(int *posX, int *posY, int lato, char carattere);
void cambiaColore(int colore);

#endif