#include "Bankroll.h"

/**************************************************************
*	Purpose:  The purpose of this function is to initialize objects.
*	Entry:	  N/A
*	Exit:	  Sets m_current_bank to stack.
****************************************************************/
Bankroll::Bankroll(int stack) : m_current_bank(stack)
{
}
/**************************************************************
*	Purpose:  The purpose of this function is give back allocated
*			  memory - clean up.
*	Entry:	  N/A
*	Exit:	  N/A
****************************************************************/
Bankroll::~Bankroll()
{
}
/**************************************************************
*	Purpose:  The purpose of this function is to return m_current_bank,
*			  the amount a player currently has in his bank.
*	Entry:	  N/A
*	Exit:	  Returns m_current_bank.
****************************************************************/
int Bankroll::Get_Bank()
{
	return m_current_bank;
}
/**************************************************************
*	Purpose:  The purpose of this function is to set m_current_bank
*			  to the sum of bank;
*	Entry:	  Integer called bank.
*	Exit:	  sets m_current_bank to the sum of bank.
****************************************************************/
void Bankroll::Set_Bank(int bank)
{
	m_current_bank += bank;
}
