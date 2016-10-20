#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Blackjack.h"

/**************************************************************
*	Purpose:  The purpose of this function is to initialize objects.
*	Entry:	  N/A
*	Exit:	  Sets m_bank to stack.
****************************************************************/
BlackJack::BlackJack(int stack) : m_bank(stack)
{
}
/**************************************************************
*	Purpose:  The purpose of this function is give back allocated
*			  memory - clean up.
*	Entry:	  N/A
*	Exit:	  N/A
****************************************************************/
BlackJack::~BlackJack()
{

}
/**************************************************************
*	Purpose:  The purpose of this function is to prompt the user
*			  into a game and process his/her bet and results.
*	Entry:	  N/A
*	Exit:	  Prompts the user to play game, takes the user's bet,
*			  deals the cards for dealer and player, and shows them.
****************************************************************/
void BlackJack::Prompt_User()
{
	int selection = 0;	//For the user's decisions
	int bet = 0;	//The amount of the bet
	bool win = false;	//Did i win, true or false

	while (m_bank.Get_Bank() && selection != 2)
	{
		m_push = false;

		cout << "You current bank is: " << m_bank.Get_Bank() << endl;
		cout << "\n1) Play a hand" << endl;
		cout << "2) Quit" << endl;
		cout << "=> ";
		cin >> selection;
		cout << "\n";

		switch (selection)
		{
		case 1:
			do
			{
				cout << "Enter amount for bet: ";
				cin >> bet;

				if (bet > m_bank.Get_Bank())
				{
					cout << "Not enough money! You only have: " << 
						m_bank.Get_Bank() << endl;	//ERROR, lack of funds
				}

			} while (bet > m_bank.Get_Bank());

			m_deck.Shuffle();	//Shuffle game deck
			m_dealer.Deal(m_deck.Deal());	//Deal a card to the dealer
			m_player.Deal(m_deck.Deal());	//Deal a card to the player
			m_dealer.Deal(m_deck.Deal());
			m_player.Deal(m_deck.Deal());
			m_dealer.Show_First();	//Only shows the dealers first card
			m_player.Show_Cards();	//Shows the players whole hand
			cout << "\n";
			win = Player_Prompt(bet);

			if (m_push == false)
			{
				if (win == false)
				{
					bet *= -1; //Make it negative
					m_bank.Set_Bank(bet);	//Subtract the bet

				}
				else
				{
					m_bank.Set_Bank(bet);	//Add the bet
				}
			}

			m_dealer.New_Hand();	//Gets rid of current hand for the dealer
			m_player.New_hand();	//Gets rid of current hand for the player

			break;

		case 2:	//On exit
			if (m_bank.Get_Bank() > 200)
			{
				//You left the casino positive
				cout << "In total, you won: " << m_bank.Get_Bank() - 200 << endl;
			}

			else
			{
				//You left the casino negative
				cout << "In total, you lost: " << 200 - m_bank.Get_Bank() << endl;
			}
			break;

		default:
			{
				cout << "Invalid choice!";	//ERROR, enter 1 or 2
				break;
			}
		}
	}

	if (!m_bank.Get_Bank())	//You're out of money!!
	{
		cout << "________________________________________" << endl;
		cout << "****************************************" << endl;
		cout << "OUT OF MONEY! GAME OVER!" << endl;
		cout << "****************************************" << endl;
		cout << "________________________________________" << endl;
	}
}
/**************************************************************
*	Purpose:  The purpose of this function is get the game going
*		      and process the winner/loser.
*	Entry:	  N/A
*	Exit:	  Prompts the user to to hit or stay, if 'hit' goes through
*			  and deals another card and adjusted the overall value.
*			  If 'stay' then shows the dealers hand and decides a 
*			  winner based on the total value of the user's hand vs.
*			  the dealers and whether either one busts or gets blackjack.
****************************************************************/
bool BlackJack::Player_Prompt(int & bet)
{
	bool bust = false;	//Declares winner, false if player loses
	bool dd = false;
	int player_value = 0;	//Total value of player's hand
	int dealer_value = 0;	//Total value of dealer's hand
	int selection = 1;		//Holds the user decisions
	int doubledown = 0;		//Decides if user wants to double-down when total is 10 or 11
	int split = 0;

	//Calls GetValue to determine total value in player's hand
	player_value = m_player.Get_Value();

	if (player_value == 21)	//Player Blackjack
	{
		cout << "_____________________________" << endl;
		cout << "* BLACKJACK!! You win! *" << endl;
		cout << "_____________________________" << endl;
		bust = true;
	}
	
	if (player_value == 10 || player_value == 11)	//Double down parameter
	{
		cout << "Would you like to double down? (1 for yes)";
		cin >> doubledown;

		if (doubledown == 1 && bet <= (m_bank.Get_Bank() / 2))
		{
			bet += bet;
			dd = true;
			m_player.Deal(m_deck.Deal());
			m_player.Show_Cards();
			player_value = m_player.Get_Value();
			if (player_value == 21)	//Player wins
			{
				cout << "_____________________________" << endl;
				cout << "* BLACKJACK!! You win! *" << endl;
				cout << "_____________________________" << endl;
				bust = true;
			}
			if (player_value > 21)	//Player busts
			{
				cout << "_____________________________" << endl;
				cout << "YOU BUST!!" << endl;
				cout << "_____________________________" << endl;
			}
			if (bust == false && player_value < 22)
			{
				m_dealer.Show_Cards();
				cout << "Dealers Hand = ";
				dealer_value = m_dealer.Get_Value();
				while (dealer_value < 17)
				{
					m_dealer.Deal(m_deck.Deal());
					m_dealer.Show_Cards();
					cout << "Dealers Hand = ";
					dealer_value = m_dealer.Get_Current_Value(dealer_value);
				}
				if (dealer_value<22 && dealer_value>player_value)	//Dealer wins
				{
					cout << "_____________________________" << endl;
					cout << "You LOSE!!!" << endl;
					cout << "_____________________________" << endl;
				}
				else if (dealer_value == player_value)	//No one wins
				{
					m_push = true;
					cout << "_____________________________" << endl;
					cout << "IT'S A TIE!" << endl;
					cout << "_____________________________" << endl;
				}
				else   //Player wins
				{
					cout << "_____________________________" << endl;
					cout << "YOU WIN!!" << endl;
					cout << "_____________________________" << endl;
					bust = true;
				}
			}
		}
		else if (bet > (m_bank.Get_Bank() / 2) && doubledown == 1)
		{
			cout << "You don't have enough money to double down" << endl;
			dd = false;
		}
	}
	if (bust == false && dd == false)
	{
		while (player_value <= 21 && selection == 1 && bust == false)
		{
			cout << "Would you like to hit? (Enter 1 for yes) ";
			cin >> selection;

			if (selection == 1)
			{
				m_player.Deal(m_deck.Deal());	//Deal player another card
				m_player.Show_Cards();	//Show players whole hand again

				player_value = m_player.Get_Value();	//Get total of players hand

				if (player_value == 21)	//Player wins
				{
					cout << "_____________________________" << endl;
					cout << "* BLACKJACK!! You win! *" << endl;
					cout << "_____________________________" << endl;
					bust = true;
				}

				if (player_value > 21)	//Player busts
				{
					cout << "_____________________________" << endl;
					cout << "YOU BUST!!" << endl;
					cout << "_____________________________" << endl;
				}
			}
		}
		
		if (bust == false && player_value<22 && selection == 0)
		{
			m_dealer.Show_Cards();	//Show dealer's hand

			cout << "Dealers Hand =";
			dealer_value = m_dealer.Get_Value();	//Get total value of dealers hand

			while (dealer_value < 17)
			{
				m_dealer.Deal(m_deck.Deal());	//Deal dealer a new card
				m_dealer.Show_Cards();	//Show dealer's whole hand again

				cout << "Dealers Hand =";
				dealer_value = m_dealer.Get_Current_Value(dealer_value);
			}

			if (dealer_value < 22 && dealer_value > player_value)	//Dealer wins
			{
				cout << "_____________________________" << endl;
				cout << "YOU LOSE!!!" << endl;
				cout << "_____________________________" << endl;
			}

			else if (dealer_value == player_value)	//No one wins
			{
				m_push = true;
				cout << "_____________________________" << endl;
				cout << "IT'S A TIE!" << endl;
				cout << "_____________________________" << endl;
			}

			else   //Player wins
			{
				cout << "_____________________________" << endl;
				cout << "YOU WIN!!" << endl;
				cout << "_____________________________" << endl;
				bust = true;
			}
		}

		else if (selection != 1 && selection != 0)	//ERROR, Invalid input.
		{
			cout << "\nInvalid input, please enter a 0 for 'no' or 1 for 'yes'!" << endl;
			m_push = true;
		}
	}

	return bust;
}
