#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <assert.h>

#define TESTCARD "treasure map"

void checkTreasureMap(struct gameState* G) {

    struct gameState testG;  

    int numOfPlayers = 2;
    int choice1 = 0, choice2 = 0, choice3 = 0; 
    int handPos = 0, bonus = 0, card = 0, discarded = 2, newCards = 4;
    int lower = 1, upper = 4;
    int currPlayer = 0;
    int r;

    srand(time(0));

    memcpy(&testG, G, sizeof(struct gameState));

    card = (rand() % (upper - lower + 1)) + lower; 
    
    testG.hand[currPlayer][card] = treasure_map;
    r = cardEffect(treasure_map, choice1, choice2, choice3, &testG, handPos, &bonus);

    assert(r == 1);
    assert(testG.handCount[currPlayer] == G->handCount[currPlayer] - discarded);
    assert(testG.deckCount[currPlayer] == G->deckCount[currPlayer] + newCards);

}

int main(int argc, char** argv) {
    
    int n, i;
    struct gameState G;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

    int seed = 1000;


    printf("----------------Testing Card: %s-----------------\n", TESTCARD);

    printf ("RANDOM TESTS.\n");

    for (n = 0; n < 2000; n++) {
        for (i = 0; i < sizeof(struct gameState); i++) {
            ((char*)&G)[i] = floor(Random() * 256);
        }
        initializeGame(2, k, seed, &G);
        checkTreasureMap(&G);
    }
    
    printf("All tests OK\n");
    
    return 0;
}
