/*
 * Poker.cpp
 *
 *  Created on: Apr 14, 2017
 *      Author: nick
 */

#include "Poker.h"

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

#include "Card.h"
#include "Deck.h"

void Poker::play() {
//	while (playOrQuit()) {
	newDeck();
	inputPlayers();

	for (int i = 0; i < (int) players.size(); i++) {
		vector<Card> hand = deck.deal();
		players[i].setHand(hand);
		cout << players[i].getName() << "'s hand is:\n\n";
		for (Card c : hand) {
			c.printCard();
		}
		cout << endl;

		discard(i);

		Scores s = Scores(players[i]);
		Score pScore = s.score(players[i]);

		players[i].setScore(pScore);

	}
	for (int i = 0; i < (int) players.size(); i++) {
		cout << players[i].getName() << "'s hand is:\n\n";
		for (Card c : players[i].getHand()) {
			c.printCard();
		}
		cout << endl;
	}

	vector<Player> victors = winner();

	cout << "The Winner is: " << victors[0].getName() << " with ";
	victors[0].getScoreString();
//	}
}

void Poker::newDeck() {
	deck = Deck();
	deck.shuffle();
}

void Poker::inputPlayers() {
	int i;
	cout << "How many players?";
	cin >> i;
	for (int j = 0; j < i; j++) {
		string name;
		cout << "Please Enter Player #" << j + 1 << "'s name.\n\n";
		cin >> name;
		Player p = Player(name);
		players.push_back(p);
	}
}

void Poker::discard(int indx) {
	int choice = 0;
	vector<int> choices;
	Player p = players[indx];

	cout << "Player: " << p.getName()
			<< ". Would you like to discard any cards? (ie 0-5)\n\n";
	cin >> choice;
	string str;

	cin.clear();

	vector<Card> tempHand = p.getHand();
	if (choice != 0) {
		for (int i = 0; i < choice; i++) {
			int j = 0;
			cout << "Card #" << i + 1 << " of " << choice << ".\n\n";
			cin >> j;
			tempHand[j - 1] = deck.draw();

		}
	}
	players[indx].setHand(tempHand);
}
template<typename T>
T convertToType(const std::string &stringType) {
	std::stringstream iss(stringType);
	T rtn;
	return iss >> rtn ? rtn : 0;
}

vector<Player> Poker::winner() {
	bool none = false;
	struct {
		bool operator()(Player a, Player b) {
			return a.getScore() < b.getScore();
		}
	} customLessScore;
	sort(players.begin(), players.end(), customLessScore);

	struct {
		bool operator()(Player a, Player b) {
			return a.getHighVal() < b.getHighVal();
		}
	} customLessVal;

	struct {
		bool operator()(Player a, Player b) {
			return a.getHighSuit() < b.getHighSuit();
		}
	} customLessSuit;
	struct {
		bool operator()(Player a, Player b) {
			return a.getHighVal(true) < b.getHighVal(true);
		}
	} customLessValWin;

	struct {
		bool operator()(Player a, Player b) {
			return a.getHighSuit(true) < b.getHighSuit(true);
		}
	} customLessSuitWin;

	vector<Score> scores;

	vector<vector<Card> > hands;
	vector<Player> winners;
	Score highScore = players[players.size() - 1].getScore();
	none = (highScore == NONE);
	if (none) {
		for (Player p : players) {
			if (p.getScore() == highScore) {
				winners.push_back(p);
			}
		}

		if (winners.size() > 1) {
			sort(winners.begin(), winners.end(), customLessVal);
			vector<Player> tempWinners;
			Card high = winners[winners.size() - 1].getHighCard();
			for (Player p : players) {
				if (p.getHighCard().getVal() == high.getVal()) {
					tempWinners.push_back(p);
				}
			}
			winners = tempWinners;
		}

		if (winners.size() > 1) {
			sort(winners.begin(), winners.end(), customLessSuit);
			vector<Player> tempWinners;
			Card high = winners[winners.size() - 1].getHighCard();
			for (Player p : winners) {
				if (p.getHighCard().getSuit() == high.getSuit()) {
					tempWinners.push_back(p);
				}
			}
			winners = tempWinners;
		}
		return winners;
	} else {
		for (Player p : players) {
			if (p.getScore() == highScore) {
				winners.push_back(p);
			}
		}

		if (winners.size() > 1) {
			sort(winners.begin(), winners.end(), customLessValWin);
			vector<Player> tempWinners;
			Card high = winners[winners.size() - 1].getHighCard(true);
			for (Player p : winners) {
				if (p.getHighCard(true).getVal() == high.getVal()) {
					tempWinners.push_back(p);
				}
			}
			winners = tempWinners;
		}

		if (winners.size() > 1) {
			sort(winners.begin(), winners.end(), customLessSuitWin);
			vector<Player> tempWinners;
			Card high = winners[winners.size() - 1].getHighCard(true);
			for (Player p : players) {
				if (p.getHighCard(true).getSuit() == high.getSuit()) {
					tempWinners.push_back(p);
				}
			}
			winners = tempWinners;
		}
		return winners;
	}

}
