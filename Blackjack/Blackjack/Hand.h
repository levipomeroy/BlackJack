/************************************************************************
* Class: Hand
*
* Purpose: This class deals the cards, shuffles them, and keeps track of
*		   the current number dealt.
*
* Manager functions:
* 	Hand()
* 		The default constructor
*	~Hand()
*		Default constructor - frees up memory of m_deck.
*
* Methods:
*	Add(Card newcard)
*		Adds anew card to the hand.
*	Show_Card()
*		Displays a card, called for each card within a hand.
*	Delete_Hand()
*		Clears hand in preparation for a new one.
*	Dealers_Start() :int
*		Calculates th value of the dealers original hand.
*	Player_Hand_Value() :int
*		Calculates the total of the players hand.
*	Dealers_Hand_Value(int x) :int
*		Calculates the total of the dealers hand.
*	Dealers_First_Card(int cardnumber)
*		Displays the first card in the dealers hand only.
*************************************************************************/
#include "Card.h"
#ifndef HAND_H
#define HAND_H

class Hand
{
public:
	Hand();	//Constructor
	~Hand();	//Destructor
	void Add(Card newcard);	//Adds a new card to hand
	void Show_Card();	//Displays a card
	void Delete_Hand();	//Clears a hand
	int Dealers_Start();	//Determines the starting value of dealers hand.
	int Player_Hand_Value();	//Total value of players cards
	int Dealers_Hand_Value(int x);	//Total value of dealers cards
	void Dealers_First_Card(int cardnumber);	//For dealers first card

private:
	Card * m_hand = nullptr;	//Holds the cards that make up the hand
	int m_number = 0;
};

#endif
