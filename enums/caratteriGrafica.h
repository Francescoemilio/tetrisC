//
// Created by FrancescoEmilioVargi on 23/09/2025.
//

#ifndef CARATTERIGRAFICA_H
#define CARATTERIGRAFICA_H

#endif //CARATTERIGRAFICA_H

struct componenteGrafico{
    int verticale;
    int orizzontale;
    int TSXC;
    int TDXC;
    int BSXC;
    int BDXC;
    int BLANK;
};
typedef struct componenteGrafico grafica;

//const grafica scelta2 = { 179, 196, 218, 191, 192, 217, 32 }; // │ ─ ┌ ┐ └ ┘
/*
xxxxxx
┌────┐y
│    │y
└────┘y
 */
//const grafica scelta3 = { 186, 205, 201, 187, 200, 188, 32 }; //
/*
xxxxxx
╔════╗y
║    ║y
╚════╝y
 */
const int numeroOpzioni = 2;
const grafica opzioni[2] = {
    { 179, 196, 218, 191, 192, 217, 32 },
    { 186, 205, 201, 187, 200, 188, 32 }
    };