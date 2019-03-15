#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

void main ()
{
	struct gameState state1;
	struct gameState state2;
	state1.whoseTurn = 1;
	state2.whoseTurn = 2;

	printf("\nCheck player 1");
	if(whoseTurn(&state1) == 1)
		printf("\nPassed where player is player %d\n", state1.whoseTurn);
	else
		printf("\nFailed where player is player %d\n", state1.whoseTurn);


	printf("\nCheck player 2");
	if(whoseTurn(&state2) == 2)
		printf("\nPassed where player is player %d\n", state2.whoseTurn);
	else
		printf("\nFailed where player is player %d\n", state2.whoseTurn);
}
