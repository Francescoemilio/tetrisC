#include <stdlib.h>
#include <stdio.h>

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