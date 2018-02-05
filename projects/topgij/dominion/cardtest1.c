//unit test for adventurer
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

int main () {
  srand((unsigned int)time(NULL));

  printf("Testing adventurer function:\n");
  struct gameState G;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
  initializeGame(2, k, rand() % 5, &G);

  //ensure only two cards were taken
  int preSize = G.handCount[0];
  cardEffect(adventurer, 0, 0, 0, &G, 0, 0);
  if(G.handCount[0] == preSize + 2) {
    printf("SUCCESS: adventurer only takes two cards\n");
  } else {
    printf("ERROR: adventurer does not take two cards\n");
  }

  //ensure that last two cards are coins
  int areCoins = 1;
  for (int i = 5; i < G.handCount[0]; i++) {
    if(handCard(i, &G) < 4 || handCard(i, &G) > 6) {
      areCoins *= 0;
    }
  }
  if(areCoins) {
    printf("SUCCESS: adventurer only takes coins\n");
  } else {
    printf("ERROR: adventurer does not only take coins\n");
  }

  printf("COMPLETE: adventurer function\n");
}
