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

#define SCH_INIZIALE = 0;
#define SCH_PRINCIPALE = 1;
#define SCH_ACCESSO = 2;
#define SCH_REGISTRAZIONE = 3;
#define SCH_STATISTICHE = 4;
#define SCH_IMPOSTAZIONI = 5;
#define SCH_PLAY = 6;
#define SCH_PAUSA = 7;
#define SCH_FINE = 8;
#define SCH_RECORD = 9;

#endif