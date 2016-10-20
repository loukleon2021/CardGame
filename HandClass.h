#include<iostream>
#include<iomanip>
#include<fstream>
#include"CardClass.h"
using namespace std;


class Hand
{
	public:
		Hand(Card c1 = (0,0), Card c2 = (0,0), Card c3 = (0,0), Card c4 = (0,0),Card c5 = (0,0));
		void setHand(Card c1, Card c2, Card c3, Card c4,Card c5);
		void printHand();
		void sortHand();
		bool onePair();
		bool twoPair();
		bool threeOfAKind();
		bool fourOfAKind();
		bool flush();
		bool straight();
	private:
		Card cardOne;
		Card cardTwo;
		Card cardThree;
		Card cardFour;
		Card cardFive;
};

Hand :: Hand(Card c1, Card c2, Card c3, Card c4,Card c5)
{
	setHand(c1,c2,c3,c4,c5);
}


void Hand :: setHand(Card c1, Card c2, Card c3, Card c4,Card c5)
{
	cardOne = c1;
	cardTwo = c2;
	cardThree = c3;
	cardFour = c4;
	cardFive = c5;
}


void Hand :: printHand()
{
	cardOne.toString();
	cardTwo.toString();
	cardThree.toString();
	cardFour.toString();
	cardFive.toString();
}

void Hand :: sortHand()
{
	Card tempOne,tempTwo;
	Card C[5] = {cardOne,cardTwo,cardThree,cardFour,cardFive};
      Card temp;				// used to hold an array element value in a swap of two elements
      int iteration;  	// controls how many times to pass through the array (go through the loop)
      int index;				// subscript to look at the first of a pair of adjacent element values
 
      for (iteration = 1; iteration < 5; iteration++)             	 
      {  // make one pass through the array - iteration counts how many times
                              		 
            for (index = 0; index < 5 - iteration; index++)  
               // compare adjacent (side-by-side) element values
                 if (C[index] > C[index+1])    // if they're out of order
                 {                         		
                       temp = C[index];           	  // swap them to put them in order
                       C[index] = C[index+1];         	
                       C[index+1] = temp;
                  }																					// otherwise leave them as they are
      }

	
	cardOne = C[0];
	cardTwo = C[1];
	cardThree = C[2];
	cardFour = C[3];
	cardFive = C[4];	
}


bool Hand :: onePair()
{
	if(cardOne == cardTwo || cardOne == cardThree || cardOne == cardFour || cardOne == cardFive)
	{
		return true;
	}
	else if(cardTwo == cardThree || cardTwo == cardFour || cardTwo == cardFive)
	{
		return true;
	}
	else if(cardThree == cardFour || cardThree == cardFive)
	{
		return true;
	}
	else if(cardFour == cardFive)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Hand :: twoPair()
{
	if(cardOne == cardTwo && cardTwo != cardThree && cardThree == cardFour) //c1 & c2
	{
		return true;
	}
	else if(cardOne == cardTwo && cardTwo != cardThree && cardThree == cardFive)
	{
		return true;
	}
	else if(cardOne == cardTwo && cardTwo != cardFour && cardFour == cardFive)
	{
		return true;
	}
	else if(cardOne == cardThree && cardThree != cardFour && cardFour == cardFive) //c1 & c3
	{
		return true;
	}
	else if(cardOne == cardThree && cardThree != cardTwo && cardTwo == cardFour) 
	{
		return true;
	}
	else if(cardOne == cardThree && cardThree != cardTwo && cardTwo == cardFive)
	{
		return true;
	}
	else if(cardOne == cardFour && cardFour != cardTwo && cardTwo == cardThree) //c1 & c4
	{
		return true;
	}
	else if(cardOne == cardFour && cardFour != cardTwo && cardTwo == cardFive)
	{
		return true;
	}
	else if(cardOne == cardFour && cardFour != cardThree && cardThree == cardFive)
	{
		return true;
	}
	else if(cardOne == cardFive && cardFive != cardTwo && cardTwo == cardThree) //c1 & c5
	{
		return true;
	}
	else if(cardOne == cardFive && cardFive != cardTwo && cardTwo == cardFour)
	{
		return true;
	}
	else if(cardOne == cardFive && cardFive != cardThree && cardThree == cardFour)
	{
		return true;
	}
	else if(cardTwo == cardThree && cardThree != cardFour && cardFour == cardFive) //!c1
	{
		return true;
	}
	else if(cardTwo == cardFour && cardFour != cardThree && cardThree == cardFive)
	{
		return true;
	}
	else if(cardTwo == cardFive && cardFive != cardThree && cardThree == cardFour)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Hand :: threeOfAKind()
{
	if(cardOne == cardTwo && cardTwo == cardThree)
	{
		return true;
	}
	else if(cardOne == cardTwo && cardTwo == cardFour)
	{
		return true;
	}
	else if(cardOne == cardTwo && cardTwo == cardFive)
	{
		return true;
	}
	else if(cardOne == cardThree && cardThree == cardFour)
	{
		return true;
	}
	else if(cardOne == cardThree && cardThree == cardFive)
	{
		return true;
	}
	else if(cardOne == cardFour && cardFour == cardFive)
	{
		return true;
	}
	else if(cardTwo == cardThree && cardThree == cardFour)
	{
		return true;
	}
	else if(cardTwo == cardThree && cardThree == cardFive)
	{
		return true;
	}
	else if(cardTwo == cardFour && cardFour == cardFive)
	{
		return true;
	}
	else if(cardThree == cardFour && cardFour == cardFive)
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool Hand :: fourOfAKind()
{
	if(cardOne == cardTwo && cardTwo == cardThree && cardThree == cardFour)
	{
		return true;
	}
	else if(cardTwo == cardThree && cardThree == cardFour && cardFour == cardFive)
	{
		return true;
	}
	else if(cardOne == cardTwo && cardTwo == cardThree && cardThree == cardFive)
	{
		return true;
	}
	else if(cardOne == cardThree && cardThree == cardFour && cardFour == cardFive)
	{
		return true;
	}
	else if(cardOne == cardTwo && cardTwo == cardFour && cardFour == cardFive)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Hand :: flush()
{
	if(cardOne.sameSuit(cardTwo) && cardOne.sameSuit(cardThree) && cardOne.sameSuit(cardFour) && cardOne.sameSuit(cardFive))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Hand :: straight() //not finished
{
	if(cardOne == cardTwo && cardTwo == cardThree && cardThree == cardFour && cardFour == cardFive)
	{
		return true;
	}
	else
	{
		return false;
	}
}

