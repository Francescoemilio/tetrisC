#include "../headers/funzioniProgramma.h"

#define POSIZIONE_UTENTI "dati/users.txt"


statoGiocoTetris *setUp(){
    statoGiocoTetris *sgt = (statoGiocoTetris *)malloc( sizeof(statoGiocoTetris) );
    if(sgt == NULL)
        termina(stderr, "Impossibile avviare il gioco.", __FILE__, __LINE__);
    sgt->p = getPila();
    pushPila( SCH_INIZIALE , sgt->p );
    sgt->dimensionePila = 1;
    sgt->listaUtenti = NULL;
    sgt->dimensioneUtenti = 0;
    sgt->versione = (char *)malloc(sizeof(char)*10);
    strcpy( sgt->versione, VERSIONE );
    sgt->utenteLoggato = NULL;
    sgt->utenteIscritto = NULL;
    return sgt;
}
void spegni( statoGiocoTetris *sgt ){ 
    distruggiPila(sgt->p);
    for(int i = 0; i< sgt->dimensioneUtenti; i++){
        distruggiUtente( sgt->listaUtenti[i] );
        free(sgt->listaUtenti);
    }
    free(sgt->versione);
}

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




void gst_schermataIniziale(  ){
    stampaSchIniziale();
    getch();
}


void gst_schermataAccesso( statoGiocoTetris *sgt ){
    sgt -> listaUtenti = caricaUtenti( POSIZIONE_UTENTI, &sgt->dimensioneUtenti );
    if(sgt -> listaUtenti == NULL){
        //Non ci sono utenti, come la gestisco ?
        sgt->utenteLoggato = NULL;
        popPila(sgt->p);
        pushPila(SCH_REGISTRAZIONE, sgt->p);
        return;
    }
}


//SCH_INIZIALE, SCH_PRINCIPALE, SCH_ACCESSO, SCH_REGISTRAZIONE, SCH_STATISTICHE, SCH_IMPOSTAZIONI,
//                                SCH_PLAY, SCH_PAUSA, SCH_FINE, SCH_RECORD