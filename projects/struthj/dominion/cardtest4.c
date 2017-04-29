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
    
    int seaHagResult = seaHagCard(&testGame,0,0);
    //assert card returned successful result curse is top cardCoins
    //assert(seaHagResult != -1);
    if(seaHagResult != -1){
        printf("Returned successfl result Passed!\n");
    }else{
        printf("Failed!\n");
        testVal = 1;
    }
    
    printf("Check if top card of deck is a curse (top of deck should be equal to 0)\n");
    //assert(testGame.deck[10][testGame.deckCount[10]--] == curse);
    if(testGame.deck[10][testGame.deckCount[10]--] == curse){
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
    //Alert user if passed
    if(testVal == 0){
        printf("%d returned result (0 expected) Test Passed!\n", seaHagResult);
    }else{
        printf("TEST Failed!\n");
        testVal = 1;
    }

    return 0;
}
