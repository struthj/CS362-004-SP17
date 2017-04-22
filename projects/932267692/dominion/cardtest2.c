#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "dominion.c"
//Smithy Test
void main(){

    printf("Test 2: Adventurer\n");
    struct gameState testGame;
    //test hand
    int myKingdomHand[10] = {smithy, sea_hag, outpost, adventurer, salvager, village, minion, mine, baron,embargo};
    int status = initializeGame(2, myKingdomHand, 4, &testGame);
    int tempHand[10]= {0};
    //assert game initialized correctly
    assert(status == NULL);
    int treasure = 0;
    int adventurerResult = adventurerCard(treasure, &testGame,0,1, 1,tempHand);
    //assert card returned successful result and hand size is 5
    assert(adventurerResult!= -1);
    printf("Number of cards in hand %d\n", numHandCards(&testGame));
    assert(numHandCards(&testGame) == 6);
    //assert two treasure cards drawn
    printf("Drawn Treasure %d\n", numHandCards(&testGame));
    assert(treasure == 2);
    //Alert user if passed
    printf("%d returned result (0 expected) Test Passed!\n", adventurerResult);
    return 0;
}
