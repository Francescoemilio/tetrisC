#include "../headers/utente.h"


//FUNZIONI UTENTE
utente *creaUtenteVuoto(){
    utente *u = (utente *)malloc( sizeof(utente) );
    strcpy(u->nome, "???\0"  );
    u->punteggioMax= 0;
    u->durataMax = 0;
    u->durataMedia = 0;
    u->nPartiteGiocate = 0;
    u->bloccoPreferito = 1;
    for(int i = 0; i<FIGURES; i++)
        u->blocchiVincenti[i] = 0;
    u->coloriGrafica = 15;
    u->modalitaGrafica = 6;
    return u;
}


utente *creaUtente(const char *nome ){
    utente *u = (utente *)malloc( sizeof(utente) );
    int e = snprintf( u->nome, DIMENSIONE_NOMI, "%s", nome );
    if( e < 0 )
        termina(stderr, "Errore con il nome dell utente.", __FILE__, __LINE__);
    u->punteggioMax= 0;
    u->durataMax = 0;
    u->durataMedia = 0;
    u->nPartiteGiocate = 0;
    u->bloccoPreferito = 1;
    for(int i = 0; i<FIGURES; i++)
        u->blocchiVincenti[i] = 0;
    u->coloriGrafica = 15;
    u->modalitaGrafica = 6;
    return u;
}
void distruggiUtente( utente * u ){
    free(u->nome);
    free(u);
}
int salvaUtenti( const char* path, utente **u, const int numeroUtenti ){
    if( path == NULL )
        termina(stderr, "Percorso passato non valido.", __FILE__, __LINE__);
    else if ( u == NULL )
        termina(stderr, "Lista utenti passata non valida.", __FILE__, __LINE__);
    FILE *f = fopen(path, "w");
    if( f == NULL )
        termina(stderr, "Errore apertura file.", __FILE__, __LINE__);
    //ORA INIZIO LA SCRITTURA DEL FILE.
    int numeroUtentiSalvati = 0;
    fprintf(f, "NUMERO UTENTI: %d\n", numeroUtenti);
    for(int i = 0; i<numeroUtenti; i++){
        if(u[i] != NULL){
            fprintf(f, "NOME: %s\n", u[i]->nome);
            fprintf(f, "PUNTEGGIO_MAX: %d\n", u[i]->punteggioMax);
            fprintf(f, "DURATA_MAX: %d\n", u[i]->durataMax);
            fprintf(f, "DURATA_MEDIA: %d\n", u[i]->durataMedia);
            fprintf(f, "PARTITE_GIOCATE: %d\n", u[i]->nPartiteGiocate);
            fprintf(f, "BLOCCO_PREFERITO: %d\n", u[i]->bloccoPreferito);
            fprintf(f, "COLORI_GRAFICA: %d\n", u[i]->coloriGrafica);
            fprintf(f, "MODALITA_GRAFICA: %d\n", u[i]->modalitaGrafica);
            fprintf(f, "BLOCCHI_VINCENTI: [");
            for(int j = 0; j<FIGURES; j++){
                fprintf(f," %d",u[i]->blocchiVincenti[j]);
                if( j < FIGURES-1 )
                    fprintf(f, ",");
            }
            fprintf(f, " ]\n--------------------\n");
            numeroUtentiSalvati += 1;
        }
    }
    fclose(f);
    return numeroUtentiSalvati;
}
utente **caricaUtenti( const char* path, int *dimensione ){
    if(path == NULL || dimensione == NULL)
        return NULL;
    FILE *f = fopen(path, "r");
    if( f == NULL )
        termina( stderr, "Errore apertura file.", __FILE__, __LINE__ );
    int size = 0;
    int e;
    e = fscanf(f, "NUMERO UTENTI: %d\n", &size);
    if(e < 1 )
        termina(stderr, "Errore lettura utenti.", __FILE__, __LINE__);
    *dimensione = size;
    utente **listaUtenti = (utente **)malloc(sizeof(utente *)*size);
    if(listaUtenti == NULL)
        termina(stderr, "Impossibile creare lista utenti.", __FILE__, __LINE__);
    for(int i = 0; i<size; i++){
        listaUtenti[i] = creaUtenteVuoto();
    }
    //Ora l'array è pronto per essere popolato.
    for(int i = 0; i < size; i++){
        e = 0;
        e += fscanf(f, "NOME: %s\n", listaUtenti[i]->nome);
        e += fscanf(f, "PUNTEGGIO_MAX: %d\n", &listaUtenti[i]->punteggioMax);
        e += fscanf(f, "DURATA_MAX: %d\n", &listaUtenti[i]->durataMax);
        e += fscanf(f, "DURATA_MEDIA: %d\n", &listaUtenti[i]->durataMedia);
        e += fscanf(f, "PARTITE_GIOCATE: %d\n", &listaUtenti[i]->nPartiteGiocate);
        e += fscanf(f, "BLOCCO_PREFERITO: %d\n", &listaUtenti[i]->bloccoPreferito);
        e += fscanf(f, "COLORI_GRAFICA: %d\n", &listaUtenti[i]->coloriGrafica);
        e += fscanf(f, "MODALITA_GRAFICA: %d\n", &listaUtenti[i]->modalitaGrafica);
        if(e != 8)
            termina(stderr, "Errore lettura utente", __FILE__, __LINE__);
        fscanf(f, "BLOCCHI_VINCENTI: [");
        e = 0;
        for(int j = 0; j<FIGURES; j++){
            e += fscanf(f, " %d",&listaUtenti[i]->blocchiVincenti[j]);
            if( j < FIGURES-1 )
                fscanf(f, ",");
            }
        if( e != FIGURES )
            termina(stderr, "Errore lettura utente", __FILE__, __LINE__);
        fscanf(f, " ]\n--------------------\n");
        }
    fclose(f);
    return listaUtenti;
}


void distruggiUtenti( utente **lista, const int dimensioneLista ){
    if( lista == NULL || dimensioneLista <= 0 )
        return;
    for(int i = 0; i<dimensioneLista; i++)
        distruggiUtente( lista[i] );
}

void stampaUtente(utente *u){
    if(u == NULL)
        termina(stderr, "Errore stampa utente. Utente null.",__FILE__,__LINE__);
    printf("Utente %s:\n",u->nome);
    printf("\tpunteggio max: %d\n",u->punteggioMax);
    printf("\tdurata media: %d\n",u->durataMedia);
    printf("\tpartite giocate: %d\n",u->nPartiteGiocate);
    printf("\tblocco preferito: %d\t\n\t",u->bloccoPreferito);
    stampaElemento(getFigura(u->bloccoPreferito), &u->modalitaGrafica, NULL, NULL);
    printf("\n\tcolori grafica: %d\n",u->coloriGrafica);
    printf("\tmodalita grafica: %d\n",u->modalitaGrafica);
    printf("\tBlocchi vincenti: [ ");
    for(int i = 0; i<FIGURES; i++){
        printf("%d",u->blocchiVincenti[i]);
        if(i<FIGURES-1)
            printf(", ");
    }
    printf(" ]\n---------------------\n");
}