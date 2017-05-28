/*
 * Poker.h
 *
 *  Created on: Apr 14, 2017
 *      Author: nick
 */

#ifndef POKER_H_
#define POKER_H_

#include "Scores.h"
#include <map>
#include <vector>
#include "Player.h"

class Poker {

public:
	Poker() {

	}

	void play();

	void newDeck();
	bool playOrQuit();

private:

	Deck deck;
	vector<Player> players; //name and Score

	void inputPlayers();
	void discard(int indx);
	vector<Player> winner();

};

#endif /* POKER_H_ */
