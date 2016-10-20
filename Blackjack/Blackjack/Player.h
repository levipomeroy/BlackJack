/************************************************************************
* Class: Player
* Purpose: This class holds an instance of hand that represents the Player's
*		   hand.
*
* Manager functions:
* 	Player()
* 		The default constructor
*	~Player()
*		Default constructor - doesnt delete any memory.
*
* Methods:
*	New_Hand()
*		Clears old hand to prepare for new one.
*	Show_Cards()
*		Displays all the cards in the Player's hand.
*	Hit(Card newcard)
*		Adds a new card
*	Get_Value()
*		Gets the value of the Player's hand.
*	 Deal(Card hand)
*		Deals, adds a new hand.
*************************************************************************/
#ifndef PLAYER_H
#define PLAYER_H
#include "hand.h"

class Player
{
public:
	Player();	//Constructor
	~Player();	//Destructor
	void Show_Cards();	//Displays all the cards 
	void New_hand();	//Clears players hand
	void Hit(Card newcard);	//Adds new card
	int Get_Value();	//Gets the total value of your hand
	void Deal(Card hand);	//Deals, adds new hand

private:
	Hand m_player_hand;
};

#endif