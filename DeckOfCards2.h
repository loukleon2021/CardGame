#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>          //This is to be able to use and manipulate the vector
#include<algorithm>      //This is for the iteration swap used for the shuffling of the cards
#include<time.h>
#include"HandClass.cpp"
#include"CardClass.cpp"

#ifndef DECK_H
#define DECK_H
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




#endif





