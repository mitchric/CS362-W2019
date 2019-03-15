#include "dominion.h"
#include <stdio.h>
#include <math.h>
#include "rngs.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TESTCARD "smithy"

void checkSmithy(struct gameState* G, int handPos, int currPlayer) {

    int choice1 = 0, choice2 = 0, choice3 = 0; 
    int bonus = 0, newCards = 3, discarded = 1;
    int r;

    struct gameState testG;

    memcpy(&testG, G, sizeof(struct gameState));
    
    r = cardEffect(smithy, choice1, choice2, choice3, &testG, handPos, &bonus); 

    assert(r == 0);
    assert(testG.handCount[currPlayer] == G->handCount[currPlayer] + newCards - discarded);
    assert(testG.deckCount[currPlayer] == G->deckCount[currPlayer] - newCards);
    

}

int main(int argc, char** argv) {
    
    int i, n, handPos;
    int currPlayer = 0;
    int seed = 1000;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy};
 

    struct gameState G;


    printf("----------------Testing Card: %s-----------------\n", TESTCARD);

    printf ("RANDOM TESTS.\n");

    SelectStream(2);
    PutSeed(3);

    for (n = 0; n < 2000; n++) {
        for (i = 0; i < sizeof(struct gameState); i++) {
            ((char*)&G)[i] = floor(Random() * 256);
        }
        initializeGame(2, k, seed, &G);
        handPos = floor(Random() * 5);
        checkSmithy(&G, handPos, currPlayer);
    }

    printf("All tests OK\n");
}
