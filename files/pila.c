#include "../headers/pila.h"

//FUNZIONI
void distruggiPilaRic(nodo_P *p);

nodo_P *getNodo( int value ){
    nodo_P *nodo = (nodo_P *)malloc( sizeof(nodo_P) );
    nodo->value = value;
    nodo->next = NULL;
    return nodo;
}
void distruggiNodo(nodo_P *nodo){ 
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
    //nodo_P *temp;
    if(pilaVuota(p)){
        p-> head = nodo;
        return;
    }
    else{
        nodo -> next = p -> head;
        p -> head = nodo;
    }
}
int popPila( pila *p ){
    if( pilaVuota(p))
        return 0;
    nodo_P *temp = p->head;
    p->head = p->head->next;
    int rv = temp->value;
    distruggiNodo(temp);
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
    if(p == NULL || p->head == NULL)
        return 1;
    return 0;
}

void distruggiPila(pila *p){
    if(p == NULL)
        return;
    if( p->head == NULL)
        free(p);
    else{
        nodo_P *temp;
        temp = p->head;
        while(p->head != NULL){
            distruggiNodo(temp);
            temp = p->head;
            p->head = p->head->next;
        }
    }
}

void distruggiPilaRic(nodo_P *p){
    if(p->next == NULL){
        distruggiNodo(p);
    }
    else{
        distruggiPilaRic(p->next);
        distruggiNodo(p);
    }
}