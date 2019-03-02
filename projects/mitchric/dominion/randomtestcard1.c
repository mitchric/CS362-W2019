#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>


  //assert (r == 0);

  //assert(memcmp(&pre, post, sizeof(struct gameState)) == 0);

void testNumHandCards() {

    int i, p, seed, numOfPlayers, numOfCards;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy};

    struct gameState G;

    memset(&G, 23, sizeof(struct gameState));

    printf ("Testing numHandCards().\n");

    srand(time(0));

    for (i = 0; i < 100; i++) {
        seed = rand() % 100 + 1;
        p = rand() % 4 + 1;
        initializeGame(p, k, seed, &G);
        numOfCards = numHandCards(&G); 
        if (numOfCards == 5)
            printf("TEST PASSED, number of cards equals 5\n");
        else 
            printf("TEST FAILED, number of cards does not equal 5\n");
    }
}



int main (int argc, char *argv[]) {

    testNumHandCards();

    exit(0);
}
