//unit test for gainCard
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

int main () {
  srand((unsigned int)time(NULL));

  printf("Testing gainCard function:\n");
  struct gameState G;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
  initializeGame(2, k, rand() % 5, &G);

  //test for return on empty supply or unused card
  G.supplyCount[adventurer] = 0;
  if(gainCard(adventurer, &G, 0, 0)) {
    printf("SUCCESS: Cannot gain card from empty/unused card pile\n");
  } else {
    printf("ERROR: Allows gain card from empty/unused card pile\n");
  }

  //test for add to deck
  initializeGame(2, k, rand() % 5, &G);
  int oldDeckCount =  G.deckCount[0];
  gainCard(adventurer, &G, 1, 0);
  if(G.deckCount[0] > oldDeckCount) {
    printf("SUCCESS: Added card to deck\n");
  } else {
    printf("ERROR: Did not add card to deck\n");
  }

  //test for add to hand
  initializeGame(2, k, rand() % 5, &G);
  int oldHandCount =  G.handCount[0];
  gainCard(adventurer, &G, 2, 0);
  if(G.handCount[0] > oldHandCount) {
    printf("SUCCESS: Added card to hand\n");
  } else {
    printf("ERROR: Did not add card to hand\n");
  }

  //test for add to discard
  initializeGame(2, k, rand() % 5, &G);
  int oldDiscardCount =  G.discardCount[0];
  gainCard(adventurer, &G, 0, 0);
  if(G.discardCount[0] > oldDiscardCount) {
    printf("SUCCESS: Added card to discard\n");
  } else {
    printf("ERROR: Did not add card to discard\n");
  }

  printf("COMPLETE: gainCard function\n");
}
