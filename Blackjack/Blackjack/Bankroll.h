/************************************************************************
* Class: Bankroll
* Purpose: This class is used to store and keep track of the current ammount
*		   of money a player has in his/her bank.
*
* Manager functions:
* 	Bankroll(int stack)
* 		A one arg constructor that sets m_current_bank to stack.
*	~Bankroll()
*		Default constructor
*
* Methods:
*	Get_Bank()
*		Returns the value in the bank
*	Set_Bank(int bank)
*		Sets the value within the bank.
*************************************************************************/
#ifndef BANKROLL_H
#define BANKROLL_H

class Bankroll
{
public:
	Bankroll(int stack);	//One arg constructor
	int Get_Bank();	//Gets value in bank
	void Set_Bank(int bank);	//Sets the bank value
	~Bankroll();	//Destructor

private:
	int m_current_bank;	//Current balance in the bank
};

#endif