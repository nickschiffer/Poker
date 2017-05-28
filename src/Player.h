/*
 * Player.h
 *
 *  Created on: Apr 14, 2017
 *      Author: nick
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Deck.h"

class Player {
public:
	Player(string name) {
		this->score = NONE;
		this->name = name;
	}
	Player() {
		this->score = NONE;
	}

	string getName() {
		return name;
	}
	void getScoreString() {
		switch (score) {
		case NONE:
			cout << "None.\n";
			break;
		case ONEPAIR:
			cout << "One Pair.\n";
			break;
		case TWOPAIR:
			cout << "Two Pairs.\n";
			break;
		case THREEOAK:
			cout << "A Three of a kind.\n";
			break;
		case STRAIGHT:
			cout << "A Straight.\n";
			break;
		case FLUSH:
			cout << "A Flush.\n";
			break;
		case FULLHOUSE:
			cout << "A Full House.\n";
			break;
		case FOUROAK:
			cout << "A Four of a kind.\n";
			break;
		case STRFLUSH:
			cout << "A Straight Flush.\n";
			break;
		case RYLFLUSH:
			cout << "A Royal Flush.\n";
			break;
		default:
			break;
		}
	}

	Score getScore() {
		return score;
	}

	void setScore(Score score) {
		this->score = score;
	}

	vector<Card> getHand() {
		return hand;
	}

	vector<Card> getWinningCards() {
		return winningCards;
	}

	void setHand(vector<Card> hand) {
		this->hand = hand;
	}

	void setWinningCards(vector<Card> winningCards) {
		this->winningCards = winningCards;
	}

	Card getHighCard(bool wc = false) {
		vector<Card> tempHand = (wc) ? winningCards : hand;
		struct {
			bool operator()(Card a, Card b) {
				return a.getVal() < b.getVal();
			}
		} customLess2;
		sort(tempHand.begin(), tempHand.end(), customLess2);
		return tempHand[tempHand.size() - 1];
	}

	Val getHighVal(bool wc = false) {
		vector<Card> tempHand = (wc) ? winningCards : hand;
		struct {
			bool operator()(Card a, Card b) {
				return a.getVal() < b.getVal();
			}
		} customLessVal;
		sort(tempHand.begin(), tempHand.end(), customLessVal);
		return tempHand[tempHand.size() - 1].getVal();
	}

	Suit getHighSuit(bool wc = false) {
		vector<Card> tempHand = (wc) ? winningCards : hand;
		struct {
			bool operator()(Card a, Card b) {
				return a.getSuit() < b.getSuit();
			}
		} customLessSuit;
		sort(tempHand.begin(), tempHand.end(), customLessSuit);
		return tempHand[tempHand.size() - 1].getSuit();
	}

private:
	Score score;
	string name;
	vector<Card> hand;
	vector<Card> winningCards;
};

#endif /* PLAYER_H_ */
