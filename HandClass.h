#include<iostream>
#include<iomanip>
#include<fstream>
#include"CardClass.cpp"
#ifndef HAND_H
#define HAND_H
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
		void setRank(int & r);
		void printRank();
		
	private:
		Card cardOne;
		Card cardTwo;
		Card cardThree;
		Card cardFour;
		Card cardFive;
		string rank;
		
};
#endif
