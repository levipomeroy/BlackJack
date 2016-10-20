/************************************************************************
* Class: Random
* Purpose: This class sets and displays the cards, setting the structure
*		   for the deck.
*
* Manager functions:
* 	Random()
* 		Populates srand.
*	~Random()
*		Default constructor - doesnt delete any memory.
*
* Methods:
*	Get_Random(int n)
*		Returns random number up to the value 'n'.
*************************************************************************/
#ifndef RANDOM_H
#define RANDOM_H
#include <iostream>
#include <time.h>

class Random
{
public:
	Random();	//Constructor
	~Random();	//Destructor
	unsigned Get_Random(int n) const;	//Returns random number up to 'n'
};

#endif
