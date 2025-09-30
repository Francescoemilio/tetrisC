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
    nodo_P *temp = p->head;
    if( temp->next == NULL ){
        temp->next = nodo;
        return;
    }
    while( temp->next != NULL )
        temp = temp->next;
    temp->next = nodo;
}
int popPila( pila *p ){
    if( pilaVuota(p))
        return 0;
    if( p->head->next == NULL ){
        int rv = p->head->value;
        free(p->head);
        p->head = NULL;
        return rv;
    }
    nodo_P *temp;
    temp = p->head;
    while(temp->next->next != NULL)
        temp = temp->next;
    int rv = temp->next->value;
    free(temp->next);
    temp->next = NULL;
    return rv;
}


void stampaPila(pila *p){
    if(pilaVuota(p)){
        printf("Pila vuota.\n");
        return;
    }
    printf("Pila: { ");
    nodo_P *temp = p->head;
    while(temp != NULL){
        printf("%d",temp->value);
        if(temp->next)
            printf(", ");
        temp = temp->next;
    }
    printf(" }");
}


int pilaVuota(pila *p){
    if(p == NULL)
        termina(stderr, "Pila null.", __FILE__, __LINE__);
    if(p->head == NULL)
        return 1;
    return 0;
}