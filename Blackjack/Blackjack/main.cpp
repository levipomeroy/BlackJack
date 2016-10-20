/***********************************************************
* Author:				Levi Pomeroy
* Date Created:			05/19/16
* Last Mod Date:		05/19/16
* Lab Number:			CST 136
* Filename:				Blackjack game
*
* Overview:
*	This program displays menus and asks the user to play a 
*	game of blackjack. Once it starts, it displays the user's
*	cards and the dealers first card. Then it asks the user to
*	hit or stand. It will then process the game and decide a winner
*	and award the winner the bet.
*
* Input:
*	The input will consist of a menu choice to play or not, an option
*	to hit or stand, and if the parameters are correct, the user has to
*	choice enter the value of an ace, or double down.
*
* Output:
*	The output of this program will consist of the prompts, asking the
*	user for hi/her choices, displayijng the dealers and players hands,
*	and a message declaring the winner after each round.
************************************************************/
#include "blackjack.h"
#include <crtdbg.h>

int main()
{
	const int start = 200;
	BlackJack game(start);
	game.Prompt_User();

	//Memory leak check
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	return 0;
}