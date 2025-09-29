#include "../headers/funzioniGrafiche.h"


//Funzioni solo per questo file e che non devono essere utilizzate in altri file:
static void calcolaAngoli(int **m, const int RIGHE, const int COLONNE);
static void inserimentoLati(int **m, const int RIGHE, const int COLONNE);
static void inserimentoAngoli(int **m, const int RIGHE, const int COLONNE);
static void stampaMatriceTradotta(int **m, const int RIGHE, const int COLONNE, const int *posX, const int *posY, const int scelta);

void stampaCubo3x3(int posX, int posY, int scelta){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = posX;
    coord.Y = posY;
    SetConsoleCursorPosition(h, coord);
    printf("%c",opzioni[scelta].TSXC);
    for(int i = 0 ; i<4; i++)
        printf("%c",opzioni[scelta].orizzontale);
    printf("%c",opzioni[scelta].TDXC);
    coord.Y ++;
    SetConsoleCursorPosition(h, coord);
    printf("%c",opzioni[scelta].verticale);
    coord.X += 5;
    SetConsoleCursorPosition(h, coord);
    printf("%c",opzioni[scelta].verticale);
    coord.Y ++;
    coord.X = posX;
    SetConsoleCursorPosition(h, coord);
    printf("%c",opzioni[scelta].BSXC);
    for(int i = 0 ; i<4; i++)
        printf("%c",opzioni[scelta].orizzontale);
    printf("%c",opzioni[scelta].BDXC);
}


void stampaCubo2x2(int posX, int posY, int scelta){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = posX;
    coord.Y = posY;
    SetConsoleCursorPosition(h, coord);
    printf("%c%c%c",opzioni[scelta].TSXC, opzioni[scelta].orizzontale, opzioni[scelta].TDXC);
    coord.Y++;
    SetConsoleCursorPosition(h, coord);
    printf("%c%c%c",opzioni[scelta].BSXC, opzioni[scelta].orizzontale, opzioni[scelta].BDXC);
}

void stampaMatriceBella2( int *posX, int *posY, int **matrice, const int RIGHE, const int COLONNE ){
    const int scelta = 2;
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
    int coordTempX = coord.X;
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
                        printf("%c",opzioni[scelta].TDXC);
                    else
                        printf("%c",opzioni[scelta].BLANK);
                }
            }
            coord.X+=2;
        }
        coord.X = coordTempX;
        coord.Y += 1;
    }
}


void stampaMatriceBella3( int *posX, int *posY, int **matrice, const int RIGHE, const int COLONNE ){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coordinate;
    coordinate.X = 1;
    coordinate.Y = 1;
    if( posX != NULL && posY != NULL ){
        coordinate.X = *posX;
        coordinate.Y = *posY;
    }
    SetConsoleCursorPosition(h, coordinate);
    COORD coordTemp;
    coordTemp.X = coordinate.X;
    coordTemp.Y = coordinate.Y;
    for( int i = 0; i<RIGHE; i++ ){
        for( int j = 0; j<COLONNE; j++ ){
            if( matrice[i][j] == 1 ){
                stampaCubo2x2(coordTemp.X, coordTemp.Y, 0);
            }
            coordTemp.X += 2;
        }
        coordTemp.X = coordinate.X;
        coordTemp.Y += 1;
    }

}





void stampaMatriceBella( int *posX, int *posY, int **matrice, const int RIGHE, const int COLONNE, const int scelta){
    /*
    Prima di tutto trasformo la matrice base nella matrice Tradotta, ovvero una
    matrice piu grande in cui in ogni cella ci sarà un valore corrispondente al carattere da trascrivere
    */
    int nuoveRighe = RIGHE+1;
    int nuoveColonne = COLONNE*2+1;
    int **matriceTradotta = getMatrice( nuoveRighe, nuoveColonne );
    inizializzaMatrice( matriceTradotta, nuoveRighe, nuoveColonne );
    int contRighe = 0;
    int contColonne = 0;
    for( int i = 0; i<nuoveRighe-1; i++ ){
        for(int j = 1; j<nuoveColonne; j+=2){
            if(matrice[contRighe][contColonne] == 1 )
                matriceTradotta[i][j] = 'B';
            contColonne += 1;
        }
        contRighe += 1;
        contColonne = 0;
    }
    //La matrice tradotta è stata riempita con i valori presi dall matrice base, ora bisogna calcolare gli angoli.
    //Per farlo preferirei avere una funzione esterna.
    calcolaAngoli( matriceTradotta, nuoveRighe, nuoveColonne );
    //stampaMatrice( matriceTradotta, nuoveRighe, nuoveColonne );
    
    stampaMatriceTradotta( matriceTradotta, nuoveRighe, nuoveColonne, posX, posY, scelta);
}

static void calcolaAngoli(int **m, const int RIGHE, const int COLONNE){
    //Per come è fatta la matrice non devo fare controlli sui lati, rischiando di uscire fuori dalla matrice.
    //Appunto per questo la funzione non è "pubblica", bensì è e rimarrà una funzione di supporto.
    //FOR PER INSERIRE I VALORI AI LATI E IN BASSO
    inserimentoLati( m, RIGHE, COLONNE );
    inserimentoAngoli( m, RIGHE, COLONNE );
}


static void inserimentoLati(int **m, const int RIGHE, const int COLONNE){
    for(int i = 0; i<RIGHE; i++){
        for(int j = 1; j<COLONNE; j+=2){
            if( m[i][j] == 'B' ){
                //Lato sinistro (1)
                if( m[i][j-1] == 0  ) m[i][j-1] = 1;
                else if( m[i][j-1] == 2  ) m[i][j-1] = 20;
                //Lato destro (2)
                if( m[i][j+1] == 0 ) m[i][j+1] = 2;
                //In basso (3)
                if( m[i+1][j] == 0 ) m[i+1][j] = 3;
            }
        }
    }
    //Lati compilati.
}

static void inserimentoAngoli(int **m, const int RIGHE, const int COLONNE){
    for(int i = 0; i<RIGHE; i++){
        for(int j = 1; j<COLONNE; j+=2){
            if( m[i][j] == 'B' ){
                //Angolo basso sinistro (4)
                switch( m[i+1][j-1] ){
                    case 0: m[i+1][j-1] = 4; break;
                    case 1: m[i+1][j-1] =30; break;
                    case 2: m[i+1][j-1] = 40; break;
                    case 5: m[i+1][j-1] = 60; break;
                    case 20: m[i+1][j-1] = 100; break;
                    case 30: m[i+1][j-1] = 100; break;
                    case 40: m[i+1][j-1] = 100; break;
                }
                //Angolo basso destro (5)
                switch( m[i+1][j+1] ){
                    case 0: m[i+1][j+1] = 5; break;
                    case 1: m[i+1][j+1] = 100; break;
                    case 2: m[i+1][j+1] = 40; break;
                    case 4: m[i+1][j+1] = 60; break;
                    case 20: m[i+1][j+1] = 100; break;
                    case 30: m[i+1][j+1] = 100; break;
                    case 40: m[i+1][j+1] = 100; break;
                }
            }
        }
    }
    //Angoli compilati.
}
/*#TABELLA DELLE SCELTE E DELLE CONVERSIONE DEGLI ANGOLI
* Mettendo 1 a sinistra
*  se trovo un 2 allora inserisco 20 al posto dell'1
* ANGOLI BASSI
* Mettendo in basso a sinistra un 4.
*  se libero 4
*  se trovo 1 metto 30
*  se trovo 2 metto 40
*  se trovo 5 metto 60
*  se trovo 20/30/40 metto 100
* Mettendo in basso a destra un 5. 
*  se libero 5
*  se trovo 2 metto 40
*  se trovo 4 metto 60
*  se trovo 1 metto 100
*  se trovo 20/30/40 metto 100
*/

static void stampaMatriceTradotta(int **m, const int RIGHE, const int COLONNE, const int *posX, const int *posY, const int scelta){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    if( h == INVALID_HANDLE_VALUE )
        termina(stderr, "Handle della console non valido.", __FILE__, __LINE__);
    COORD coordinate;
    int coord_temp_X, coord_temp_Y;
    getConsolePosition( &coord_temp_X, &coord_temp_Y );
    coordinate.X = coord_temp_X, coordinate.Y = coord_temp_Y;
    if( posX != NULL && posY != NULL ){
        coordinate.X = *posX;
        coordinate.Y = *posY;
    }
    int temp = coordinate.X;
    SetConsoleCursorPosition(h, coordinate);
    for(int i = 0; i<RIGHE; i++){
        for(int j = 0; j<COLONNE; j++){
            if( m[i][j] != 0 ){ 
                SetConsoleCursorPosition(h, coordinate);
                switch( m[i][j] ){
                    case 1: printf("%c",opzioni[scelta].TSXC); break;
                    case 2: printf("%c",opzioni[scelta].TDXC); break;
                    case 3: printf("%c",opzioni[scelta].orizzontale); break;
                    case 4: printf("%c",opzioni[scelta].BSXC); break;
                    case 5: printf("%c",opzioni[scelta].BDXC); break;
                    case 20: printf("%c",opzioni[scelta].TBOTTOM); break;
                    case 30: printf("%c",opzioni[scelta].TRIGHT); break;
                    case 40: printf("%c",opzioni[scelta].TLEFT); break;
                    case 60: printf("%c",opzioni[scelta].TUP); break;
                    case 100: printf("%c",opzioni[scelta].FULL); break;
                    case 'B': printf("%c",opzioni[scelta].orizzontale); break;
                }
            }
            coordinate.X += 1;
        }
        coordinate.Y += 1;
        coordinate.X = temp;
    }
}