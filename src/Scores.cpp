/*
 * Scores.cpp
 *
 *  Created on: Apr 14, 2017
 *      Author: nick
 */

#include "Scores.h"
#include <map>

bool Scores::checkRoyalFlush() {
	vector<Val> interVal;
	vector<Card> pass1;
	vector<Val> flush = { { ACE }, { KING }, { QUEEN }, { JACK }, { TEN } };
	for (Card c : hand) {
		if (std::find(flush.begin(), flush.end(), c.getVal()) != flush.end()) {
			pass1.push_back(c);
		}
	}
	if (pass1.size() < 5)
		return false;
	Suit suit = pass1[0].getSuit();
	for (Card c : pass1) {
		if (c.getSuit() != suit)
			return false;
	}
	vector<Card> temp;
	temp.push_back(Card(ACE, suit));
	temp.push_back(Card(KING, suit));
	temp.push_back(Card(QUEEN, suit));
	temp.push_back(Card(JACK, suit));
	temp.push_back(Card(TEN, suit));
	ptr->setWinningCards(temp);
	return true;

}
bool Scores::checkStraightFlush() {
	//int c = 0;
	vector<Card> temp;
	for (int i = 1; i < (int) hand.size(); i++) {
		if (hand[i].getVal() == hand[i - 1].getVal() + 1) {
			temp.push_back(hand[i]);
		}
	}

	Suit suit = hand[0].getSuit();
	for (Card c : hand) {
		if (c.getSuit() != suit)
			return false;
	}

	if (temp.size() >= 5) {
		ptr->setWinningCards(temp);
		return true;
	} else {
		return false;
	}

}

bool Scores::checkFourOfAKind() {
	map<Val, int> c;
	map<Val, int>::iterator it;
	for (int i = 0; i < (int) hand.size(); i++) {
		++c[hand[i].getVal()];
	}
	for (map<Val, int>::iterator it = c.begin(); it != c.end(); ++it) {
		if (it->second == 4) {
			vector<Card> temp;
			temp.push_back(Card(it->first, HEARTS));
			temp.push_back(Card(it->first, HEARTS));
			temp.push_back(Card(it->first, HEARTS));
			temp.push_back(Card(it->first, HEARTS));
			ptr->setWinningCards(temp);
			return true;
		}
	}
	return false;

}
bool Scores::checkFullHouse() {
	bool threeOAK = false;
	bool pair = false;
	vector<Card> temp;
	map<Val, int> c;
	map<Val, int>::iterator it;
	for (int i = 0; i < (int) hand.size(); i++) {
		++c[hand[i].getVal()];
	}
	for (map<Val, int>::iterator it = c.begin(); it != c.end(); ++it) {
		if (it->second == 3) {
			temp.push_back(Card(it->first, HEARTS));
			threeOAK = true;
		}
	}
	//pair = checkOnePair();

	map<Val, int> d;
	map<Val, int>::iterator it2;
	for (int i = 0; i < (int) hand.size(); i++) {
		++d[hand[i].getVal()];
	}
	for (map<Val, int>::iterator it2 = d.begin(); it2 != d.end(); ++it2) {
		if (it2->second == 2) {
			Val val = it2->first;
			Suit suit = HEARTS;
			Card c = Card(val, suit);
			temp.push_back(c);
			temp.push_back(c);
			pair = true;
		}
	}

	if (threeOAK && pair) {
		ptr->setWinningCards(temp);
		return true;
	} else
		return false;

}
bool Scores::checkFlush() {
	map<Suit, int> c;
	vector<Card> temp;
	for (int i = 0; i < (int) hand.size(); i++) {
		++c[hand[i].getSuit()];
	}
	for (map<Suit, int>::iterator it = c.begin(); it != c.end(); ++it) {
		if (it->second == 5) {
			ptr->setWinningCards(hand);
			return true;
		}
	}
	return false;

}
bool Scores::checkStraight() {
	vector<Card> temp;
//	int c = 0;
	for (int i = 1; i < (int) hand.size(); i++) {
		if (hand[i].getVal() == hand[i - 1].getVal() + 1) {
			temp.push_back(hand[i]);
		}
	}

	if (temp.size() >= 5) {
		ptr->setWinningCards(hand);
		return true;
	} else {
		return false;
	}

}
bool Scores::checkThreeOfAKind() {
	map<Val, int> c;
	map<Val, int>::iterator it;
	for (int i = 0; i < (int) hand.size(); i++) {
		++c[hand[i].getVal()];
	}
	for (map<Val, int>::iterator it = c.begin(); it != c.end(); ++it) {
		if (it->second == 3) {
			vector<Card> temp;
			temp.push_back(Card(it->first, HEARTS));
			temp.push_back(Card(it->first, HEARTS));
			temp.push_back(Card(it->first, HEARTS));
			ptr->setWinningCards(temp);
			return true;
		}
	}
	return false;

}
bool Scores::checkTwoPairs() {
	vector<Card> temp;
	bool pair1, pair2;
	pair1 = pair2 = false;
	map<Val, int> c;
	map<Val, int>::iterator it;
	for (int i = 0; i < (int) hand.size(); i++) {
		++c[hand[i].getVal()];
	}
	for (map<Val, int>::iterator it = c.begin(); it != c.end(); ++it) {
		if (it->second == 2) {
			if (!pair1) {
				temp.push_back(Card(it->first, HEARTS));
				temp.push_back(Card(it->first, HEARTS));
				pair1 = true;
			} else {
				temp.push_back(Card(it->first, HEARTS));
				temp.push_back(Card(it->first, HEARTS));
				ptr->setWinningCards(temp);
				return true;
			}

		}
	}
	return false;

}
bool Scores::checkOnePair() {
	vector<Card> temp;
	map<Val, int> c;
	map<Val, int>::iterator it;
	for (int i = 0; i < (int) hand.size(); i++) {
		++c[hand[i].getVal()];
	}
	for (map<Val, int>::iterator it = c.begin(); it != c.end(); ++it) {
		if (it->second == 2) {
			temp.push_back(Card(it->first, HEARTS));
			temp.push_back(Card(it->first, HEARTS));
			ptr->setWinningCards(temp);
			return true;
		}
	}
	return false;

}
bool Scores::checkNoPairs() {
	for (Card c : hand) {
		Val v = c.getVal();
		for (Card d : hand) {
			if (d.getVal() == v) {
				return false;
			}
		}

	}
	return true;

}
Score Scores::scoreHand() {
	if (checkRoyalFlush()) {
		return RYLFLUSH;
	} else if (checkStraightFlush()) {
		return STRFLUSH;
	} else if (checkFourOfAKind()) {
		return FOUROAK;
	} else if (checkFullHouse()) {
		return FULLHOUSE;
	} else if (checkFlush()) {
		return FLUSH;
	} else if (checkStraight()) {
		return STRAIGHT;
	} else if (checkThreeOfAKind()) {
		return THREEOAK;
	} else if (checkTwoPairs()) {
		return TWOPAIR;
	} else if (checkOnePair()) {
		return ONEPAIR;
	} else {
		return NONE;
	}

}

