#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Smithy Test
int main(){

    printf("Test 2: Adventurer\n");
    int testVal = 0;
    struct gameState testGame;
    //test hand
    int myKingdomHand[10] = {smithy, sea_hag, outpost, adventurer, salvager, village, minion, mine, baron,embargo};
    int status = initializeGame(2, myKingdomHand, 4, &testGame);
    int tempHand[10]= {0};
    //assert game initialized correctly
    if(status == NULL){
        printf("Passed!\n");
    }else{
        printf("Failed!\n");
        testVal = 1;
    }
    int treasure = 0;
    int adventurerResult = adventurerCard(treasure, &testGame,0,0, 0,tempHand);
    //assert card returned successful result and hand size is 5
    //assert(adventurerResult!= -1);
    if(adventurerResult!= -1){
        printf("Returned successfl result Passed!\n");
    }else{
        printf("Failed!\n");
        testVal = 1;
    }
    
    printf("Number of cards in hand %d\n", numHandCards(&testGame));
    //assert(numHandCards(&testGame) == 6);
    if(numHandCards(&testGame) == 6){
        printf("Returned successfl result Passed!\n");
    }else{
        printf("Failed!\n");
        testVal = 1;
    }
    
    //assert two treasure cards drawn
    printf("Drawn Treasure %d\n", numHandCards(&testGame));
    //assert(treasure == 2);
    if(treasure == 2){
        printf("Returned successfl result Passed!\n");
    }else{
        printf("Failed!\n");
        testVal = 1;
    }
    
    //Alert user if passed
    if(testVal == 0){
        printf("%d returned result (0 expected) Test Passed!\n", adventurerResult);
    }else{
        printf("TEST Failed!\n");
        testVal = 1;
    }

    return 0;
}
