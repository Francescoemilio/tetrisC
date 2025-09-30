#ifndef PILA_H
#define PILA_H

#include <stdio.h>
#include <stdlib.h>
#include "funzioni.h"

struct nodo_s{
    int value;
    struct nodo_s *next;
};
typedef struct  nodo_s nodo_P;

struct pila_s{
    nodo_P *head;
};
typedef struct pila_s pila;

nodo_P *getNodo( int value );
void distruggiNoto(nodo_P *nodo);
void stampaNodo( nodo_P *nodo );
pila *getPila();
void pushPila(int value, pila *p);
int popPila( pila *p );
void stampaPila(pila *p);
int pilaVuota(pila *p);


#endif