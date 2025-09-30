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

static const enum statiDiGioco {SCH_INIZIALE, SCH_PRINCIPALE};


#endif