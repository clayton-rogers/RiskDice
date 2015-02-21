#ifndef _RiskDice
#define _RiskDice
#define _CRT_SECURE_NO_WARNINGS // cause fopen is just fine

#include <cstdio>           // for io
#include <cstdlib>          // for rand()
#include <ctime>            // to seed the random generator
#include "Dice.h"           // dice class

#define _CRT_SECURE_NO_WARNINGS // cause fopen is just fine

void sortDice (Dice dies[], int n); // sorts 'n' dies
double runMonte();


#endif _RiskDice