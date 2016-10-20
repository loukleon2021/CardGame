#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<algorithm>
                         //apparently it throws a fit if you try and call Class.h again since its already called in DeckofCards.h
#include"DeckOfCards2.h"




int main()
{
	Hand myHand;
	Hand theirHand;
	DeckOfCards myDeck;                       //creates a DeckOfCards object.
	myDeck.shuffle();                         //shuffles
	//myDeck.printDeck();
	myDeck.dealPlayers(myHand,theirHand);
	myHand.printHand();
	cout<<endl;
	myHand.sortHand();
	myHand.printHand();
	return 0;
}
