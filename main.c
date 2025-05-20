#include "functions.h"

int main() {
    srand(time(0)); // Seed the random number generator

    int rounds, p1_total = 0, p2_total = 0;

    printf("Enter the number of rounds: ");
    scanf("%d", &rounds);

    for (int i = 1; i <= rounds; i++) {
        printf("\nROUND %d\n", i);
        printf("--------\n");
        printf("Player points at the start of the round -- P1 = %d P2 = %d\n", p1_total, p2_total);

        // Create champions for each player
        CHAMPION c1 = createChampion();
        int c1_power = getChampionPower(c1);
        CHAMPION c2 = createChampion();
        int c2_power = getChampionPower(c2);

        // Play the round
        playRound(&p1_total, &p2_total, c1, c1_power, c2, c2_power);

        printf("Player points at the end of the round -- P1 = %d P2 = %d\n", p1_total, p2_total);
    }

    // Game Over
    printf("\nGAME OVER!!\n");
    if (p1_total > p2_total) {
        printf("P1 Won! P2 whines: \"I demand a rematch! My TANK was defective!\"\n");
    } else if (p1_total < p2_total) {
        printf("P2 Won! P1 sulks: \"I blame my FIGHTER, must've skipped leg day!\"\n");
    } else {
        printf("It's a tie! Both players shake hands... awkwardly.\n");
    }

    return 0;
}
