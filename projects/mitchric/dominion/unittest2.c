#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

void testWhoseTurn()
{
    int i, j;
    int randomSeed = 100;
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy};

    for (i = 2; i <= MAX_PLAYERS; ++i) {
        initializeGame(i, k, randomSeed, &G);
        printf("Testing if whoseTurn() reports correct turn index (zero based) for %d players.\n", i);
        for (j = 0; j < i; ++j) {
            if (whoseTurn(&G) == j)
                printf("whoseTurn(): PASS if turn equals player %d\n", j);
            else 
                printf("whoseTurn(): FAIL if turn does not equal %d\n", j);
            endTurn(&G);
        }
    }
}

int main(int argc, char **argv)
{
    testWhoseTurn();

    return 0;
}
