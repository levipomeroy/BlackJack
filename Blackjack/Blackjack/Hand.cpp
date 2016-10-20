#include "hand.h"
#include <iostream>
using std::cout;
using std::endl;

/**************************************************************
*	Purpose:  The purpose of this function is to initialize objects.
*	Entry:	  N/A.
*	Exit:	  N/A.
****************************************************************/
Hand::Hand()
{
}
/**************************************************************
*	Purpose:  The purpose of this function is give back allocated
*			  memory - clean up.
*	Entry:	  N/A
*	Exit:	  N/A
****************************************************************/
Hand::~Hand()
{
	delete[]m_hand;
}
/**************************************************************
*	Purpose:  The purpose of this function is to add a new card
*			  to the hand.
*	Entry:	  Class type: Card called newcard
*	Exit:	  makes more room for the new card, copies it over, 
*		      handles memory, and increments the m_number.
****************************************************************/
void Hand::Add(Card newcard)
{
	Card * temp = new Card[m_number + 1];
	for (int i = 0; i < m_number; i++)
	{
		temp[i] = m_hand[i];
	}
	temp[m_number] = newcard;

	delete[]m_hand;
	m_hand = temp;

	m_number++;
}
/**************************************************************
*	Purpose:  The purpose of this function is to display the hand.
*	Entry:	  N/A
*	Exit:	  Displays every card within the hand when called on.
****************************************************************/
void Hand::Show_Card()
{
	for (int i = 0; i < m_number; i++)
	{
		m_hand[i].Display_Card();
		cout << endl;
	}
}
/**************************************************************
*	Purpose:  The purpose of this function is to display the first
*			  card in the dealers hand.
*	Entry:	  Integer called cardnumber
*	Exit:	  Displays the first card within the dealer's hand.
****************************************************************/
void Hand::Dealers_First_Card(int cardnumber)
{
	m_hand[cardnumber].Display_Card();
}
/**************************************************************
*	Purpose:  The purpose of this function is to clear the hand,
*			  in preparation for a new hand to be dealt.
*	Entry:	  N/A
*	Exit:	  Deletes the hand and sets it back to nullptr.
****************************************************************/
void Hand::Delete_Hand()
{
	delete[]m_hand;
	m_hand = nullptr;
	m_number = 0;
}
/**************************************************************
*	Purpose:  The purpose of this function is to calculate the 
*			  total value of the players hand.
*	Entry:	  N/A
*	Exit:	  Calculates the total value of the players hand and
*			  returns it.
****************************************************************/
int Hand::Player_Hand_Value()
{
	int value = 0;
	for (int i = 0; i < m_number; i++)
	{
		value += m_hand[i].Get_Players_Rank();
	}
	cout << value << endl;

	return value;
}
/**************************************************************
*	Purpose:  The purpose of this function is to calculate the
*			  value of the dealers hand at the beggining.
*	Entry:	  N/A
*	Exit:	  Calculates the value of the dealers hand at the
*			  beggining and returns it.
****************************************************************/
int Hand::Dealers_Start()
{
	int value = 0;
	for (int i = 0; i < m_number; i++)
	{
		value += m_hand[i].Get_Rank();
	}
	cout << value << endl;
	return value;
}
/**************************************************************
*	Purpose:  The purpose of this function is to calculate the
*			  total value of the dealers hand.
*	Entry:	  N/A
*	Exit:	  Calculates the total value of the dealers hand and
*			  returns it.
****************************************************************/
int Hand::Dealers_Hand_Value(int x)
{
	int value = 0;
	for (int i = 0; i < m_number; i++)
	{
		value += m_hand[i].Get_Dealers_Rank(x);
	}
	cout << value << endl;
	return value;
}