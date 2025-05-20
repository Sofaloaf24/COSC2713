#include "functions.h"

// Generate a random number between min and max (inclusive)
int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Create a champion with a 33.33% probability for each type
CHAMPION createChampion() {
    int randVal = getRandomNumber(1, 3);
    if (randVal == 1) return MAGE;
    else if (randVal == 2) return FIGHTER;
    else return TANK;
}

// Get champion power based on type
int getChampionPower(CHAMPION c) {
    switch (c) {
        case MAGE: return getRandomNumber(1, 8);
        case FIGHTER: return getRandomNumber(3, 7);
        case TANK: return getRandomNumber(5, 9);
        default: return 0;
    }
}

// Print champion type as a string
void printChampion(CHAMPION c) {
    switch (c) {
        case MAGE: printf("MAGE"); break;
        case FIGHTER: printf("FIGHTER"); break;
        case TANK: printf("TANK"); break;
    }
}

// Play one round of the game based on rules
void playRound(int* p1_total, int* p2_total, CHAMPION c1, int c1_power, CHAMPION c2, int c2_power) {
    printf("P1 : ");
    printChampion(c1);
    printf("-%d vs P2 : ", c1_power);
    printChampion(c2);
    printf("-%d\n", c2_power);

    if (c1 == c2) {
        // Same champion type
        if (c1_power > c2_power) {
            printf("Player 1 (%s) wins and gains their power.\n", c1 == MAGE ? "MAGE" : c1 == FIGHTER ? "FIGHTER" : "TANK");
            *p1_total += c1_power;
            printf("Player 2 loses their power.\n");
            *p2_total -= c2_power;
        } else if (c1_power < c2_power) {
            printf("Player 2 (%s) wins and gains their power.\n", c2 == MAGE ? "MAGE" : c2 == FIGHTER ? "FIGHTER" : "TANK");
            *p2_total += c2_power;
            printf("Player 1 loses their power.\n");
            *p1_total -= c1_power;
        } else {
            printf("It's a tie! Nothing happens.\n");
        }
    } else if (c1 == MAGE && c2 == FIGHTER) {
        if (c1_power > c2_power) {
            printf("Player 1 (MAGE) wins and gains their power.\n");
            *p1_total += c1_power;
        } else {
            printf("Player 2 (FIGHTER) wins, but player 1 loses power.\n");
            *p1_total -= c1_power;
        }
    } else if (c1 == MAGE && c2 == TANK) {
        printf("Player 1 (MAGE) wins and gains their power.\n");
        printf("Player 2 (TANK) loses their power.\n");
        *p1_total += c1_power;
        *p2_total -= c2_power;
    } else if (c1 == FIGHTER && c2 == MAGE) {
        if (c2_power > c1_power) {
            printf("Player 2 (MAGE) wins and gains their power.\n");
            *p2_total += c2_power;
        } else {
            printf("Player 1 (FIGHTER) wins, but player 2 loses power.\n");
            *p2_total -= c2_power;
        }
    } else if (c1 == FIGHTER && c2 == TANK) {
        printf("Player 1 (FIGHTER) wins and gains their power.\n");
        *p1_total += c1_power;
    } else if (c1 == TANK && c2 == MAGE) {
        printf("Player 2 (MAGE) wins and gains their power.\n");
        printf("Player 1 (TANK) loses their power.\n");
        *p2_total += c2_power;
        *p1_total -= c1_power;
    } else if (c1 == TANK && c2 == FIGHTER) {
        printf("Player 2 (FIGHTER) wins and gains their power.\n");
        *p2_total += c2_power;
    } else {
        printf("Nothing happens this round.\n");
    }
}
