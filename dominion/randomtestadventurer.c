#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TESTS 12

//This randomly tests Adventurer

int main() {

	  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};

	  int i, j, n, players, player, handCount, deckCount, seed, address;
	  //struct gameState state;
	  struct gameState state;
	  struct gameState stat;
	  struct gameState sta;

	  printf("Running Random Adventurer Test\n");

	  /*
										--- Author's Note ---
	  So, I had problems running out of memory when I used the same gameState variable more than 12 times, and
	  I honestly don't know why. I momentarily solved this problem by adding more for loops and creating more gamestates;
	  I was still able to get decent coverage, though not up to the amount of tests I originally had in mind.

	  */
		players = 0;
	  for (i = 0; i < MAX_TESTS; i++) {

	   players = rand() % 4;

	   seed = rand();		//pick random seed

	   initializeGame(players, k, seed, &state);	//initialize Gamestate

	   //Initiate valid state variables
		 for(int player = 0; j < players; player++){
			  state.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
			  state.discardCount[player] = rand() % MAX_DECK;
			  state.handCount[player] = rand() % MAX_HAND;

			  //Copy state variables
			  handCount = state.handCount[player];
			  deckCount = state.deckCount[player];
		}
		  //1 in 3 chance of making empty deck for coverage
		  if (seed % 3 == 0) {

			state.deckCount[player] = 0;
		  }

		  playCard(0, 1, 1, 1, &state);		//Run adventurer card
			printf("first loop\n");
	  }

	   for (i = 0; i < MAX_TESTS; i++) {

  		  players = rand() % 4;
		  seed = rand();		//pick random seed

		  initializeGame(players, k, seed, &stat);	//initialize Gamestate

		  //Initiate valid state variables
			for(int player = 0; j < players; player++){
			  stat.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
			  stat.discardCount[player] = rand() % MAX_DECK;
			  stat.handCount[player] = rand() % MAX_HAND;


			  //Copy state variables
			  handCount = stat.handCount[player];
			  deckCount = stat.deckCount[player];
		}

		  //1 in 3 chance of making empty deck for coverage
		  if (seed % 3 == 0) {

			stat.deckCount[player] = 0;
		  }

		  playCard(adventurer, 1, 1, 1, &stat);		//Run adventurer card
	  }

	   for (i = 0; i < MAX_TESTS; i++) {

  		players = rand() % 4;
		  seed = rand();		//pick random seed

		  initializeGame(players, k, seed, &sta);	//initialize Gamestate

		  //Initiate valid state variables
			for(int player = 0; j < players; player++){
			  sta.deckCount[player] = rand() % MAX_DECK; //Pick random deck size out of MAX DECK size
			  sta.discardCount[player] = rand() % MAX_DECK;
			  sta.handCount[player] = rand() % MAX_HAND;


			  //Copy state variables
			  handCount = sta.handCount[player];
			  deckCount = sta.deckCount[player];
			}

		  //1 in 3 chance of making empty deck for coverage
		  if (seed % 3 == 0) {

			sta.deckCount[player] = 0;
		  }
		  playCard(adventurer, 1, 1, 1, &sta);		//Run adventurer card

	   }

	  printf("Tests Complete\n");

	  return 0;
}
