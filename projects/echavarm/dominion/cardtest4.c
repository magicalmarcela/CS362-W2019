#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

void main() 
{
    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int player=0;
	struct gameState state, test;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &state);

	printf("\n----------Testing Great Hall Card----------\n");

	// copy the game state to a test case
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
		printf("Failed where the Great Hall was not discarded.\n");
	
	
	//Action Test: Check if the +1 Action was added
	if(test.numActions+1 == state.numActions)
		printf("Passed where an extra action was added\n");
	else
		printf("Failed where an extra action was not added\n");
	
	
	printf("----------End Testing Great Hall Card----------\n");
}

//cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)

/*Layout of Great Hall in Dominion
	case great_hall:
		//+1 Card
		drawCard(currentPlayer, state);
			
		//+1 Actions
		state->numActions++;
			
		//discard card from hand
		discardCard(handPos, currentPlayer, state, 0);
		return 0;
*/
