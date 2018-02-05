//unit test for village
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>

int main () {
  printf("Testing village function:\n");
  struct gameState G;
  int k[10] = {adventurer, council_room, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
  initializeGame(2, k, 2, &G);

  gainCard(village, &G, 2, 0);
  int preSize = G.handCount[0];
  int preActions = G.numActions;
  cardEffect(village, 0, 0, 0, &G, 5, 0);

  //check that one card was drawn
  if(G.handCount[0] == preSize) {
    printf("SUCCESS: village draws 1 card\n");
  } else {
    printf("ERROR: village does not draw 1 card\n");
  }

  //ensure smithy is in the played pile and not in the hand
  if(G.playedCards[G.playedCardCount - 1] == village && handCard(5, &G) != village) {
    printf("SUCCESS: village is discarded after play\n");
  } else {
    printf("ERROR: village is not discarded after play\n");
  }

  //ensure actions is +2
  if(G.numActions == preActions + 2) {
    printf("SUCCESS: village increases actions by 2\n");
  } else {
    printf("ERROR: village does not increase actions by 2\n");
  }

  printf("COMPLETE: village function\n");
}
