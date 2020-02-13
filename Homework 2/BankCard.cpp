#include <iostream>
#include <string>
#include "Card.h"
#include "BankCard.h"

//constructs Bank Card by reading input info from user
BankCard::BankCard()
{
	BankCard::readinfo();
}

//Asks for additional information for Bank Card, including account number and CSC
void BankCard::readinfo()
{
	bool valid = false;
	while (!valid)
	{
		std::cout << "Account Number: ";
		std::getline(std::cin, account_number);
		valid = Card::isNumber(account_number); //account number must only be numerical values
	}

	valid = false; //reset valid flag for reading in CSC

	while (!valid)
	{
		std::cout << "Card Security Code : ";
		std::getline(std::cin, CSC);
		valid = BankCard::validCSC(CSC);
	}
}

//Prints info on a Bank Card
void BankCard::print() const
{
	Card::print();  //first prints basic Card info
	std::cout << "| Account# : " << account_number << std::endl;
	std::cout << "|      CSC : " << CSC;  //then prints info special to Bank Cards
	std::cout << std::endl << "|" <<std::endl;
}

//Tests if user inputs a valid CSC
bool BankCard::validCSC(const std::string &testCSC) const
{
	//First, CSC has to be a number
	if (!Card::isNumber(testCSC)) 
	{
		std::cout << "Not a numeric value! Try again." << std::endl;
		return false;
	}
	else
	{
		//if it's a number, must be only 3 digits
		if (testCSC.length() != 3)
		{
			std::cout << "CSC must be exactly 3 digits. Try again." << std::endl;
			return false;
		}
		else return true;
	}
}
