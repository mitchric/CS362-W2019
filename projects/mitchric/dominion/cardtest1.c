#include "dominion.h"
#include "dominion_helpers.h"
#include "string.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

void testSmithy()
{
    int numOfPlayers = 2; 
    int extraCards = 0;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int randomSeed = 100;
    int thisPlayer = 0;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy};
    struct gameState G, testG;

    initializeGame(numOfPlayers, k, randomSeed, &G);

    memcpy(&testG, &G, sizeof(struct gameState));

    cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

    extraCards = 3;

    if (testG.handCount[thisPlayer] == G.handCount[thisPlayer] + extraCards)
        printf("Test smithy card : PASS if hand count for player %d = %d.\n", thisPlayer, G.handCount[thisPlayer] + extraCards);
    else
        printf("Test smithy card : FAIL if hand count for player %d != %d.\n", thisPlayer, G.handCount[thisPlayer] + extraCards);

    if (testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - extraCards)
        printf("Test smithy card : PASS if deck count for player %d = %d.\n", thisPlayer, G.deckCount[thisPlayer] - extraCards);
    else
        printf("Test smithy card : FAIL if deck count for player %d != %d.\n", thisPlayer, G.deckCount[thisPlayer] - extraCards);
}

int main(int argc, char **argv)
{
    testSmithy();

    return 0;
}
