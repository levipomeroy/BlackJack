#include "Dealer.h"
#include <iostream>
using std::cout;
using std::endl;

/**************************************************************
*	Purpose:  The purpose of this function is to initialize objects.
*	Entry:	  N/A.
*	Exit:	  N/A.
****************************************************************/
Dealer::Dealer()
{
}
/**************************************************************
*	Purpose:  The purpose of this function is give back allocated
*			  memory - clean up.
*	Entry:	  N/A
*	Exit:	  N/A
****************************************************************/
Dealer::~Dealer()
{
}
/**************************************************************
*	Purpose:  The purpose of this function is to show the dealer's
*			  first card in his hand.
*	Entry:	  N/A
*	Exit:	  Output's the dealers first card and a description.
****************************************************************/
void Dealer::Show_First()
{
	cout << "Dealer's first card is: \n";
	m_dealer_hand.Dealers_First_Card(0);
	cout << "\n\n";
}
/**************************************************************
*	Purpose:  The purpose of this function is clear the old hand,
*			  in preparation for a new hand.
*	Entry:	  N/A
*	Exit:	  Deletes the hand.
****************************************************************/
void Dealer::New_Hand()
{
	m_dealer_hand.Delete_Hand();
}
/**************************************************************
*	Purpose:  The purpose of this function is to display all the
*			  cards in the dealer's hand.
*	Entry:	  N/A
*	Exit:	  Displays all the cards in the dealer's hand.
****************************************************************/
void Dealer::Show_Cards()
{
	cout << "Dealers hand: " << endl;
	m_dealer_hand.Show_Card();
	cout << endl;
}
/**************************************************************
*	Purpose:  The purpose of this function is to return the 
*			  m_dealer_hand of the initial vlaue in the dealer's
*			  hand.
*	Entry:	  N/A
*	Exit:	  Returns m_dealer_hand.Dealers_Start()
****************************************************************/
int Dealer::Get_Value()
{
	return m_dealer_hand.Dealers_Start();
}
/**************************************************************
*	Purpose:  The purpose of this function is to return the
*			  m_dealer_hand of the dealer's hand value.
*	Entry:	  Integer called x
*	Exit:	  Returns m_dealer_hand.Dealers_Hand_Value(x)
****************************************************************/
int Dealer::Get_Current_Value(int x)
{
	return m_dealer_hand.Dealers_Hand_Value(x);
}
/**************************************************************
*	Purpose:  The purpose of this function is to add a new hand,
*			  or deal, to the dealer.
*	Entry:	  Class type: Card called hand.
*	Exit:	  Calls Hand::Add for m_dealer_hand, passing it hand.
****************************************************************/
void Dealer::Deal(Card hand)
{
	m_dealer_hand.Add(hand);
}
