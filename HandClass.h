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
		Card twoPair();
		int Pair();
		int threeOfAKind();
		int fourOfAKind();
		bool hasPair();
		bool hastwoPair();
		bool hasthreeOfAKind();
		bool hasfourOfAKind();
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


int Hand :: Pair()
{
	if(cardOne == cardTwo || cardOne == cardThree || cardOne == cardFour || cardOne == cardFive)
	{
		return cardOne.getFace();
	}
	else if(cardTwo == cardThree || cardTwo == cardFour || cardTwo == cardFive)
	{
		return cardTwo.getFace();
	}
	else if(cardThree == cardFour || cardThree == cardFive)
	{
		return cardTwo.getFace();
	}
	else if(cardFour == cardFive)
	{
		return cardFour.getFace();
	}
	else
	{
		return 0;
	}
}



Card Hand :: twoPair()
{
	Card notACard;
	if(cardOne == cardTwo && cardTwo != cardThree && cardThree == cardFour) //c1 & c2
	{
		notACard.setCard(cardOne.getFace(),cardThree.getFace());
		return notACard;
	}
	else if(cardOne == cardTwo && cardTwo != cardThree && cardThree == cardFive)
	{
		notACard.setCard(cardOne.getFace(),cardThree.getFace());
		return notACard;
	}
	else if(cardOne == cardTwo && cardTwo != cardFour && cardFour == cardFive)
	{
		notACard.setCard(cardOne.getFace(),cardFour.getFace());
		return notACard;
	}
	else if(cardOne == cardThree && cardThree != cardFour && cardFour == cardFive) //c1 & c3
	{
		notACard.setCard(cardOne.getFace(),cardFour.getFace());
		return notACard;
	}
	else if(cardOne == cardThree && cardThree != cardTwo && cardTwo == cardFour) 
	{
		notACard.setCard(cardOne.getFace(),cardTwo.getFace());
		return notACard;
	}
	else if(cardOne == cardThree && cardThree != cardTwo && cardTwo == cardFive)
	{
		notACard.setCard(cardOne.getFace(),cardTwo.getFace());
		return notACard;
	}
	else if(cardOne == cardFour && cardFour != cardTwo && cardTwo == cardThree) //c1 & c4
	{
		notACard.setCard(cardOne.getFace(),cardTwo.getFace());
		return notACard;
	}
	else if(cardOne == cardFour && cardFour != cardTwo && cardTwo == cardFive)
	{
		notACard.setCard(cardOne.getFace(),cardTwo.getFace());
		return notACard;
	}
	else if(cardOne == cardFour && cardFour != cardThree && cardThree == cardFive)
	{
		notACard.setCard(cardOne.getFace(),cardThree.getFace());
		return notACard;
	}
	else if(cardOne == cardFive && cardFive != cardTwo && cardTwo == cardThree) //c1 & c5
	{
		notACard.setCard(cardOne.getFace(),cardTwo.getFace());
		return notACard;
	}
	else if(cardOne == cardFive && cardFive != cardTwo && cardTwo == cardFour)
	{
		notACard.setCard(cardOne.getFace(),cardTwo.getFace());
		return notACard;
	}
	else if(cardOne == cardFive && cardFive != cardThree && cardThree == cardFour)
	{
		notACard.setCard(cardOne.getFace(),cardThree.getFace());
		return notACard;
	}
	else if(cardTwo == cardThree && cardThree != cardFour && cardFour == cardFive) //!c1
	{
		notACard.setCard(cardTwo.getFace(),cardFour.getFace());
		return notACard;
	}
	else if(cardTwo == cardFour && cardFour != cardThree && cardThree == cardFive)
	{
		notACard.setCard(cardTwo.getFace(),cardThree.getFace());
		return notACard;
	}
	else if(cardTwo == cardFive && cardFive != cardThree && cardThree == cardFour)
	{
		notACard.setCard(cardTwo.getFace(),cardThree.getFace());
		return notACard;
	}
	else
	{
		notACard.setCard(0,0);
		return notACard;
	}
}

int Hand :: threeOfAKind()
{
	if(cardOne == cardTwo && cardTwo == cardThree && cardThree != cardFour && cardThree != cardFive)
	{
		return cardOne.getFace();
	}
	else if(cardOne == cardTwo && cardTwo == cardFour && cardFour != cardThree && cardFour != cardFive)
	{
		return cardOne.getFace();
	}
	else if(cardOne == cardTwo && cardTwo == cardFive && cardFive != cardThree && cardFive != cardFour)
	{
		return cardOne.getFace();
	}
	else if(cardOne == cardThree && cardThree == cardFour && cardFour != cardTwo && cardFour != cardFive)
	{
		return cardOne.getFace();
	}
	else if(cardOne == cardThree && cardThree == cardFive && cardFive != cardTwo && cardFive != cardFour)
	{
		return cardOne.getFace();
	}
	else if(cardOne == cardFour && cardFour == cardFive && cardFive != cardTwo && cardFive != cardThree)
	{
		return cardOne.getFace();
	}
	else if(cardTwo == cardThree && cardThree == cardFour && cardFour != cardOne && cardFour != cardFive)
	{
		return cardTwo.getFace();
	}
	else if(cardTwo == cardThree && cardThree == cardFive && cardFive != cardOne && cardFive != cardFour)
	{
		return cardTwo.getFace();
	}
	else if(cardTwo == cardFour && cardFour == cardFive && cardFive != cardOne && cardFive != cardThree)
	{
		return cardTwo.getFace();
	}
	else if(cardThree == cardFour && cardFour == cardFive && cardFive != cardOne && cardFive != cardTwo)
	{
		return cardThree.getFace();
	}
	else
	{
		return 0;
	}

}

int Hand :: fourOfAKind()
{
	if(cardOne == cardTwo && cardTwo == cardThree && cardThree == cardFour && cardFour != cardFive)
	{
		return cardOne.getFace();
	}
	else if(cardTwo == cardThree && cardThree == cardFour && cardFour == cardFive && cardFive != cardOne)
	{
		return cardTwo.getFace();
	}
	else if(cardOne == cardTwo && cardTwo == cardThree && cardThree == cardFive && cardFive != cardFour)
	{
		return cardOne.getFace();
	}
	else if(cardOne == cardThree && cardThree == cardFour && cardFour == cardFive && cardFive != cardTwo)
	{
		return cardOne.getFace();
	}
	else if(cardOne == cardTwo && cardTwo == cardFour && cardFour == cardFive && cardFive != cardThree)
	{
		return cardOne.getFace();
	}
	else
	{
		return 0;
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


bool Hand :: hasPair()
{
	int x = Pair();
	if(x != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
