#include "../headers/funzioni.h"



//FUNZIONI

void termina(FILE *output, const char *msg, const char *file, const int pos){
    if(output == NULL){
        fprintf(stderr, "Errore: In %s Pos %d\n\t%s\n",file, pos, msg);
        exit(-1);
        }
    else {
        fprintf(output, "Errore: In %s Pos %d\n\t%s\n",file, pos, msg);
        exit(-1);
        }
}


void getConsolePosition(int *posX, int *posY){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    if(h == INVALID_HANDLE_VALUE)
        termina(stderr, "Impossibile ottenere i dati della console corretti.", __FILE__, __LINE__);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if( GetConsoleScreenBufferInfo(h, &csbi) ){
        *posX = csbi.dwCursorPosition.X;
        *posY = csbi.dwCursorPosition.Y;
    }
    else{
        termina(stderr, "Impossibile leggere le coordinate della console.", __FILE__, __LINE__);
    }
}


int **getMatrice( int w, int h ){
    int **matriceElemento = (int **)malloc(sizeof(int *)*w);
    if( matriceElemento == NULL )
        termina(stderr, "Impossibile costruire la matrice.", __FILE__, __LINE__);
    for(int i = 0; i<w; i++){
      matriceElemento[i] = (int *)malloc(sizeof(int)*h);
        if( matriceElemento[i] == NULL )
            termina(stderr, "Impossibile costruire la matrice.", __FILE__, __LINE__);
    }
    return matriceElemento;
}


void stampaMatrice(int **m, int w, int h){
    for(int i= 0; i<w; i++){
      for(int j= 0; j<h; j++){
        printf("%3d ",m[i][j]);
      }
      printf("\n");
    }
}

void distruggiMatrice(int **m, const int RIGHE){
    for(int i= 0; i<RIGHE; i++){
        free(m[i]);
      }
    free(m);
}


void inizializzaMatrice(int **m, int RIGHE, int COLONNE){
    for(int i = 0; i<RIGHE; i++){
        for(int j = 0; j<COLONNE; j++)
            m[i][j] = 0;
    }   
}