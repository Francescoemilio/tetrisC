#include "../headers/funzioniGrafiche.h"
#include "../enums/caratteriGrafica.h"
#include <windows.h>
#include <stdio.h>

void stampaMatriceBella( int *posX, int *posY, int **matrice, const int RIGHE, const int COLONNE ){
    const int scelta = 0;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    if( posX != NULL && posY != NULL ){
        coord.X = *posX;
        coord.Y = *posY;
    }
    else {
        coord.X = 1;
        coord.Y = 1;
    }
    SetConsoleCursorPosition(h, coord);
    //Son prponto a fare le stampe
    for(int i = 0; i<RIGHE; i++){
        for(int j = 0; j<COLONNE; j++){
            if( matrice[i][j] == 1 ){
                COORD c;
                c.X = coord.X +1;
                c.Y = coord.Y;
                SetConsoleCursorPosition(h, c);
                printf("%c",opzioni[scelta].orizzontale);
                c.Y ++;
                SetConsoleCursorPosition(h, c);
                printf("%c",opzioni[scelta].orizzontale);
            }
            //stampo gli angoli ora
            //angolo alto destro
            if( i <= 0 || j+1 == COLONNE ){
                //Sono un angolo o un lato, non faccio niente. Ci penserò dopo.
            }
            else{
                COORD c;
                c.X = coord.X;
                c.Y = coord.Y;
                c.X+=2;
                SetConsoleCursorPosition(h, c);
                //Non sono un angolo devo per forza fare qualcosa.
                if( ( matrice[i][j+1] == 1 && matrice[i-1][j] == 1 ) || (matrice[i-1][j+1] == 1) ){
                    //Metto croce
                    if( matrice[i][j] == 0 && matrice[i-1][j+1] == 1 )
                        printf("%c",opzioni[scelta].BSXC);
                    else
                        printf("%c",opzioni[scelta].FULL);
                }
                else if( matrice[i][j+1] == 1 ){
                    //Metto T bassa
                    if( matrice[i][j] == 0 && matrice[i-1][j+1] == 1 )
                        printf("%c",opzioni[scelta].TSXC);
                    else
                        printf("%c",opzioni[scelta].TBOTTOM);
                }
                else if( matrice[i-1][j] == 1 ){
                    //Metto TLEFT
                    if( matrice[i][j] == 0 && matrice[i-1][j+1] == 1 )
                        printf("%c",opzioni[scelta].BDXC);
                    else
                        printf("%c",opzioni[scelta].TLEFT);
                }
                else {
                    //Son solo.
                    if( matrice[i][j] == 0 && matrice[i-1][j+1] == 1 )
                        printf("%c",opzioni[scelta].BLANK);
                    else
                        printf("%c",opzioni[scelta].TDXC);
                }
            }
            coord.X+=3;
        }
        coord.Y += 2;
    }
} 