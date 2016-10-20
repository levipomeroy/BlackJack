/************************************************************************
* Class: Blackjack
* Purpose: This class prompts the user for info and processes the program,
*		   it controls the game of blackjack.
*
* Manager functions:
* 	BlackJack(int stack)
* 		A 1 arg constructor, sets m_bank to stack.
*	~BlackJack();
*		Default destructor - frees memory.
*
* Methods:
*	Prompt_User()
*		Prompts the user to play or exit and processes results.
*	Player_Prompt(int & bet)
*		Enters game and decides result, i.e. winner/loser. And provides 
*		additional options.
*************************************************************************/
#include "Bankroll.h"
#include "Dealer.h"
#include "Player.h"
#include "Deck.h"

#ifndef BLACKJACK_H
#define BLACKJACK_H

class BlackJack
{
public:
	BlackJack(int stack);	//One arg constructor
	~BlackJack();	//Destructor
	void Prompt_User();	//Prompts user to play
	bool Player_Prompt(int & bet);	//Processes game & supplies necessary additions

private:
	Bankroll m_bank;	//Amount of money
	Dealer m_dealer;	//Deealers hand/cards
	Player m_player;	//Players hand/cards
	Deck m_deck;		//The game deck of cards
	bool m_push = false;
};

#endif
