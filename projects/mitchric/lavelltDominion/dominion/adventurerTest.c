#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define TESTCARD "adventurer"

int main(int argc, char** argv) {
    
    struct gameState G, testG;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

    int numOfPlayers = 2;
    int choice1 = 0, choice2 = 0, choice3 = 0; 
    int handPos = 0, bonus = 0, newCards = 2;
    int currPlayer = 0;
    int deckCounter = 0;
    int firstCard = 0;
    int secondCard = 0;


    int seed = 1000;

    initializeGame(numOfPlayers, k, seed, &G);

    printf("----------------Testing Card: %s-----------------\n", TESTCARD);

    memcpy(&testG, &G, sizeof(struct gameState));

    deckCounter = testG.deckCount[currPlayer];
    // set top 2 cards in deck as treasure cards
    testG.deck[currPlayer][deckCounter - 1] = copper; 
    testG.deck[currPlayer][deckCounter - 2] = copper;

    cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus);

    firstCard = testG.hand[currPlayer][testG.handCount[currPlayer]-1];
    secondCard = testG.hand[currPlayer][testG.handCount[currPlayer] - 2];

    printf("hand count = %d, expected = %d\n", testG.handCount[currPlayer], G.handCount[currPlayer] + newCards); 
    printf("deck count = %d, expected = %d\n", testG.deckCount[currPlayer], G.deckCount[currPlayer] - newCards);
    printf("First card in hand = %d, expected %d\n", firstCard, copper);
    printf("Second card in hand = %d, expected %d\n", secondCard, copper);
    assert(testG.handCount[currPlayer] == G.handCount[currPlayer] + newCards);
    assert(testG.deckCount[currPlayer] == G.deckCount[currPlayer] - newCards);
    assert(firstCard == copper);
    assert(secondCard == copper);
    
    return 0;
}
