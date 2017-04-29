#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


//unit test 2
int main(){
    printf("Unit Test 2: UpdateCoins\n");
    struct gameState testGame;
    //test hand
    int myKingdomHand[10] = {smithy, sea_hag, outpost, adventurer, salvager, village, minion, mine, baron,embargo};
    int status = initializeGame(2, myKingdomHand, 5, &testGame);
    //assert game initialized correctly
    assert(status == NULL);
    //test updateCoins function
    int currentCoins = testGame.coins;
    printf("%d current Coins!\n", currentCoins);
    assert(currentCoins == 4);
    updateCoins(0, &testGame, 1);
    currentCoins = testGame.coins;
    printf("%d current Coins!\n", currentCoins);
    assert(currentCoins == 5);
    updateCoins(0, &testGame, 2);
    currentCoins = testGame.coins;
    printf("%d current Coins!\n", currentCoins);
    assert(currentCoins == 6);
    updateCoins(0, &testGame, 4);
    currentCoins = testGame.coins;
    printf("%d current Coins!\n", currentCoins);
    assert(currentCoins == 8);
   //Alert user if passed
    printf("%d returned result (0 expected) Test Passed!\n", status);

    return 0;
}
