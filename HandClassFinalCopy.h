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
		string compareHighCard(Hand & g);
		void compareHand(Hand & g);
		Card twoPair();
		Card fullHouse();
		int Pair();
		int threeOfAKind();
		int fourOfAKind();
		int straight();
		int judgeHand();
		int highCard();
		bool hasPair();
		bool hasTwoPair();
		bool hasFullHouse();
		bool hasThreeOfAKind();
		bool hasFourOfAKind();
		bool flush();
		bool hasStraight();
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
	sortHand();
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
	if(cardOne == cardTwo)
	{
		return cardOne.getFace();
	}
	else if(cardTwo == cardThree)
	{
		return cardTwo.getFace();
	}
	else if(cardThree == cardFour)
	{
		return cardThree.getFace();
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
	if(cardOne == cardTwo && cardTwo != cardThree && cardThree == cardFour && cardFour != cardFive) //c1 & c2
	{
		notACard.setCard(cardOne.getFace(),cardThree.getFace());
		return notACard;
	}
	else if(cardOne == cardTwo && cardTwo != cardFour && cardFour == cardFive && cardThree != cardTwo && cardThree != cardFour)
	{
		notACard.setCard(cardOne.getFace(),cardThree.getFace());
		return notACard;
	}
	else if(cardOne != cardTwo && cardTwo == cardThree && cardThree != cardFour && cardFour == cardFive)
	{
		notACard.setCard(cardTwo.getFace(),cardFour.getFace());
		return notACard;
	}
	else
	{
		notACard.setCard(0,0);
		return notACard;
	}
}

Card Hand :: fullHouse() //needs to be done. all I did was copy the two of a kind
{
	Card notACard;
	if(cardOne == cardTwo && cardTwo != cardThree && cardThree == cardFour && cardThree ==cardFive)
	{
		notACard.setCard(cardThree.getFace(),cardOne.getFace());
		return notACard;
	}
	else if(cardOne == cardTwo && cardOne == cardThree && cardThree != cardFour && cardFour == cardFive) //c1 & c3
	{
		notACard.setCard(cardOne.getFace(),cardFour.getFace());
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
	else if(cardTwo == cardThree && cardThree == cardFour && cardFour != cardOne && cardFour != cardFive)
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

int Hand :: straight() 
{
	if(cardOne.getFace() + 1 == cardTwo.getFace()  && cardTwo.getFace() + 1 == cardThree.getFace() && cardThree.getFace() + 1 == cardFour.getFace() && cardFour.getFace() + 1 == cardFive.getFace())
	{
		if(cardOne.getFace() != 1)
		{
			return cardFive.getFace();
		}
		else
		{
			return cardOne.getFace();
		}
	}
	else
	{
		return 0;
	}
}

bool Hand :: hasStraight()
{
	int x = straight();
	if(x != 0)
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
	int y = threeOfAKind();
	int z = fourOfAKind();
	Card testTwoPair = twoPair();
	if(x != 0 && y == 0 && z == 0 && testTwoPair.getFace() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Hand :: hasTwoPair()
{
	int x = Pair();
	int y = threeOfAKind();
	int z = fourOfAKind();
	Card testTwoPair = twoPair();
	if(x != 0 && y == 0 && z == 0 && testTwoPair.getFace() != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Hand :: hasFullHouse()
{
	Card testFullHouse = fullHouse();
	if(testFullHouse.getFace() != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool Hand :: hasThreeOfAKind()
{
	int x = Pair();
	int y = threeOfAKind();
	int z = fourOfAKind();
	Card testTwoPair = twoPair();
	if(x != 0 && y != 0 && z == 0 && testTwoPair.getFace() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Hand :: hasFourOfAKind()
{
	int x = Pair();
	int y = threeOfAKind();
	int z = fourOfAKind();
	Card testTwoPair = twoPair();
	if(x != 0 && y == 0 && z != 0 && testTwoPair.getFace() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


int Hand :: judgeHand()
{	
	int score = 0;
	int Straight = straight();
	if(straight() == true && flush() == true)
	{
		score = 9;
	}
	else if(hasFourOfAKind() == true)
	{
		score = 8;
	}
	else if(hasFullHouse() == true)
	{
		score = 7;
	}
	else if(flush() == true && straight() == false)
	{
		score = 6;
	}
	else if(straight() == true && flush() == false)
	{
		score = 5;
	}
	else if(hasThreeOfAKind() == true)
	{
		score = 4;
	}
	else if(hasTwoPair() == true)
	{
		score = 3;
	}
	else if(hasPair() == true)
	{
		score = 2;
	}
	else
	{
		score = 1; //high card
	}
	return score;
}


int Hand :: highCard()
{
	if (cardOne.getFace() != 1)
	{
		return cardFive.getFace();
	}
	else
	{
		return cardOne.getFace();
	}
}

string Hand :: compareHighCard(Hand & g)
{
	int p1 = highCard();
	int p2 = g.highCard();
	string result;
	if(p1 != 1 && p2 != 1 && p1 > p2)
	{
		result = "Player One wins with a high card of " + cardFive.printFace();
	}
	else if(p1 != 1 && p2 != 1 && p1 < p2)
	{
		result = "Player Two wins with a high card of " + g.cardFive.printFace();
	}
	else if(p1 == 1 && p2 != 1)
	{
		result = "Player One wins with a high card of " + cardOne.printFace();
	}
	else if(p1 != 1 && p2 == 1)
	{
		result = "Player Two wins with a high card of " + g.cardOne.printFace();
	}
	else
	{
		result = "It is a tie!";
	}
	
	return result;
	
}




void Hand :: compareHand(Hand & g)
{
	
	int playerOne = judgeHand();
	int playerTwo = g.judgeHand();
	
	if(playerOne > playerTwo)
	{
		cout << "Player One Wins!"<< endl;
	}
	else if(playerOne < playerTwo)
	{
		cout << "Player Two Wins!" << endl;
	}
	else if(playerOne == playerTwo)
	{
		if(playerOne == 1)
		{
			cout << compareHighCard(g);
		}
		else if(playerOne == 2)
		{
			int P1P = Pair();
			int P2P = g.Pair();
			Card winner;
			if(P1P == 1 && P2P != 1 || P1P > P2P)
			{
				winner.setCard(P1P,0);
				cout << "Player One Wins with a pair of " << winner.printFace() <<"'s"<< endl; 
			}
			else if(P2P == 1 && P1P != 1 || P1P < P2P)
			{
				winner.setCard(P2P,0);
				cout << "Player Two Wins with a pair of " << winner.printFace() <<"'s"<< endl; 
			}
			else
			{
				cout << compareHighCard(g);
			}
		}
		else if(playerOne == 3)
		{
			Card P12P = twoPair();
			Card P22P = g.twoPair();
			Card firstPair, secondPair;
			if(P12P.getFace() == 1 && P22P.getFace() != 1 || P12P.getSuit() > P22P.getSuit())
			{
				firstPair.setCard(P12P.getSuit(),0);
				secondPair.setCard(P12P.getFace(),0);
				cout << "Player One wins with two pairs of " << firstPair.printFace() << "'s and " << secondPair.printFace() << "'s"<< endl;
			}
			if(P22P.getFace() == 1 && P12P.getFace() != 1 || P12P.getSuit() > P22P.getSuit())
			{
				firstPair.setCard(P22P.getSuit(),0);
				secondPair.setCard(P22P.getFace(),0);
				cout << "Player One wins with two pairs of " << firstPair.printFace() << "'s and " << secondPair.printFace() << "'s"<< endl;
			}
			else
			{
				firstPair.setCard(P22P.getSuit(),0);
				secondPair.setCard(P22P.getFace(),0);
				cout << "its a tie with two pairs of " << firstPair.printFace() << "'s and " << secondPair.printFace() << "'s"<< endl;
			}
		}	
		else if(playerOne == 4)
		{
			int P1 = hasThreeOfAKind();
			int P2 = g.hasThreeOfAKind();
			Card winner;
			if(P1 == 1 && P2 != 1 || P1 > P2)
			{
				winner.setCard(P1,0);
				cout << "Player One wins with a three of a kind of " << winner.printFace() << endl; 
			}
			else if(P2 == 1 && P1 != 1 || P1 < P2)
			{
				winner.setCard(P2,0);
				cout << "Player One wins with a three of a kind of " << winner.printFace() << endl; 
			}
			else
			{
				cout << compareHighCard(g);
			}
		}
		else if(playerOne == 5)
		{
			cout << compareHighCard(g);
		}
		else if(playerOne == 6)
		{
			cout << compareHighCard(g);
		}
		else if(playerOne == 7)
		{
			Card P1FH = fullHouse();
			Card P2FH = g.fullHouse();
			Card firstPair, secondPair;
			if(P1FH.getFace() == 1 && P2FH.getFace() != 1 || P1FH.getFace() > P2FH.getFace())
			{
				firstPair.setCard(P1FH.getSuit(),0);
				secondPair.setCard(P1FH.getFace(),0);
				cout << "Player One wins with two pairs of " << firstPair.printFace() << "'s and " << secondPair.printFace() << "'s"<< endl;
			}
			if(P2FH.getFace() == 1 && P1FH.getFace() != 1 || P1FH.getFace() > P2FH.getFace())
			{
				firstPair.setCard(P2FH.getSuit(),0);
				secondPair.setCard(P2FH.getFace(),0);
				cout << "Player One wins with two pairs of " << firstPair.printFace() << "'s and " << secondPair.printFace() << "'s"<< endl;
			}
			else
			{
				cout << "Something has to be wrong. Two players cant have a tie for the pair of 3 with only one deck!" << endl;
			}
		}
		else if(playerOne == 8)
		{
			int P1 = hasFourOfAKind();
			int P2 = g.hasFourOfAKind();
			Card winner;
			if(P1 == 1 && P2 != 1 || P1 > P2)
			{
				winner.setCard(P1,0);
				cout << "Player One wins with a four of a kind of " << winner.printFace() << endl; 
			}
			else if(P2 == 1 && P1 != 1 || P1 < P2)
			{
				winner.setCard(P2,0);
				cout << "Player One wins with a four of a kind of " << winner.printFace() << endl; 
			}
			else
			{
				cout << compareHighCard(g);
			}
		}
		else if(playerOne == 9)
		{
			cout << compareHighCard(g);
		}
	}
	
}
