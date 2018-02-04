//unit test for isGameOver
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

int main () {
  srand(time(0));

  printf("Testing isGameOver function:\n");
  struct gameState G;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
  initializeGame(2, k, rand() % 5, &G);

  //Province cards are empty
  G.supplyCount[province] = 0;
  if(isGameOver(&G)) {
    printf("SUCCESS: Game ends when province cards are empty\n");
  } else {
    printf("ERROR: Game does not end when province cards are empty\n");
  }

  //Randomly make three supply piles to zero
  initializeGame(2, k, rand() % 5, &G);  //reset game state
  G.supplyCount[adventurer] = 0;
  G.supplyCount[council_room] = 0;
  //test for failure
  if(isGameOver(&G)) {
    printf("SUCCESS: Game does not end when three supply piles are not empty\n");
  } else {
    printf("ERROR: Game endsend when three supply piles are not empty\n");
  }

  G.supplyCount[feast] = 0;
  if(isGameOver(&G)) {
    printf("SUCCESS: Game ends when three supply piles are empty\n");
  } else {
    printf("ERROR: Game does not end when three supply piles are empty\n");
  }

  printf("COMPLETE: isGameOver function\n");
}
