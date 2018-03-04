//random test for village
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main () {
  printf("Random testing village function:\n");
  struct gameState G;
  int k[10] = {adventurer, council_room, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

  //flags
  int draw_1_card = 1;
  int smithy_in_played = 1;
  int actions_is_plus_2 = 1;

  //random testing
  srand(time(NULL));
  for(int j = 1; j < 20; j++){
    initializeGame(rand() % 3 + 2, k, rand(), &G);

    gainCard(village, &G, 2, 0);
    int preSize = G.handCount[0];
    int preActions = G.numActions;
    cardEffect(village, 0, 0, 0, &G, 5, 0);

    //check that one card was drawn
    if(G.handCount[0] != preSize) {
      draw_1_card = 0;
    }

    //ensure smithy is in the played pile and not in the hand
    if(G.playedCards[G.playedCardCount - 1] == village && handCard(5, &G) != village) {
    } else {
      smithy_in_played = 0;
    }

    //ensure actions is +2
    if(G.numActions != preActions + 2) {
      actions_is_plus_2 = 0;
    }
  }

  if(draw_1_card) {
    printf("SUCCESS: village draws 1 card\n");
  } else {
    printf("ERROR: village does not draw 1 card\n");
  }

  if(smithy_in_played) {
    printf("SUCCESS: village is discarded after play\n");
  } else {
    printf("ERROR: village is not discarded after play\n");
  }

  if(actions_is_plus_2) {
    printf("SUCCESS: village increases actions by 2\n");
  } else {
    printf("ERROR: village does not increase actions by 2\n");
  }

  printf("COMPLETE: random testing of village function\n");
}
