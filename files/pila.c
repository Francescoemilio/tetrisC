#include "../headers/pila.h"



nodo_P *getNodo( int value ){
    nodo_P *nodo = (nodo_P *)malloc( sizeof(nodo_P) );
    nodo->value = value;
    nodo->next = NULL;
    return nodo;
}
void distruggiNoto(nodo_P *nodo){
    nodo->next = NULL;
    free(nodo);
}
void stampaNodo( nodo_P *nodo ){
    printf("{valore: %d, next: %s }",nodo->value, nodo->next==NULL?"Vuoto":"Pieno");
}

pila *getPila(){
    pila *p = (pila *)malloc(sizeof(pila));
    p->head = NULL;
    return p;
}

void pushPila(int value, pila *p){
    nodo_P *nodo = getNodo( value );
    if( pilaVuota( p ) ){
        p->head = getNodo( value );
        return;
        }
    nodo_P *temp;
}
int popPila( pila *p );


void stampaPila(pila *p);


int pilaVuota(pila *p){
    if(p == NULL)
        termina(stderr, "Pila null.", __FILE__, __LINE__);
    if(p->head == NULL)
        return 1;
    return 0;
}