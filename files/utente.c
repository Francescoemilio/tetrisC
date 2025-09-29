#include "../headers/utente.h"


//FUNZIONI UTENTE
utente *creaUtenteVuoto(){
    utente *u = (utente *)malloc( sizeof(utente) );
    strcpy(u->nome, "???"  );
    u->punteggioMax= 0;
    u->durataMax = 0;
    u->durataMedia = 0;
    u->nPartiteGiocate = 0;
    u->bloccoPreferito = 0;
    for(int i = 0; i<FIGURES; i++)
        u->blocchiVincenti[i] = 0;
    u->coloriGrafica = 15;
    u->modalitaGrafica = 1;
    return u;
}


utente *creaUtente(const char *nome ){
    utente *u = (utente *)malloc( sizeof(utente) );
    u->nome = (char *)malloc( sizeof(char) * strlen(nome)+1 );
    strcpy(u->nome, nome );
    u->punteggioMax= 0;
    u->durataMax = 0;
    u->durataMedia = 0;
    u->nPartiteGiocate = 0;
    u->bloccoPreferito = 0;
    for(int i = 0; i<FIGURES; i++)
        u->blocchiVincenti[i] = 0;
    u->coloriGrafica = 15;
    u->modalitaGrafica = 1;
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
            fprintf(f, "DURATA_MEDIA: %d\n", u[i]->nome);
            fprintf(f, "PARTITE_GIOCATE: %d\n", u[i]->nome);
            fprintf(f, "BLOCCO_PREFERITO: %d\n", u[i]->nome);
            fprintf(f, "COLORI_GRAFICA: %d\n", u[i]->nome);
            fprintf(f, "MODALITA_GRAFICA: %d\n", u[i]->nome);
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
    fclose(f);
}


void distruggiUtenti( utente **lista, const int dimensioneLista ){
    if( lista == NULL || dimensioneLista <= 0 )
        return;
    for(int i = 0; i<dimensioneLista; i++)
        distruggiUtente( lista[i] );
}