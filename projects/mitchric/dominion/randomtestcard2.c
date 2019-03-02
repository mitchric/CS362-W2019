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

void testWhoseTurn() {

    int i, p, seed, numOfPlayers, numOfCards;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy};

    struct gameState G;

    memset(&G, 23, sizeof(struct gameState));

    printf ("Testing whoseTurn().\n");

    srand(time(0));
    
    for (i = 0; i < 100; i++) {
        seed = rand() % 100 + 1;
        p = rand() % 4 + 1;
        initializeGame(p, k, seed, &G);
        if (p == 1) {
            printf("TEST FAILED number of players less than 2\n");
            continue;
        }
        if (p == 2) {
            if (whoseTurn(&G) == 0) 
                printf("TEST PASSED, 2 players, it's player 1's turn\n");
            else 
                printf("TEST FAILED, 2 players, and it's not player 1's turn\n");
            endTurn(&G);
            if (whoseTurn(&G) == 1)
                printf("TEST PASSED, 2 players, it's player 2's turn\n");
            else
                printf("TEST FAILED, 2 players, and it's not player 2's turn\n");
        } else if (p == 3) {
            if (whoseTurn(&G) == 0)
                printf("TEST PASSED, 3 players, it's player 1's turn\n");
            else 
                printf("TEST FAILED, 3 players, and it's not player 1's turn\n");
            endTurn(&G);
            if (whoseTurn(&G) == 1)
                printf("TEST PASSED, 3 players, it's player 2's turn\n");
            else
                printf("TEST FAILED, 3 players, and it's not player 2's turn\n");
            endTurn(&G);
            if (whoseTurn(&G) == 2)
                printf("TEST PASSED, 3 players, it's player 3's turn\n");
            else
                printf("TEST FAILED, 3 players, and it's not player 3's turn\n");
        } else if (p == 4) {
            if (whoseTurn(&G) == 0)
                printf("TEST PASSED, 4 players, it's player 1's turn\n");
            else 
                printf("TEST FAILED, 4 players, and it's not player 1's turn\n");
            endTurn(&G);
            if (whoseTurn(&G) == 1)
                printf("TEST PASSED, 4 players, it's player 2's turn\n");
            else
                printf("TEST FAILED, 4 players, and it's not player 2's turn\n");
            endTurn(&G);
            if (whoseTurn(&G) == 2)
                printf("TEST PASSED, 4 players, it's player 3's turn\n");
            else
                printf("TEST FAILED, 4 players, and it's not player 3's turn\n");
            endTurn(&G);
            if (whoseTurn(&G) == 3)
                printf("TEST PASSED, 4 players, it's player 4's turn\n");
            else
                printf("TEST FAILED, 4 players, and it's not player 4's turn\n");
        } else {
            printf("TEST FAILED, incorrect player count\n");
        }
    }
}

int main (int argc, char *argv[]) {

    testWhoseTurn();

    exit(0);
}
