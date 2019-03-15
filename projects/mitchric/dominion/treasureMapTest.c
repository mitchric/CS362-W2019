#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TESTCARD "treasure map"

int main(int argc, char** argv) {
    
    struct gameState G, testG;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

    int numOfPlayers = 2;
    int choice1 = 0, choice2 = 0, choice3 = 0; 
    int handPos = 0, bonus = 0, card = 1, discarded = 2, newCards = 4;
    int currPlayer = 0;


    int seed = 1000;

    initializeGame(numOfPlayers, k, seed, &G);

    printf("----------------Testing Card: %s-----------------\n", TESTCARD);

    memcpy(&testG, &G, sizeof(struct gameState));
    testG.hand[currPlayer][card] = treasure_map;
    cardEffect(treasure_map, choice1, choice2, choice3, &testG, handPos, &bonus);

    printf("hand count = %d, expected = %d\n", testG.handCount[currPlayer], G.handCount[currPlayer] - discarded); 
    printf("deck count = %d, expected = %d\n", testG.deckCount[currPlayer], G.deckCount[currPlayer] + newCards);
    assert(testG.handCount[currPlayer] == G.handCount[currPlayer] - discarded);
    assert(testG.deckCount[currPlayer] == G.deckCount[currPlayer] + newCards);
    
    return 0;
}
