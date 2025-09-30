#include "../headers/funzioniProgramma.h"



char *getNomeByCodice(int codice){
    char *nome = (char *)malloc(sizeof(char)*40);
    switch( codice ){
        case 0: strcpy(nome, "SCH_INIZIALE"); break;
        case 1: strcpy(nome, "SCH_PRINCIPALE"); break;
        case 2: strcpy(nome, "SCH_ACCESSO"); break;
        case 3: strcpy(nome, "SCH_REGISTRAZIONE"); break;
        case 4: strcpy(nome, "SCH_STATISTICHE"); break;
        case 5: strcpy(nome, "SCH_IMPOSTAZIONI"); break;
        case 6: strcpy(nome, "SCH_PLAY"); break;
        case 7: strcpy(nome, "SCH_PAUSA"); break;
        case 8: strcpy(nome, "SCH_FINE"); break;
        case 9: strcpy(nome, "SCH_RECORD"); break;
        default:
            strcpy(nome, "SCH_ASSENTE");
    }
    return nome;
}


//SCH_INIZIALE, SCH_PRINCIPALE, SCH_ACCESSO, SCH_REGISTRAZIONE, SCH_STATISTICHE, SCH_IMPOSTAZIONI,
//                                SCH_PLAY, SCH_PAUSA, SCH_FINE, SCH_RECORD