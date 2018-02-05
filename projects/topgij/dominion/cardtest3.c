//unit test for smithy
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>

int main () {
  printf("Testing smithy function:\n");
  struct gameState G;
  int k[10] = {adventurer, council_room, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
  initializeGame(2, k, 2, &G);

  gainCard(smithy, &G, 2, 0);
  int preSize = G.handCount[0];
  cardEffect(smithy, 0, 0, 0, &G, 5, 0);

  //check that three cards were drawn
  if(G.handCount[0] == preSize + 2) {
    printf("SUCCESS: smithy draws 3 cards\n");
  } else {
    printf("ERROR: smithy does not draw 3 cards\n");
  }

  //ensure smithy is in the played pile and not in the hand
  if(G.playedCards[G.playedCardCount - 1] == smithy && handCard(5, &G) != smithy) {
    printf("SUCCESS: smithy is discarded after play\n");
  } else {
    printf("ERROR: smithy is not discarded after play\n");
  }

  printf("COMPLETE: smithy function\n");
}
