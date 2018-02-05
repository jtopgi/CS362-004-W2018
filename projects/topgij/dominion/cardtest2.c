//unit test for council_room
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>

int main () {
  printf("Testing council_room function:\n");
  struct gameState G;
  int k[10] = {adventurer, council_room, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
  initializeGame(2, k, 2, &G);

  gainCard(council_room, &G, 2, 0);
  int preSize = G.handCount[0];
  int preSizeEnemy = G.handCount[1];
  int preBuys = G.numBuys;
  cardEffect(council_room, 0, 0, 0, &G, 5, 0);

  //check that four cards were drawn
  if(G.handCount[0] == preSize + 3) {
    printf("SUCCESS: council_room draws 4 cards\n");
  } else {
    printf("ERROR: council_room does not draw 4 cards\n");
  }

  //check that numBuys is incremented
  if(G.numBuys == preBuys + 1) {
    printf("SUCCESS: council_room increases numBuys by 1\n");
  } else {
    printf("ERROR: council_room does not increase numBuys by 1\n");
  }

  //ensure that the other players draw a card
  if(G.handCount[1] == preSizeEnemy + 1) {
    printf("SUCCESS: council_room draws other players 1 card\n");
  } else {
    printf("ERROR: council_room does not draw other players 1 card\n");
  }

  //ensure council_room is in the played pile and not in the hand
  if(G.playedCards[G.playedCardCount - 1] == council_room && handCard(5, &G) != council_room) {
    printf("SUCCESS: council_room is discarded after play\n");
  } else {
    printf("ERROR: council_room is not discarded after play\n");
  }

  printf("COMPLETE: council_room function\n");
}
