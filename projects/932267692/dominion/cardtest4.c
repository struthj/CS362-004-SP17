#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dominion.c"

//seaHag test
void main(){
    printf("Test 4: Sea Hag\n");
    struct gameState testGame;
    //test hand
    int myKingdomHand[10] = {smithy, sea_hag, outpost, adventurer, salvager, village, minion, mine, baron,embargo};
    int status = initializeGame(2, myKingdomHand, 4, &testGame);
    //assert game initialized correctly
    assert(status == NULL);
    int seaHagResult = seaHagCard(&testGame,0,0);
    //assert card returned successful result curse is top cardCoins
    assert(seaHagResult != -1);
    printf("Check if top card of deck is a curse (top of deck should be equal to 0)\n");
    assert(testGame.deck[10][testGame.deckCount[10]--] == curse);
    printf("Number of cards in hand %d\n", numHandCards(&testGame));
    assert(numHandCards(&testGame) == 5 );
    //Alert user if passed
    printf("%d returned result (0 expected) Test Passed!\n", seaHagResult);

    return 0;
}
