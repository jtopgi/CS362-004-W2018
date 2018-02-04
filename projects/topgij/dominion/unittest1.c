//unit test for fullDeckCount
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

int main () {
  srand(time(0));

  printf("Testing fullDeckCount function:\n");
  struct gameState G;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
  initializeGame(2, k, rand() % 50, &G);

  int count = 0;
  for (int i = 0; i < 10; i++) {
    count += fullDeckCount(0, i, &G);
  }
  if(count == 10) {
    printf("SUCCESS: Started with 10 cards\n");
  } else {
    printf("ERROR: Did not start with 10 cards\n");
  }

  drawCard(0, &G);
  count = 0;
  for (int i = 0; i < 10; i++) {
    count += fullDeckCount(0, i, &G);
  }
  if(count == 10) {
    printf("SUCCESS: Counts cards in hand\n");
  } else {
    printf("ERROR: Does not count cards in hand\n");
  }

  discardCard(0, 0, &G, 0);
  G.discardCount[0] += 1;   //bug in discardCard not updating
  count = 0;
  for (int i = 0; i < 10; i++) {
    count += fullDeckCount(0, i, &G);
  }
  if(count == 10) {
    printf("SUCCESS: Counts discarded cards\n");
  } else {
    printf("ERROR: Does not count discarded cards\n");
  }
  printf("COMPLETE: fullDeckCount function\n");
}
