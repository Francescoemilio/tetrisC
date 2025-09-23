#include <stdlib.h>
#include <stdio.h>
#include "blocco.h"
#include <windows.h>
#include "../enums/caratteriGrafica.h"

struct elemento_s{
    int height;
    int width;
    int **matrice;
    int dimensione;
    blocco **listaBlocchi;
};

typedef struct elemento_s elemento;


elemento *creaElementoVuoto();
elemento *creaElemento(int w, int h, int **m, int dim);
void distruggiElemento( elemento *e );
void stampaElemento( elemento *e, int *modo, int *posX, int *posY);
void stampaCubo(int posX, int posY, int scelta);