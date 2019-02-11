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
	int count1 = 0;
	int count2 = 0;

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &state);

	printf("\n----------Testing Smithy Card----------\n");

	// copy the game state to a test case
	memcpy(&test, &state, sizeof(struct gameState));
	cardEffect(smithy, choice1, choice2, choice3, &state, handpos, &bonus);

	player = whoseTurn(&test);
	
	
	//Check the player hands count
	if(test.handCount[player]-1 == state.handCount[player])
		printf("Passed where hand count is correct\n");
	else
		printf("Failed where hand count is not correct\n");
	
	
	//Check players hand
	if(state.hand[player][test.handCount[player]] != -1)
		printf("Passed where Smithy card was added to the players hand\n");
	else
		printf("Failed where Smithy card was not added to the players hand\n");

	
	//Check if player played Smithy card
	if(test.playedCardCount+2 == state.playedCardCount)
		printf("Passed where player played Smithy card\n");
	else
		printf("Failed where player did not play Smithy card\n");
	
	
	//Count smithy cards in hand
	for (i = 0; i < state.handCount[0]; i++)
        if(state.hand[0][i] = smithy);
			count1++;
		
	for (i = 0; i < test.handCount[0]; i++)
        if(test.hand[0][i] = smithy);
			count2++;
	
	if(count1 == count2-1)
		printf("Passed where there is no variance in smithy cards\n");
	else
		printf("Failed where there is a variance in smithy cards\n");
	
	
	//Discard Test: Check if card was discarded
	if(test.discardCount[player] == state.discardCount[player])
		printf("Passed where the Smithy was discarded\n");	
	else
		printf("Failed where the Smithy was not discarded.\n");
	
	printf("----------End Testing Smithy Card----------\n");
}

//cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)

/*Layout of Adventurer in Dominion
int smithyRefactor(int currentPlayer, struct gameState *state, int handPos)
{
	 int i;
	 //+3 Cards
      for (i = 0; i < handPos; i++)
		{
	 	 drawCard(currentPlayer, state);
		}
			
     //discard card from hand
     discardCard(handPos, currentPlayer, state, 0);
      return 0;
}
*/
