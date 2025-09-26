#include "../headers/blocco.h"




//FUNZIONI
blocco* creaBlocco(){
    blocco* b = (blocco *) malloc(sizeof(blocco)*1);
    b->posX = 0;
    b->posY = 0;
    return b;
}
blocco* creaBloccoByPos(int x, int y){
    blocco* b = (blocco *) malloc(sizeof(blocco)*1);
    b->posX = x;
    b->posY = y;
    return b;
}

void stampaBlocco(blocco *b){
    printf("Blocco{ x:%d, y:%d}\n",b->posX, b->posY);
}

void distruggiBlocco(blocco *b){
    free(b);
}

int confrontaAltezzaBlocco(blocco *b1, blocco *b2){
    if(b1->posY == b2->posY)
        return 0;
    if(b1->posY > b2->posY)
        return 1;
    else return -1;
}