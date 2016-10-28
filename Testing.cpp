#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<algorithm>
#include"DeckOfCards2.cpp"
#include"CardClass.cpp"
#include"HandClass.cpp"




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
	theirHand.printHand();
	myHand.compareHand(theirHand);
	return 0;
}
