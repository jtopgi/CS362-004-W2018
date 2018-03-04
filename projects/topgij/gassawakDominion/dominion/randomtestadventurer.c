//random test for adventurer
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main () {
  printf("Random Testing adventurer function:\n");
  struct gameState G;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

  //set flag variables
  int two_card_taken = 1;
  int cards_are_coins = 1;

  //random testing
  srand(time(NULL));
  for(int j = 1; j < 20; j++){
    initializeGame(rand() % 3 + 2, k, rand(), &G);

    //ensure only two cards were taken
    int preSize = G.handCount[0];
    cardEffect(adventurer, 0, 0, 0, &G, 0, 0);
    if(G.handCount[0] != preSize + 2) {
      two_card_taken = 0;
    }

    //ensure that last two cards are coins
    int areCoins = 1;
    for (int i = 5; i < G.handCount[0]; i++) {
      if(handCard(i, &G) < 4 || handCard(i, &G) > 6) {
        areCoins *= 0;
      }
    }
    if(!areCoins) {
      cards_are_coins = 0;
    }
  }

  //print out results
  if(two_card_taken){
    printf("SUCCESS: adventurer only takes two cards\n");
  } else {
    printf("ERROR: adventurer does not take only two cards\n");
  }
  if(cards_are_coins) {
    printf("SUCCESS: adventurer only takes coins\n");
  } else {
    printf("ERROR: adventurer does not only take coins\n");
  }

  printf("COMPLETE: Random testing of adventurer function\n");
}
