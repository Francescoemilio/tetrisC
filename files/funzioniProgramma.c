#include "../headers/funzioniProgramma.h"



char *getNomeByCodice(int codice){
    char *nome = (char *)malloc(sizeof(char)*40);
    switch( codice ){
        case 0: strcpy(nome, "SCH_INIZIALE"); break;
        case 1: strcpy(nome, "SCH_PRINCIPALE"); break;
        case 2: strcpy(nome, "SCH_SCELTA_UTENTE"); break;
        default:
            strcpy(nome, "SCH_ASSENTE");
    }
    return nome;
}