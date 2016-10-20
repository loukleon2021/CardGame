#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>          //This is to be able to use and manipulate the vector
#include<algorithm>      //This is for the iteration swap used for the shuffling of the cards
#include<time.h>
#include"HandClass.h"
using namespace std;


class DeckOfCards
{
	public:
		DeckOfCards();                     //Default Constructor
		void printDeck();                  //This is a function I created for testing purposes we can delete this if you want
		void shuffle();                    //Exactly what it says
		Card dealCard();                   //Exactly what it says
		bool moreCards();                  //Requirement to make sure that there are still more cards or not
		void dealPlayers(Hand & d);
		void dealPlayers(Hand & d, Hand & g);
	private:
		vector<Card> deck;
		int currentCard;
};



//Initializes the deck and sets the current card to -1. This ensures that when dealing, you never miss the first card.
DeckOfCards :: DeckOfCards()  
{
	Card Each;
	int i;
	int k;
	for(i=1;i<5;i++)
	{
		for(k=1;k<14;k++)
		{
			Each.setCard(k,i);
			deck.push_back(Each);
		}
	}
	currentCard = -1;

}



//Troubleshooting Function I made that we can delete
void DeckOfCards :: printDeck()
{
	for (int i = 0; i < deck.size() ; i++)
	{
		deck[i].toString();
	}
}



//Uses indexes to start from the fist card, swapping each card with any random placement 
void DeckOfCards :: shuffle()
{
	srand( time(0) );
	int random;
	for (int i = 0; i < deck.size() ; i++)
	{
		random = rand() % deck.size();
		iter_swap(deck.begin() + i, deck.begin() + random );
	}
}



//Just deals the current card.
Card DeckOfCards :: dealCard()
{
		currentCard += 1;
		return deck[currentCard];
}



//Checks to see if there are more cards or not
bool DeckOfCards :: moreCards()
{
	if(currentCard == deck.size() - 1)
	{
		return false;
	}
	else
	{
		return true;
	}
}


void DeckOfCards :: dealPlayers(Hand & d)
{
	Card c1,c2,c3,c4,c5;
	currentCard+=1;
	c1=deck[currentCard];
	currentCard+=1;
	c2=deck[currentCard];
	currentCard+=1;
	c3=deck[currentCard];
	currentCard+=1;
	c4=deck[currentCard];
	currentCard+=1;
	c5=deck[currentCard];
	d.setHand(c1,c2,c3,c4,c5);
	
}

void DeckOfCards :: dealPlayers(Hand & d, Hand & g)
{
	Card c1,c2,c3,c4,c5;
	currentCard+=1;
	c1=deck[currentCard];
	currentCard+=1;
	c2=deck[currentCard];
	currentCard+=1;
	c3=deck[currentCard];
	currentCard+=1;
	c4=deck[currentCard];
	currentCard+=1;
	c5=deck[currentCard];
	d.setHand(c1,c2,c3,c4,c5);
	
	Card c6,c7,c8,c9,c10;
	currentCard+=1;
	c6=deck[currentCard];
	currentCard+=1;
	c7=deck[currentCard];
	currentCard+=1;
	c8=deck[currentCard];
	currentCard+=1;
	c9=deck[currentCard];
	currentCard+=1;
	c10=deck[currentCard];
	g.setHand(c6,c7,c8,c9,c10);
}









