#include "dominion.h"
#include "dominion_helpers.h"
#include "string.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

void testVillageCard()
{
    int numOfPlayers = 2; 
    int extraActions = 0;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int randomSeed = 100;
    int thisPlayer = 0;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy};
    struct gameState G, testG;

    initializeGame(numOfPlayers, k, randomSeed, &G);

    memcpy(&testG, &G, sizeof(struct gameState));

    cardEffect(village, choice1, choice2, choice3, &testG, handpos, &bonus);

    extraActions = 2;

    if (testG.numActions == G.numActions + extraActions)
        printf("Test village card : PASS if number of actions for turn = %d.\n", G.numActions + extraActions);
    else
        printf("Test village card : FAIL if number of actions for turn != %d.\n", G.numActions + extraActions); 

    if (testG.handCount[thisPlayer] == G.handCount[thisPlayer])
	printf("Test village card : PASS if hand count for player %d = %d.\n", thisPlayer, G.handCount[thisPlayer]);
    else 
	printf("Test village card : FAIL if hand count for player %d != %d.\n", thisPlayer, G.handCount[thisPlayer]);
}

int main(int argc, char **argv)
{
    testVillageCard();

    return 0;
}
