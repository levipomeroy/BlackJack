/************************************************************************
* Class: Dealer
* Purpose: This class holds an instance of hand that represents the dealers
*		   hand.
*
* Manager functions:
* 	Dealer()
* 		The default constructor
*	~Dealer()
*		Default constructor - doesnt delete any memory.
*
* Methods:
*	Show_First()
*		Displays the dealers first card.
*	New_Hand()
*		Clears old hand to prepare for new one.
*	Show_Cards()
*		Displays all the cards in the dealers hand.
*	Get_Value()
*		Gets the value of the dealers hand.
*	Get_Current_Value(int x)
*		Gets the current value of the dealers hand.
*	 Deal(Card hand)
*		Deals, adds a new hand.
*************************************************************************/
#include "Hand.h"

#ifndef DEALER_H
#define DEALER_H

class Dealer
{
public:
	Dealer();	//Constructor
	~Dealer();	//Destructor
	void Show_First();	//Shows first card
	void New_Hand();	//Clears old hand
	void Show_Cards();	//Displays all cards
	int Get_Value();	//Gets value of hand
	int Get_Current_Value(int x);	//Gets updated value
	void Deal(Card hand);	//Adds new hand, deals

private:
	Hand m_dealer_hand;	//Holds the cards of dealers hand
};

#endif
