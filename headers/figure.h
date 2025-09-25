#ifndef FIGURE_H
#define FIGURE_H

#include <stdlib.h>
#include "../headers/elemento.h"
#include "../headers/funzioni.h"

#define FIGURES 7

elemento *getFigura( int n );

elemento *getCubo();
elemento *getCroce();
elemento *getL();
elemento *getReverseL();
elemento *getLong();
elemento *getSnake();
elemento *getReverseSnake();

#endif