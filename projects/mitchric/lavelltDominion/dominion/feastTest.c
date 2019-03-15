#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TESTCARD "feast"

int main(int argc, char** argv) {
    
    struct gameState G, testG;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

    int numOfPlayers = 2;
    int choice1 = 1, choice2 = 0, choice3 = 0; 
    int handPos = 0, bonus = 0, discarded = 1;
    int currPlayer = 0;


    int seed = 1000;

    initializeGame(numOfPlayers, k, seed, &G);

    printf("----------------Testing Card: %s-----------------\n", TESTCARD);

    memcpy(&testG, &G, sizeof(struct gameState));

    cardEffect(feast, choice1, choice2, choice3, &testG, handPos, &bonus);

    printf("discard = %d, expected = %d\n", testG.discard[currPlayer][ testG.discardCount[currPlayer] - 1 ], choice1); 
    printf("discard count = %d, expected = %d\n", testG.discardCount[currPlayer], G.discardCount[currPlayer] + discarded);
    printf("Card %d supply count = %d, expected = %d\n", choice1, testG.supplyCount[choice1], G.supplyCount[choice1] - discarded);
    assert(testG.discard[currPlayer][ testG.discardCount[currPlayer] - 1 ] == choice1);
    assert(testG.discardCount[currPlayer] == G.discardCount[currPlayer] + discarded);
    assert(testG.supplyCount[choice1] == G.supplyCount[choice1] - discarded);
    
    return 0;
}
