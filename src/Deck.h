/*
 * Deck.h
 *
 *  Created on: Apr 14, 2017
 *      Author: nick
 */

#ifndef DECK_H_
#define DECK_H_

#include <algorithm>
#include <cstdlib>
#include <vector>
#include <ctime>

#include "Card.h"

class Deck {
public:
	Deck() {
		for (int i = 0; i < 4; i++) {
			Suit suit = static_cast<Suit>(i);
			for (int j = 0; j < 13; j++) {
				Val val = static_cast<Val>(j + 2);
				Card card = Card(val, suit);
				deck.push_back(card);
			}
		}

	}
	void shuffle() {
		random_shuffle(deck.begin(), deck.end(), myrandom);

	}
	vector<Card> deal() {
		vector<Card> hand;
		for (int i = 0; i < 5; i++) {
			hand.push_back(deck.back());
			deck.pop_back();
		}
		return hand;
	}

	Card draw() {
		Card c = deck.back();
		deck.pop_back();
		return c;
	}

private:
	vector<Card> deck;
	static int myrandom(int i) {
		srand(time(NULL));
		return rand() % i;
	}

};

#endif /* DECK_H_ */
