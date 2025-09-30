#ifndef STATIDIGIOCO_H
#define STATDIGIOCO_H

#define DIM_NOME_STATO_GIOCO 40
/*
struct statoDiGioco_s {
    int codice;
    char nomeStato[DIM_NOME_STATO_GIOCO];
};
typedef struct statoDiGioco_s statoDiGioco;

static const statoDiGioco statiDiGioco[1] = {
    {1, "SCHERMATA_INIZIALE"}
};*/

const int SCH_INIZIALE = 0;
const int SCH_PRINCIPALE = 1;
const int SCH_ACCESSO = 2;
const int SCH_REGISTRAZIONE = 3;
const int SCH_STATISTICHE = 4;
const int SCH_IMPOSTAZIONI = 5;
const int SCH_PLAY = 6;
const int SCH_PAUSA = 7;
const int SCH_FINE = 8;
const int SCH_RECORD = 9;
#endif