#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


//unit test 4
int main(){
    printf("Unit Test 4: ScoreFor\n");
    struct gameState testGame;
    //test hand
    int myKingdomHand[10] = {smithy, sea_hag, outpost, adventurer, salvager, village, minion, mine, baron,embargo};
    int status = initializeGame(2, myKingdomHand, 513, &testGame);
    //assert game initialized correctly
    assert(status == NULL);
    //test scoreFor function
    int currentScore = scoreFor(0,&testGame);
    printf("%d current Score!\n", currentScore);
    updateCoins(0, &testGame,5);
    drawCard(0, &testGame);
    testGame.hand[0][0] = province;
    int updateScore = scoreFor(0,&testGame);;
    printf("%d current Score after!\n", updateScore);
    assert(currentScore < updateScore);

    currentScore = scoreFor(1,&testGame);
    printf("%d current Score!\n", currentScore);
    updateCoins(1, &testGame,10);
    drawCard(1, &testGame);
    testGame.hand[1][0] = province;
    updateScore = scoreFor(1,&testGame);;
    printf("%d current Score after!\n", updateScore);
    assert(currentScore < updateScore);

   //Alert user if passed
    printf("%d returned result (0 expected) Test Passed!\n", status);

    return 0;
}
