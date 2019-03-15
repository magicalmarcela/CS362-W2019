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
    //int seed = 1000;
    //int numPlayers = 2;
    int player=0;
	struct gameState state, test;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	for(a = 0; a < 50; a++)
	{
		int numPlayers = (rand() % 50);
		int seed = (rand() % 5000);

		// initialize a game state and player cards
		initializeGame(numPlayers, k, seed, &state);


		printf("\n----------Testing Village Card Pass %d/50----------\n", a+1);

		// copy the game state to a test case
		memcpy(&test, &state, sizeof(struct gameState));
		cardEffect(village, choice1, choice2, choice3, &state, handpos, &bonus);

		player = whoseTurn(&test);

		//Check players hand
		if(state.hand[player][test.handCount[player]-1] != -1)
			printf("Passed where Village card was added to the players hand\n");
		else
			printf("Failed where Village card was not added to the players hand\n");

		//Check if player played Village card
		if(test.playedCardCount+1 == state.playedCardCount)
			printf("Passed where player played Village card\n");
		else
			printf("Failed where player did not play Village card\n");

		//Discard Test: Check if card was discarded
		if(test.discardCount[player] == state.discardCount[player])
			printf("Passed where the Village was discarded\n");
		else
		{
			printf("Failed where the Village was not discarded.\n");
		}

		//Action Test: Check if the +1 Action was added
		if(test.numActions+2 == state.numActions)
			printf("Passed where two extra action was added\n");
		else
			printf("Failed where two extra action was not added\n");
	}
	printf("----------End Testing Village Card----------\n");
}
