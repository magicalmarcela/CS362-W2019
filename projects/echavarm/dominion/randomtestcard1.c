#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include<time.h>

void main()
{
	srand(time(NULL));

    int i, j, m, a;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    //int numPlayers = 2;
    int player=0;
	struct gameState state, test;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	for(a = 0; a < 10000; a++)
	{
		int numPlayers = (rand() % 50);
		//int seed = (rand() % 100);

		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &state);

		printf("\n----------Testing Great Hall Card Pass %d/10000----------\n", a+1);

		// copy the game state to a test case
		//state.hand[player][5] = great_hall;
		//state.handCount[player]++;

		memcpy(&test, &state, sizeof(struct gameState));
		cardEffect(great_hall, choice1, choice2, choice3, &state, handpos, &bonus);

		player = whoseTurn(&test);

		//Check players hand
		if(state.hand[player][test.handCount[player]-1] != -1)
			printf("Passed where Great Hall card was added to the players hand\n");
		else
			printf("Failed where Great Hall card was not added to the players hand\n");

		//Check if player played Great Hall card
		if(test.playedCardCount+1 == state.playedCardCount)
			printf("Passed where player played Great Hall card\n");
		else
			printf("Failed where player did not play Great Hall card\n");

		//Discard Test: Check if card was discarded
		if(test.discardCount[player] == state.discardCount[player])
			printf("Passed where the Great Hall was discarded\n");
		else
		{
			printf("Failed where the Great Hall was not discarded.\n");
		}

		//Action Test: Check if the +1 Action was added
		if(test.numActions+1 == state.numActions)
			printf("Passed where an extra action was added\n");
		else
			printf("Failed where an extra action was not added\n");
	}
	printf("----------End Testing Great Hall Card----------\n");
}
