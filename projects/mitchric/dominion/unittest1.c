#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

void testNumHandCards()
{
    int i, j;
    int randomSeed = 100;
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy};

    for (i = 2; i <= MAX_PLAYERS; ++i) {
        initializeGame(i, k, randomSeed, &G);
        printf("Testing if numHandCards() reports correct individual card total for %d players.\n", i);
        for (j = 1; j <= i; ++j) {
            if (numHandCards(&G) == 5)
                printf("numHandCards(): PASS if total cards in player %d's hand equals 5\n", j);
            else 
                printf("numHandCards(): FAIL if total cards in player %d's hand does not equal 5\n", j);
            endTurn(&G);
        }
    }
}

int main(int argc, char **argv)
{
    testNumHandCards();

    return 0;
}
