#include "../headers/figure.h"


elemento *getFigura( int n ){
    if( n > FIGURES || n < 1)
        termina(stderr, "Valore figura non valido.", __FILE__, __LINE__);
    switch( n ){
        case 1: return getCubo();  break;
        case 2: return getCroce(); break;
        case 3: return getL();  break;
        case 4: return getReverseL(); break;
        case 5: return getLong();  break;
        case 6: return getSnake(); break;
        case 7: return getReverseSnake();  break;
        default: return getCubo(); break;
    }
}

//FUNZIONI PER OTTENRE LE FIGURE INDIETRO

elemento *getCubo(){
    int dimensione = 4, larghezza = 2, altezza = 2;
    int **matriceElemento = getMatrice(larghezza, altezza);
    matriceElemento[0][0] = 1;
    matriceElemento[0][1] = 1;
    matriceElemento[1][0] = 1;
    matriceElemento[1][1] = 1;
    elemento *e = creaElemento(larghezza, altezza, matriceElemento, dimensione);
    return e;
}

elemento *getCroce(){
    int dimensione = 4, larghezza = 2, altezza = 3;
    int **matriceElemento = getMatrice(larghezza, altezza);
    matriceElemento[0][0] = 0;
    matriceElemento[1][0] = 1;
    matriceElemento[0][1] = 1;
    matriceElemento[1][1] = 1;
    matriceElemento[0][2] = 0;
    matriceElemento[1][2] = 1;
    elemento *e = creaElemento(larghezza, altezza, matriceElemento, dimensione);
    return  e;
}

elemento *getL(){
    int dimensione = 4, larghezza = 3, altezza = 2;
    int **matriceElemento = getMatrice(larghezza, altezza);
    matriceElemento[0][0] = 1;
    matriceElemento[1][0] = 1;
    matriceElemento[2][0] = 1;
    matriceElemento[0][1] = 0;
    matriceElemento[1][1] = 0;
    matriceElemento[2][1] = 1;
    elemento *e = creaElemento(larghezza, altezza, matriceElemento, dimensione);
    return  e;
}

elemento *getReverseL(){
    int dimensione = 4, larghezza = 3, altezza = 2;
    int **matriceElemento = getMatrice(larghezza, altezza);
    matriceElemento[0][0] = 0;
    matriceElemento[1][0] = 0;
    matriceElemento[2][0] = 1;
    matriceElemento[0][1] = 1;
    matriceElemento[1][1] = 1;
    matriceElemento[2][1] = 1;
    elemento *e = creaElemento(larghezza, altezza, matriceElemento, dimensione);
    return  e;
}

elemento *getLong(){
    int dimensione = 4, larghezza = 4, altezza = 1;
    int **matriceElemento = getMatrice(larghezza, altezza);
    matriceElemento[0][0] = 1;
    matriceElemento[1][0] = 1;
    matriceElemento[2][0] = 1;
    matriceElemento[3][0] = 1;
    elemento *e = creaElemento(larghezza, altezza, matriceElemento, dimensione);
    return  e;
}

elemento *getSnake(){
    int dimensione = 4, larghezza = 2, altezza = 3;
    int **matriceElemento = getMatrice(larghezza, altezza);
    matriceElemento[0][0] = 0;
    matriceElemento[0][1] = 1;
    matriceElemento[0][2] = 1;
    matriceElemento[1][0] = 1;
    matriceElemento[1][1] = 1;
    matriceElemento[1][2] = 0;
    elemento *e = creaElemento(larghezza, altezza, matriceElemento, dimensione);
    return  e;
}

elemento *getReverseSnake(){
    int dimensione = 4, larghezza = 2, altezza = 3;
    int **matriceElemento = getMatrice(larghezza, altezza);
    matriceElemento[0][0] = 1;
    matriceElemento[0][1] = 1;
    matriceElemento[0][2] = 0;
    matriceElemento[1][0] = 0;
    matriceElemento[1][1] = 1;
    matriceElemento[1][2] = 1;
    elemento *e = creaElemento(larghezza, altezza, matriceElemento, dimensione);
    return  e;
}