#include<iostream>
#include<iomanip>
#include<fstream>
#include "cardClass.h"
#ifndef CARD_CPP
#define CARD_CPP
using namespace std;


//Default Constructor
Card :: Card(int f, int s)
{
	setCard(f,s);
}

//Constructor
void Card :: setCard(int f, int s)
{
	face = f;
	suit = s;
}

/*This is where I initialized the arrays. When index = 0 is set to NULL to ensure no matter how complex the code gets,
the index of the card will always correspond to the correct card placement.*/
string Card::faceArray[14] = {"NULL","Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};
string Card::suitArray[5] = {"NULL","Spades","Hearts","Clubs","Diamonds"};

//Prints the value of the card
void Card::toString()
{
	string result = faceArray[face] + " of " + suitArray[suit];
	cout << result<< endl;
}


string Card :: printFace()
{
	return faceArray[face];
}


ostream & operator << (ostream & fn, const Card & d)
{
	fn << d.face << " of " << d.suit;
	return fn;
	
}



bool Card :: operator > (const Card & g) const
{
	if(face > g.face)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Card :: operator < (const Card & g) const
{
	if(face < g.face)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Card :: operator == (const Card & g) const
{
	if(face == g.face)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Card :: operator != (const Card & g) const
{
	if(face == g.face)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Card :: operator >= (const Card & g) const
{
	if(face > g.face || face == g.face)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Card :: sameSuit(const Card & g) const
{
	if(suit == g.suit)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Card :: getFace() const
{
	return face;
}

int Card :: getSuit() const
{
	return suit;
}

#endif
