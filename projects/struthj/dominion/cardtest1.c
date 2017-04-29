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

    printf("Test 1: Smithy\n");
    int testVal = 0;
    struct gameState testGame;
    //test hand
    int myKingdomHand[10] = {smithy, sea_hag, outpost, adventurer, salvager, village, minion, mine, baron,embargo};
    int status = initializeGame(2, myKingdomHand, 4, &testGame);
    //assert game initialized correctly
    if(status == NULL){
        printf("Passed!\n");
    }else{
        printf("Failed!\n");
        testVal = 1;
    }
    int smithyResult = smithyCard(0, 0,&testGame, 1);
    //assert card returned successful result and handsize is increased by 2
    //assert(smithyResult != -1);
    if(smithyResult != -1){
        printf("Returned successfl result Passed!\n");
    }else{
        printf("Failed!\n");
        testVal = 1;
    }
    printf("Number of cards in hand %d\n", numHandCards(&testGame));
    
    if(numHandCards(&testGame) == 7){
        printf("Returned successfl result Passed!\n");
    }else{
        printf("Failed!\n");
        testVal = 1;
    }
    //Alert user if passed
    if(testVal == 0){
        printf("%d returned result (0 expected) Test Passed!\n", smithyResult);
    }else{
        printf("TEST Failed!\n");
        testVal = 1;
    }
    
    return 0;
}
