#ifndef FUNZIONI_H
#define FUNZIONI_H
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>

//DICHIARAZIONE FUNZIONI
void termina(FILE *output, const char *msg, const char *file, const int pos);
void getConsolePosition(int *posX, int *posY);
int **getMatrice( int w, int h );
void stampaMatrice(int **m,int w, int h);
void distruggiMatrice(int **m, const int RIGHE);
void inizializzaMatrice(int **m, int RIGHE, int COLONNE);
#endif