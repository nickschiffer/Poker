/*
 * Card.h
 *
 *  Created on: Apr 14, 2017
 *      Author: nick
 */

#ifndef CARD_H_
#define CARD_H_

#include <iostream>
#include <string>

using namespace std;

enum Suit {
	HEARTS, SPADES, CLUBS, DIAMONDS
};

//ostream& operator<(ostream& out1, const Suit suit) {
//	const char* s = 0;
//#define PROCESS_VAL(p) case(p): s = #p; break;
//	switch (suit) {
//	PROCESS_VAL(HEARTS)
//		;
//	PROCESS_VAL(SPADES)
//		;
//	PROCESS_VAL(CLUBS)
//		;
//	PROCESS_VAL(DIAMONDS)
//		;
//	}
//#undef PROCESS_VAL
//	return out1 << s;
//}

enum Val {
	ACE = 14,
	TWO = 2,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING
};

//ostream& operator<(ostream& out, const Val value) {
//	const char* s = 0;
//#define PROCESS_VAL(p) case(p): s = #p; break;
//	switch (value) {
//	PROCESS_VAL(ACE)
//		;
//	PROCESS_VAL(TWO)
//		;
//	PROCESS_VAL(THREE)
//		;
//	PROCESS_VAL(FOUR)
//		;
//	PROCESS_VAL(FIVE)
//		;
//	PROCESS_VAL(SIX)
//		;
//	PROCESS_VAL(SEVEN)
//		;
//	PROCESS_VAL(EIGHT)
//		;
//	PROCESS_VAL(NINE)
//		;
//	PROCESS_VAL(TEN)
//		;
//	PROCESS_VAL(JACK)
//		;
//	PROCESS_VAL(QUEEN)
//		;
//	}
//#undef PROCESS_VAL
//	return out << s;
//}
enum Score {
	NONE,
	ONEPAIR,
	TWOPAIR,
	THREEOAK,
	STRAIGHT,
	FLUSH,
	FULLHOUSE,
	FOUROAK,
	STRFLUSH,
	RYLFLUSH
};

class Card {
public:
	Card(Val val, Suit suit) {
		this->val = val;
		this->suit = suit;
	}
	Val getVal() {
		return this->val;
	}
	int getValInt() {
		return (int) this->val;
	}
	Suit getSuit() {
		return this->suit;
	}
	void printCard() {
		switch (val) {
		case ACE:
			cout << "Ace of ";
			break;
		case TWO:
			cout << "Two of ";
			break;
		case THREE:
			cout << "Three of ";
			break;
		case FOUR:
			cout << "Four of ";
			break;
		case FIVE:
			cout << "Five of ";
			break;
		case SIX:
			cout << "Six of ";
			break;
		case SEVEN:
			cout << "Seven of ";
			break;
		case EIGHT:
			cout << "Eight of ";
			break;
		case NINE:
			cout << "Nine of ";
			break;
		case TEN:
			cout << "Ten of ";
			break;
		case JACK:
			cout << "Jack of ";
			break;
		case QUEEN:
			cout << "Queen of ";
			break;
		case KING:
			cout << "King of ";
			break;
		};
		switch (suit) {

		case HEARTS:
			cout << "Hearts.\n\n";
			break;
		case SPADES:
			cout << "Spades.\n\n";
			break;
		case CLUBS:
			cout << "Clubs.\n\n";
			break;
		case DIAMONDS:
			cout << "Diamonds.\n\n";
			break;

		}

	}

private:
	Val val;
	Suit suit;
};

#endif /* CARD_H_ */
