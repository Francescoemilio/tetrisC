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
    for(int i= 0; i<h; i++)
        for(int j =0; j<w; j++ ){
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
        for(int i = 0; i<e->height; i++){
            for(int j = 0; j<e->width; j++){
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
    else if(modo != NULL && (*modo == 2 || *modo == 3) && posX != NULL && posY != NULL){
        int k = 2;
        for(int i = 0; i<e->height; i++){
          for(int j = 0; j<e->width; j++){
            if(e->matrice[i][j] == 1){

            }
          }
        }
    }
}

void stampaCubo(int posX, int posY, int scelta){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = posX;
    coord.Y = posY;
    SetConsoleCursorPosition(h, coord);
    printf("%c",opzioni[scelta].TSXC);
    for(int i = 0 ; i<4; i++)
        printf("%c",opzioni[scelta].orizzontale);
    printf("%c",opzioni[scelta].TDXC);
    coord.Y ++;
    SetConsoleCursorPosition(h, coord);
    printf("%c",opzioni[scelta].verticale);
    coord.X += 4;
    SetConsoleCursorPosition(h, coord);
    printf("%c",opzioni[scelta].verticale);
    coord.Y ++;
    coord.X = posX;
    SetConsoleCursorPosition(h, coord);
    printf("%c",opzioni[scelta].BSXC);
    for(int i = 0 ; i<4; i++)
        printf("%c",opzioni[scelta].orizzontale);
    printf("%c",opzioni[scelta].BDXC);
}

