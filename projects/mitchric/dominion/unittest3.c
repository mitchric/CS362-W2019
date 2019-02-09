#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

void testEndTurn()
{
    int i;
    int numOfPlayers = 2;
    int randomSeed = 100;
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy};

    initializeGame(numOfPlayers, k, randomSeed, &G);

    for (i = 0; i < numOfPlayers; ++i) {
        endTurn(&G);
        if (i == G.whoseTurn - 1) {
            if (G.whoseTurn == i + 1) 
                printf("endTurn(): PASS if player %d finished their turn. It's now player %d's turn.\n", i, i + 1);
            else 
                printf("endTurn(): FAIL if player %d did not finish their turn and it's not player %d's turn.\n", i, i + 1);
        } else if (i == G.whoseTurn + 1) {
            if (G.whoseTurn == i - 1)
                printf("endTurn(): PASS if player %d finished their turn. It's now player %d's turn.\n", i, i - 1);
            else
                printf("endTurn(): FAIL if player %d did not finish their turn and it's not player %d's turn.\.n", i, i - 1);
        }
        if (G.handCount[i] == 0) 
            printf("endTurn(): PASS if player %d's hand count equals 0.\n", i);
        else 
            printf("endTurn(): FAIL if player %d's hand count does not equal 0.\n", i);
        if (i == G.whoseTurn - 1) {
            if (G.handCount[G.whoseTurn] == 5)
                printf("endTurn(): PASS if player %d's hand count equals 5.\n", i + 1);
            else 
                printf("endTurn(): FAIL if player %d's hand count does not equal 5.\n", i + 1);
        } else if (i == G.whoseTurn + 1) {
            if (G.handCount[G.whoseTurn] == 5)
                printf("endTurn(): PASS if player %d's hand count equals 5.\n", i - 1);
            else
                printf("endTurn(): FAIL if player %d's hand count does not equal 5.\n", i - 1);
        }
    }
}

int main(int argc, char **argv)
{
    testEndTurn();

    return 0;
}

