#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


//outpost test
int main(){
    printf("Test 3: Outpost\n");
    int testVal = 0;
    struct gameState testGame;
    //test hand
    int myKingdomHand[10] = {smithy, sea_hag, outpost, adventurer, salvager, village, minion, mine, baron,embargo};
    int status = initializeGame(2, myKingdomHand, 4, &testGame);
    //assert game initialized correctly
    //assert(status == NULL);
    if(status == NULL){
        printf("%Passed!\n");
    }else{
        printf("%Failed!\n");
        testVal = 1;
    }
    
    int outPostResult = outpostCard(&testGame,0, 0);
    //assert card returned successful result outpost flag is set
    //assert(outPostResult != -1);
    if(outPostResult != -1){
        printf("Returned successfl result Passed!\n");
    }else{
        printf("Failed!\n");
        testVal = 1;
    }
    
    printf("Check if Outpost has been played (outpost flag should be 1)\n");
    //assert(testGame.outpostPlayed == 1);
    if(testGame.outpostPlayed == 1){
        printf("Returned successfl result Passed!\n");
    }else{
        printf("Failed!\n");
        testVal = 1;
    }
    
    printf("Number of cards in hand %d\n", numHandCards(&testGame));
    //assert(numHandCards(&testGame) == 5 );
    if(numHandCards(&testGame) == 5){
        printf("Returned successfl result Passed!\n");
    }else{
        printf("Failed!\n");
        testVal = 1;
    }
    
        //Alert user if passed
    if(testVal == 0){
        printf("%d returned result (0 expected) Test Passed!\n", outPostResult);
    }else{
        printf("TEST Failed!\n");
        testVal = 1;
    }

    return 0;
}
