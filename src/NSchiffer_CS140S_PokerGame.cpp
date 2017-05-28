//============================================================================
// Name        : NSchiffer_CS140S_PokerGame.cpp
// Author      : Nickolas Schiffer
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "Poker.h"

using namespace std;

bool playOrQuit();

int main() {
	while (playOrQuit()) {
		Poker p;
		p.play();
	}
}

bool playOrQuit() {
	char c = ' ';
	cout << "p to play or q to quit.\n\n";
	cin >> c;
	if (c == 'p') {
		cin.clear();
		cin.ignore(1024, '\n');
		return true;
	} else {
		cin.clear();
		cin.ignore(1024, '\n');
		return false;
	}
}
