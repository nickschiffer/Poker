/*
 * Scores.h
 *
 *  Created on: Apr 14, 2017
 *      Author: nick
 */

#ifndef SCORES_H_
#define SCORES_H_

#include "Deck.h"
#include "Player.h"

class Scores {
public:
	Scores(Player& p) {
		hand = p.getHand();
		ptr = &p;
		//sort(this->hand.begin(), this->hand.end());

		struct {
			bool operator()(Card a, Card b) {
				return a.getValInt() < b.getValInt();
			}
		} customLess;
		sort(this->hand.begin(), this->hand.end(), customLess);
	}
	Score score(Player p) {
		return scoreHand();
	}

private:
	vector<Card> hand;
	Player* ptr;
	Score scoreHand(); //Returns Highest Score from hand
	bool checkRoyalFlush();
	bool checkStraightFlush();
	bool checkFourOfAKind();
	bool checkFullHouse();
	bool checkFlush();
	bool checkStraight();
	bool checkThreeOfAKind();
	bool checkTwoPairs();
	bool checkOnePair();
	bool checkNoPairs();
};

#endif /* SCORES_H_ */
