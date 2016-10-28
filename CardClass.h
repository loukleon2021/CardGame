#include<iostream>
#include<iomanip>
#include<fstream>

#ifndef CARD_H
#define CARD_H

using namespace std;


class Card
{
	public:
		Card(int f = 0,int s = 0);          //default constructor which also can be set
		void setCard(int f, int s);         //creates a constructor for testing
		static string faceArray[14];        //string array for all 13 faces of cards. Will explain the +1 below
		static string suitArray[5];         //string array for all 5 suits of cards. Will explain the +1 below
		void toString();                   //basic function to print the current card
		string printFace();
		friend ostream & operator << (ostream & fn, const Card & d);
		bool operator > (const Card & g) const;
		bool operator < (const Card & g) const;
		bool operator == (const Card & g) const;
		bool operator != (const Card & g) const;
		bool operator >= (const Card & g) const;
		bool sameSuit(const Card & g) const;
		int getFace() const;
		int getSuit() const;
	private:
		int face;
		int suit;
};


#endif
