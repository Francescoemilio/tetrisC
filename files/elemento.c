#include "../headers/elemento.h"

elemento *creaElementoVuoto(){
    elemento *e = (elemento *) malloc(sizeof(elemento));
    e->height = 0;
    e->width = 0;
    e->dimensione = 0;
    e->listaBlocchi = NULL;
    e->matrice = NULL;
    return e;
}
elemento *creaElemento(int w, int h, int **m, int dim){
    elemento *e = (elemento *) malloc(sizeof(elemento));
    e->height = h;
    e->width = w;
    e->dimensione = dim;
    e->matrice = (int **)malloc(sizeof(int)*w);
    for(int i = 0; i<w; i++){
      e->matrice[i] = (int *)malloc(sizeof(int)*h);
    }
    e->listaBlocchi =  (blocco **)malloc(sizeof(blocco)*dim);
    int cont = 0;
    for(int i= 0; i<w; i++)
        for(int j =0; j<h; j++ ){
            e->matrice[i][j] = m[i][j];
            if(m[i][j] == 1 && cont < dim){
                e->listaBlocchi[cont] = creaBloccoByPos(i, j);
                cont ++;
            }
        }
    return e;
}
void distruggiElemento( elemento *e ){
    //Libero la lista dei blocchi
    for(int cont = 0; cont<e->dimensione; cont ++){
        free(e->listaBlocchi[cont]);
    }
    free(e->listaBlocchi);
    //Libero la matrice
    free(e->matrice);
    //Libero il blocco
    free(e);
}

void stampaElemento( elemento *e, int *modo, int *posX, int *posY){
    if(modo == NULL || *modo == 1){
        printf("Elemento: {dimensione: %d, larghezza: %d, altezza: %d}\n",e->dimensione, e->width, e->height);
        printf("Matrice:\n\t");
        for(int i = 0; i<e->width; i++){
            for(int j = 0; j<e->height; j++){
                if(e->matrice[i][j]==0)
                    printf(" ");
                else if(e->matrice[i][j]==1)
                    printf("#");
            }
            printf("\n\t");
        }
        printf("Lista blocchi:\n");
        for(int cont = 0; cont < e->dimensione ; cont ++){
            printf("\t");
            stampaBlocco( e->listaBlocchi[cont] );
        }
    }
    else if(modo != NULL && (*modo == 2 || *modo == 3)){
        int coordinataX;
        int coordinataY;
        if( posX != NULL && posY != NULL ){
            coordinataX = *posX;
            coordinataY = *posY;
        }
        else{
            getConsolePosition( &coordinataX, &coordinataY );
        }

        int k = 2;
        for(int i = 0; i<e->width; i++){
          for(int j = 0; j<e->height; j++){
            if(e->matrice[i][j] == 1){
                stampaCubo3x3( coordinataX+j*6, coordinataY+i*3 ,*modo-k );
            }
          }
        }
    }
    else if(modo != NULL && (*modo == 4 || *modo == 5)){
        int coordinataX;
        int coordinataY;
        if( posX != NULL && posY != NULL ){
            coordinataX = *posX;
            coordinataY = *posY;
        }
        else{
            getConsolePosition( &coordinataX, &coordinataY );
        }
        int k = 4;
        for(int i = 0; i<e->width; i++){
          for(int j = 0; j<e->height; j++){
            if(e->matrice[i][j] == 1){
                stampaCubo2x2( coordinataX+j*3, coordinataY+i*2 ,*modo-k );
            }
          }
        }
    }
    else if( modo != NULL && *modo == 6){
        stampaMatriceBella(NULL, NULL, e->matrice, e->width, e->height, 0);
    }
    else {
        printf("Hai passato un valore non valido.\n");
    }
}




elemento *ruotaOrario( elemento *e ){
    int nuovaDimensione = e->dimensione, nuovaLarghezza = e->height, nuovaAltezza = e->width;
    int **matriceNuova = getMatrice( nuovaLarghezza, nuovaAltezza );
    for(int i = 0; i<e->width; i++)
        for(int j = 0; j<e->height; j++)
            matriceNuova[j][e->width-1-i] = e->matrice[i][j];
    elemento *nuovoElemento = creaElemento( nuovaLarghezza, nuovaAltezza, matriceNuova, nuovaDimensione );
    distruggiElemento(e);
    return nuovoElemento;
}


elemento *ruotaAntiOrario( elemento *e ){
    int nuovaDimensione = e->dimensione, nuovaLarghezza = e->height, nuovaAltezza = e->width;
    int **matriceNuova = getMatrice( nuovaLarghezza, nuovaAltezza );
    for(int i = 0; i<e->width; i++)
        for(int j = 0; j<e->height; j++)
            matriceNuova[e->height-1-j][i] = e->matrice[i][j];
    elemento *nuovoElemento = creaElemento( nuovaLarghezza, nuovaAltezza, matriceNuova, nuovaDimensione );
    distruggiElemento(e);
    return nuovoElemento;
}