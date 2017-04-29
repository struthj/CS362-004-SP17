#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dominion.c"

//unit test 1
void main(){
    printf("Unit Test 1: WhoseTurn\n");
    struct gameState testGame;
    //test hand
    int myKingdomHand[10] = {smithy, sea_hag, outpost, adventurer, salvager, village, minion, mine, baron,embargo};
    int status = initializeGame(3, myKingdomHand, 5, &testGame);
    //assert game initialized correctly
    assert(status == NULL);
    //test whoseTurn function
    int currentPlayer = whoseTurn(&testGame);
    printf("%d players turn!\n", currentPlayer);
    assert(currentPlayer == 0);
    endTurn(&testGame);
    currentPlayer = whoseTurn(&testGame);
    printf("%d players turn!\n", currentPlayer);
    assert(currentPlayer == 1);
    endTurn(&testGame);
    currentPlayer = whoseTurn(&testGame);
    printf("%d players turn!\n", currentPlayer);
    assert(currentPlayer == 2);
    endTurn(&testGame);
    currentPlayer = whoseTurn(&testGame);
    printf("%d players turn!\n", currentPlayer);
    assert(currentPlayer == 0);
    endTurn(&testGame);

   //Alert user if passed
    printf("%d returned result (0 expected) Test Passed!\n", status);

    return 0;
}
