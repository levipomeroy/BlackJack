#include "Player.h"
#include <iostream>
using std::cout;
using std::endl;

/**************************************************************
*	Purpose:  The purpose of this function is to initialize objects.
*	Entry:	  N/A.
*	Exit:	  N/A.
****************************************************************/
Player::Player()
{
}
/**************************************************************
*	Purpose:  The purpose of this function is give back allocated
*			  memory - clean up.
*	Entry:	  N/A
*	Exit:	  N/A
****************************************************************/
Player::~Player()
{
}
/**************************************************************
*	Purpose:  The purpose of this function is to display all the
*			  cards in the player's hand.
*	Entry:	  N/A
*	Exit:	  Displays all the cards in the player's hand.
****************************************************************/
void Player::Show_Cards()
{
	cout << "Players hand: \n";
	m_player_hand.Show_Card();
	cout << "\n";
}
/**************************************************************
*	Purpose:  The purpose of this function is clear the old hand,
*			  in preparation for a new hand.
*	Entry:	  N/A
*	Exit:	  Deletes the hand.
****************************************************************/
void Player::New_hand()
{
	m_player_hand.Delete_Hand();
}
/**************************************************************
*	Purpose:  The purpose of this function is to add a new card
*			  to the player's hand.
*	Entry:	  Class type: Card called newcard.
*	Exit:	  Calls Hand::Add for m_player_hand, passing it newcard.
****************************************************************/
void Player::Hit(Card newcard)
{
	m_player_hand.Add(newcard);
}
/**************************************************************
*	Purpose:  The purpose of this function is to return the
*			  m_player_hand of the value of the players hand.
*	Entry:	  N/A
*	Exit:	  Returns m_player_hand.Player_Hand_Value()
****************************************************************/
int Player::Get_Value()
{
	cout << "Value of your hand: ";
	return m_player_hand.Player_Hand_Value();
	cout << endl;
}
/**************************************************************
*	Purpose:  The purpose of this function is to add a new hand,
*			  or deal, to the player.
*	Entry:	  Class type: Card called hand.
*	Exit:	  Calls Hand::Add for m_player_hand, passing it hand.
****************************************************************/
void Player::Deal(Card hand)
{
	m_player_hand.Add(hand);
}