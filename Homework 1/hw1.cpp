/*
PIC 10B 2A, Homework 1
Purpose: Tic-tac-toe game
Author: Michael Ting
Date: 10/16/2019
*/

#include <iostream>
#include <string>
#include <vector>

#include "Person.h"
#include "Game.h"

using namespace std;

int main()
{
	string name1, name2;
	int rounds;

	cout << "Please enter Player 1's name: ";
	getline(cin, name1);
	cout << "Please enter Player 2's name: ";
	getline(cin, name2);

	cout << "How many rounds would you like to play? ";
	
	bool wrong = true;
	while (wrong)
	{
		cin >> rounds;
		if (!cin.fail()) //input wasn't a number
		{
			cout << endl;
			wrong = false;
		}
		else {
			cout << "Try again. How many rounds? ";
			cin.clear();
			cin.ignore(INT_MAX, '\n'); //ignores previous input
		}
	}

	Game game = Game(name1, name2, rounds);
	game.start_round();
	bool finished = false;
	while (!finished) {
		game.update_board();
		finished = game.endphase(); //loop breaks when finished becomes true, which happens when endgame returns true,	
									//which happens when the last rounds has finished
	}

}