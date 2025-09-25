//
// Created by FrancescoEmilioVargi on 23/09/2025.
//

#ifndef CARATTERIGRAFICA_H
#define CARATTERIGRAFICA_H
#define NUMERO_OPZIONI 2;


struct componenteGrafico{
    int verticale;
    int orizzontale;
    int TSXC;
    int TDXC;
    int BSXC;
    int BDXC;
    int BLANK;
    int TUP;
    int TRIGHT;
    int TBOTTOM;
    int TLEFT;
    int FULL;
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
const grafica opzioni[2] = {
    { 179, 196, 218, 191, 192, 217, 32, 193, 195, 194, 180, 197 }, // │ ─ ┌ ┐ └ ┘ ' ' ┴ ├ ┬ ┤ ┼
    { 186, 205, 201, 187, 200, 188, 32, 202, 204, 203, 185, 206 }  // ║ ═ ╔ ╗ ╚ ╝ ' ' ╩ ╠ ╦ ╣ ╬ 
    };

    
#endif //CARATTERIGRAFICA_H