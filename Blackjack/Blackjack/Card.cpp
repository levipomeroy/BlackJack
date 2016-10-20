#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include "Card.h"

/**************************************************************
*	Purpose:  The purpose of this function is to initialize objects.
*	Entry:	  N/A
*	Exit:	  Sets m_rank to rank and m_suit to suit.
****************************************************************/
Card::Card(Rank rank, Suit suit) : m_rank(rank), m_suit(suit)
{ 
}
/**************************************************************
*	Purpose:  The purpose of this function is give back allocated
*			  memory - clean up.
*	Entry:	  N/A
*	Exit:	  N/A
****************************************************************/
Card::~Card()
{
}
/**************************************************************
*	Purpose:  The purpose of this function is to display a card.
*	Entry:	  N/A
*	Exit:	  Displays the rank and suit of a card.
****************************************************************/
void Card::Display_Card()
{
	const char*rank_txt[] = { "Ace","Deuce", "Trey", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen","King" };

	cout << rank_txt[m_rank - 1] << " of " << static_cast<char>(m_suit);
}
/**************************************************************
*	Purpose:  The purpose of this function is to set m_rank to
*			  rank, type: enum Rank.
*	Entry:	  Enum Rank
*	Exit:	  Sets m_rank to rank, type: enum Rank.
****************************************************************/
void Card::Set_Rank(Rank rank)
{
	m_rank = rank;
}
/**************************************************************
*	Purpose:  The purpose of this function is to set m_suit to
*			  suit, type: enum Suit.
*	Entry:	  Enum Suit
*	Exit:	  Sets m_suit to suit, type: enum Suit.
****************************************************************/
void Card::Set_Suit(Suit suit)
{
	m_suit = suit;

}
/**************************************************************
*	Purpose:  The purpose of this function is to return m_rank,
*			  the suit of a card for the instance of the player.
*	Entry:	  N/A
*	Exit:	  Returns m_suit for the player.
****************************************************************/
Card::Rank Card::Get_Players_Rank()
{
	if (m_rank == KING || m_rank == QUEEN || m_rank == JACK)
	{
		m_rank = TEN;	//Face cards equal 10.
	}

	if (m_rank == ACE)
	{
		int selection = 0;

		cout << "\nDo you want your ace to be 1 or 11?";
		cin >> selection;

		if (selection == 1)
		{
			m_rank = ACE;	//Low ace
		}

		else if(selection == 11)
		{
			m_rank = JACK;	//High ace
		}

		else
		{
			cout << "\n Invalid input!\n";
		}
	}
	return m_rank;
}
/**************************************************************
*	Purpose:  The purpose of this function is to return m_rank,
*			  the rank of a card.
*	Entry:	  N/A
*	Exit:	  Returns m_rank.
****************************************************************/
Card::Rank Card::Get_Rank()
{
	if (m_rank == KING || m_rank == QUEEN || m_rank == JACK)
	{
		m_rank = TEN;	//Face cards equal 10.
	}

	if (m_rank == ACE)
	{
		m_rank = JACK;	//Ace is 11, unless specified otherwise
	}

	return m_rank;
}
/**************************************************************
*	Purpose:  The purpose of this function is to return m_rank,
*			  the suit of a card for the instance of the dealer.
*	Entry:	  Integer current.
*	Exit:	  Returns m_suit for the dealer.
****************************************************************/
Card::Rank Card::Get_Dealers_Rank(int current)
{
	if (m_rank == KING || m_rank == QUEEN || m_rank == JACK)
	{
		m_rank = TEN;	//Face cards equal 10.
	}
	if (current>17 && m_rank == ACE)
	{
		m_rank = JACK;
	}
	return m_rank;
}
/**************************************************************
*	Purpose:  The purpose of this function is to return m_suit,
*			  the suit of a card.
*	Entry:	  N/A
*	Exit:	  Returns m_suit.
****************************************************************/
Card::Suit Card::Get_Suit()
{
	return m_suit;
}