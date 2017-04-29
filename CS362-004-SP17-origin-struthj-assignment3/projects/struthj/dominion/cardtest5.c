#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dominion.c"

//salvager test
void main(){
    printf("Test 5: Salvager\n");
    struct gameState testGame;
    //test hand
    int myKingdomHand[10] = {smithy, sea_hag, outpost, adventurer, salvager, village, minion, mine, baron,embargo};
    int status = initializeGame(2, myKingdomHand, 4, &testGame);
    //assert game initialized correctly
    assert(status == NULL);
    printf("%d coins in Hand before card played!\n", testGame.coins);
    int salvagerResult = salvagerCard(&testGame,1,0,0);
    printf("%d coins in Hand after card played!\n", testGame.coins);
    //assert card returned successful and number of coins is increased
    assert(salvagerResult != -1);
    printf("Check if number of coins is correct (should be equal to 5 coins)\n");
    assert(testGame.coins == 5);
    //Alert user if passed
    printf("%d returned result (0 expected) Test Passed!\n", salvagerResult);

    return 0;
}
