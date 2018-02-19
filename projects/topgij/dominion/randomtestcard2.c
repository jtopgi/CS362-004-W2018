//random test for smithy
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main () {
  printf("Random testing smithy function:\n");
  struct gameState G;
  int k[10] = {adventurer, council_room, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

  //flags
  int smithy_played_pile = 1;
  int three_cards_drawn = 1;

  //random testing
  srand(time(NULL));
  for(int j = 1; j < 20; j++){
    initializeGame(rand() % 3 + 2, k, rand(), &G);

    gainCard(smithy, &G, 2, 0);
    int preSize = G.handCount[0];
    cardEffect(smithy, 0, 0, 0, &G, 5, 0);

    //check that three cards were drawn
    if(G.handCount[0] != preSize + 2) {
      three_cards_drawn = 0;
    }

    //ensure smithy is in the played pile and not in the hand
    if(G.playedCards[G.playedCardCount - 1] == smithy && handCard(5, &G) != smithy) {
    } else {
      smithy_played_pile = 0;
    }
  }

  if(three_cards_drawn) {
    printf("SUCCESS: smithy draws 3 cards\n");
  } else {
    printf("ERROR: smithy does not draw 3 cards\n");
  }

  if(smithy_played_pile) {
    printf("SUCCESS: smithy is discarded after play\n");
  } else {
    printf("ERROR: smithy is not discarded after play\n");
  }

  printf("COMPLETE: random testing smithy function\n");
}
