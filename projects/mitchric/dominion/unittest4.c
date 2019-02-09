#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

void testIsGameOver()
{
    int numOfPlayers = 2;
    int randomSeed = 100;
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy};

    initializeGame(numOfPlayers, k, randomSeed, &G);

    G.supplyCount[province] = 0;
    if (isGameOver(&G) == 1)
	printf("isGameOver(): PASS if isGameOver() returns 1 when G.supplyCount[province] is set to 0.\n");
    else
	printf("isGameOver(): FAIL if isGameOver() returns 0 when G.supplyCount[province] is set to 0.\n");

    G.supplyCount[0] = 0;    
    G.supplyCount[1] = 0;
    G.supplyCount[2] = 0;
    if (isGameOver(&G) == 1)
	printf("isGameOver(): PASS if isGameOver() returns 1 when at least 3 indices are set to 0.\n");
    else
	printf("isGameOver(): FAIL if isGameOver() returns 0 when at least 3 indices are set to 0.\n");
}

int main(int argc, char **argv)
{
    testIsGameOver();

    return 0;
}

