#include <stdio.h>
#include <stdlib.h>
#include "../headers/funzioni.h"
#include "../headers/elemento.h"


int main( int argc, char *argv[]  ){
    
    int dimensione = 4, larghezza = 3, altezza = 2;
    int **matriceElemento = (int **)malloc(sizeof(int *)*larghezza);
    for(int i = 0; i<larghezza; i++){
      matriceElemento[i] = (int *)malloc(sizeof(int)*altezza);
    }
    matriceElemento[0][0] = 0;
    matriceElemento[0][1] = 1;
    matriceElemento[0][2] = 0;
    matriceElemento[1][0] = 1;
    matriceElemento[1][1] = 1;
    matriceElemento[1][2] = 1;
    for(int i= 0; i<altezza; i++){
      for(int j= 0; j<larghezza; j++){
        printf("%d ",matriceElemento[i][j]);
      }
      printf("\n");
    }

    elemento *e = creaElemento(larghezza, altezza, matriceElemento, dimensione);
    stampaElemento(e, NULL);
    distruggiElemento(e);

    return 0;
}
