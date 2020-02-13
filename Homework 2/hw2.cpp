/*
PIC 10B 2A, Homework 2
Purpose: Wallet Printer
Author: Michael Ting
Date: 10/17/2019
*/
#include <iostream>
#include <string>
#include <vector>

#include "Card.h"
#include "IDCard.h"
#include "BankCard.h"
#include <stdlib.h>
using namespace std;

int main()
{

	int card_type;  //number from 1-3 (or 0) to flag which card should create to add
	vector<Card*> cards;  //holds pointers to all created cards

	cout << "*******************" << endl;
	cout << "* Wallet Printer! *" << endl;
	cout << "*******************" << endl << endl;

	cout << "Print Cards by selecting the type (0 if done) : " << endl << endl;
	cout << "1. Basic Card" << endl << "2. ID Card" << endl << "3. Bank Card" << endl << endl;

	bool valid = false;

	do
	{
		while (!valid)
		{
			cout << "Card Type: ";
			cin >> card_type;  //gets which card type from user

			//Checks if value was actually a number
			if (cin.fail()) cout << "Invalid Input. Try again.";

			//check if value is between 1 and 3
			else if (card_type < 0 || card_type > 3) cout << "Number must be between 1-3. Try again."; 

			//if it made past these checks, the number is valid
			else valid = true;

			cin.clear();
			cin.ignore(1000, '\n');
			cout << endl;
		}

		if (card_type == 1)  //if card type was 1, create basic Card
		{
			cards.push_back(new Card());
		}

		if (card_type == 2)  //if card type was 2, create IDCard
		{
			cards.push_back(new IDCard());
		}

		if (card_type == 3)  //if card type was 3, create BankCard
		{
			cards.push_back(new BankCard());
		}
		cout << endl;
		valid = false;  //reset valid flag for next input
	} while (card_type != 0);  //if card type was 0, exit loop

	//selection sort algorithm to sort "cards" vector using overridden operator
	for (int j = 0; j < cards.size() - 1; ++j) {

		int min = j;
		for (int i = j + 1; i < cards.size(); ++i) {
			if (*(cards.at(i)) <= *(cards.at(min))) {
				min = i;
			}

		}
		if (min != j)
			swap(cards.at(j), cards.at(min));
	}

	//loop to print all the cards in cards
	for (int i = 0; i < cards.size(); i++)
	{
		cout << " "+string(50, '-');
		cout << endl;
		cards[i]->print();
	}
}