#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


//unit test 3
int main(){
    printf("Unit Test 3: Shuffle\n");
    struct gameState testGame;
    //test hand
    int myKingdomHand[10] = {smithy, sea_hag, outpost, adventurer, salvager, village, minion, mine, baron,embargo};
    int status = initializeGame(2, myKingdomHand, 513, &testGame);
    //assert game initialized correctly
    assert(status == NULL);
    //test shuffle function
    int currentDeck = testGame.deck[0][testGame.deckCount[0] -1];
    printf("%d current Card!\n", currentDeck);
    shuffle(0,&testGame);
    int shuffleDeck = testGame.deck[0][testGame.deckCount[0] -1];
    printf("%d current Card after!\n", shuffleDeck);
    assert(currentDeck != shuffleDeck);

    currentDeck = testGame.deck[0][testGame.deckCount[0] -1];
    printf("%d current Card!\n", currentDeck);
    shuffle(0,&testGame);
    shuffleDeck = testGame.deck[0][testGame.deckCount[0] -1];
    printf("%d current Card after!\n", shuffleDeck);
    assert(currentDeck != shuffleDeck);

   //Alert user if passed
    printf("%d returned result (0 expected) Test Passed!\n", status);

    return 0;
}
