#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Enum for Champion Types
typedef enum { MAGE, FIGHTER, TANK } CHAMPION;

// Function Prototypes
int getRandomNumber(int min, int max);
CHAMPION createChampion();
int getChampionPower(CHAMPION c);
void printChampion(CHAMPION c);
void playRound(int* p1_total, int* p2_total, CHAMPION c1, int c1_power, CHAMPION c2, int c2_power);

#endif
