//unit test for updateCoins
#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

int main () {
  srand((unsigned int)time(NULL));

  printf("Testing updateCoins function:\n");
  struct gameState G;
  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};
  initializeGame(2, k, rand() % 5, &G);

  //test copper
  int preCopper = G.coins;
  gainCard(copper, &G, 2, 0);
  updateCoins(0, &G, 0);
  if(G.coins == preCopper + 1) {
    printf("SUCCESS: Calculated copper properly.\n");
  } else {
    printf("ERROR: Did not calculate copper properly.\n");
  }

  //test silver
  int preSilver = G.coins;
  gainCard(silver, &G, 2, 0);
  updateCoins(0, &G, 0);
  if(G.coins == preSilver + 2) {
    printf("SUCCESS: Calculated silver properly.\n");
  } else {
    printf("ERROR: Did not calculate silver properly.\n");
  }

  //test gold
  int preGold = G.coins;
  gainCard(gold, &G, 2, 0);
  updateCoins(0, &G, 0);
  if(G.coins == preGold + 3) {
    printf("SUCCESS: Calculated gold properly.\n");
  } else {
    printf("ERROR: Did not calculate gold properly.\n");
  }

  //test bonus
  int preBonus = G.coins;
  int bonus = 5;
  gainCard(gold, &G, 2, 0);
  updateCoins(0, &G, bonus);
  if(G.coins == preBonus + 3 + bonus) {
    printf("SUCCESS: Calculated bonus properly.\n");
  } else {
    printf("ERROR: Did not calculate bonus properly.\n");
  }

  printf("COMPLETE: updateCoins function\n");
}
