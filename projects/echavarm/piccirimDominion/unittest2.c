
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
	int cardNumber = 0;
	int returned = 0;

 	printf("\n----------Start Testing Card Cost----------\n");

	for(cardNumber; cardNumber < 27; cardNumber++)
	{
		returned = getCost(cardNumber);

		if(cardNumber == 0)			//Curse: 0
		{
			if (returned == 0)
				printf("\nPassed where Curse returned %d.\n", returned);
			else
				printf("\nFailed where Curse returned %d.\n", returned);
		}
		else if (cardNumber == 1)	//Estate: 2
		{
			if (returned == 2)
				printf("\nPassed where Estate returned %d.\n", returned);
			else
				printf("\nFailed where Estate returned %d.\n", returned);
		}
		else if (cardNumber == 2)	//Duchy: 5
		{
			if (returned == 5)
				printf("\nPassed where Duchy returned %d.\n", returned);
			else
				printf("\nFailed where Duchy returned %d.\n", returned);
		}
		else if (cardNumber == 3)	//Province: 8
		{
			if (returned == 8)
				printf("\nPassed where Province returned %d.\n", returned);
			else
				printf("\nFailed where Province returned %d.\n", returned);
		}
		else if (cardNumber == 4)	//Copper: 0
		{
			if (returned == 0)
				printf("\nPassed where Copper returned %d.\n", returned);
			else
				printf("\nFailed where Copper returned %d.\n", returned);
		}
		else if (cardNumber == 5)	//Silver: 3
		{
			if (returned == 3)
				printf("\nPassed where Silver returned %d.\n", returned);
			else
				printf("\nFailed where Silver returned %d.\n", returned);
		}
		else if (cardNumber == 6)	//Gold: 6
		{
			if (returned == 6)
				printf("\nPassed where Gold returned %d.\n", returned);
			else
				printf("\nFailed where Gold returned %d.\n", returned);
		}
		else if (cardNumber == 7)	//Adventure: 6
		{
			if (returned == 6)
				printf("\nPassed where Adventure returned %d.\n", returned);
			else
				printf("\nFailed where Adventure returned %d.\n", returned);
		}
		else if (cardNumber == 8)	//Council_Room: 5
		{
			if (returned == 5)
				printf("\nPassed where Council_Room returned %d.\n", returned);
			else
				printf("\nFailed where Council_Room returned %d.\n", returned);
		}
		else if (cardNumber == 9)	//Feast: 4
		{
			if (returned == 4)
				printf("\nPassed where Feast returned %d.\n", returned);
			else
				printf("\nFailed where Feast returned %d.\n", returned);
		}
		else if (cardNumber == 10)	//Gardens: 4
		{
			if (returned == 4)
				printf("\nPassed where Gardens returned %d.\n", returned);
			else
				printf("\nFailed where Gardens returned %d.\n", returned);
		}
		else if (cardNumber == 11)	//Mine: 5
		{
			if (returned == 5)
				printf("\nPassed where Mine returned %d.\n", returned);
			else
				printf("\nFailed where Mine returned %d.\n", returned);
		}
		else if (cardNumber == 12)	//Remodel: 4
		{
			if (returned == 4)
				printf("\nPassed where Remodel returned %d.\n", returned);
			else
				printf("\nFailed where Remodel returned %d.\n", returned);
		}
		else if (cardNumber == 13)	//Smithy: 4
		{
			if (returned == 4)
				printf("\nPassed where Smithy returned %d.\n", returned);
			else
				printf("\nFailed where Smithy returned %d.\n", returned);
		}
		else if (cardNumber == 14)	//Village: 3
		{
			if (returned == 3)
				printf("\nPassed where Village returned %d.\n", returned);
			else
				printf("\nFailed where Village returned %d.\n", returned);
		}
		else if (cardNumber == 15)	//Baron: 4
		{
			if (returned == 4)
				printf("\nPassed where Baron returned %d.\n", returned);
			else
				printf("\nFailed where Baron returned %d.\n", returned);
		}
		else if (cardNumber == 16)	//Great_Hall: 3
		{
			if (returned == 3)
				printf("\nPassed where Great_Hall returned %d.\n", returned);
			else
				printf("\nFailed where Great_Hall returned %d.\n", returned);
		}
		else if (cardNumber == 17)	//Minion: 5
		{
			if (returned == 5)
				printf("\nPassed where Minion returned %d.\n", returned);
			else
				printf("\nFailed where Minion returned %d.\n", returned);
		}
		else if (cardNumber == 18)	//Steward: 3
		{
			if (returned == 3)
				printf("\nPassed where Steward returned %d.\n", returned);
			else
				printf("\nFailed where Steward returned %d.\n", returned);
		}
		else if (cardNumber == 19)	//Tribute: 5
		{
			if (returned == 5)
				printf("\nPassed where Tribute returned %d.\n", returned);
			else
				printf("\nFailed where Tribute returned %d.\n", returned);
		}
		else if (cardNumber == 20)	//Ambassador: 3
		{
			if (returned == 3)
				printf("\nPassed where Ambassador returned %d.\n", returned);
			else
				printf("\nFailed where Ambassador returned %d.\n", returned);
		}
		else if (cardNumber == 21)	//Cutpurse: 4
		{
			if (returned == 4)
				printf("\nPassed where Cutpurse returned %d.\n", returned);
			else
				printf("\nFailed where Cutpurse returned %d.\n", returned);
		}
		else if (cardNumber == 22)	//Embargo: 2
		{
			if (returned == 2)
				printf("\nPassed where Embargo returned %d.\n", returned);
			else
				printf("\nFailed where Embargo returned %d.\n", returned);
		}
		else if (cardNumber == 23)	//Outpost: 5
		{
			if (returned == 5)
				printf("\nPassed where Outpost returned %d.\n", returned);
			else
				printf("\nFailed where Outpost returned %d.\n", returned);
		}
		else if (cardNumber == 24)	//Salvager: 4
		{
			if (returned == 4)
				printf("\nPassed where Salvager returned %d.\n", returned);
			else
				printf("\nFailed where Salvager returned %d.\n", returned);
		}
		else if (cardNumber == 25)	//Sea_Hag: 4
		{
			if (returned == 4)
				printf("\nPassed where Sea_Hag returned %d.\n", returned);
			else
				printf("\nFailed where Sea_Hag returned %d.\n", returned);
		}
		else if (cardNumber == 26)	//Treasure_Map: 4
		{
			if (returned == 4)
				printf("\nPassed where Treasure_Map returned %d.\n", returned);
			else
				printf("\nFailed where Treasure_Map returned %d.\n", returned);
		}
	}

	 printf("\n----------End Testing Card Cost----------\n");
}
