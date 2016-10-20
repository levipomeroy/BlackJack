#include "Random.h"

/**************************************************************
*	Purpose:  The purpose of this function is to populate the
*			  srand thingy so we can get random cards when shuffling.
*	Entry:	  N/A
*	Exit:	  Sets srand to time(NULL).
****************************************************************/
Random::Random()
{
	srand(time(NULL));	//Seed srand for random results
}
/**************************************************************
*	Purpose:  The purpose of this function is give back allocated
*			  memory - clean up.
*	Entry:	  N/A
*	Exit:	  N/A
****************************************************************/
Random::~Random()
{
}
/**************************************************************
*	Purpose:  The purpose of this function is to get the random.
*	Entry:	  int called 'n'
*	Exit:	  Returns random umbers up to the 'n' number.
****************************************************************/
unsigned Random::Get_Random(int n) const
{
	return rand() % n;
}

