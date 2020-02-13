#include <iostream>
#include <string>
#include "Card.h"
#include "IDCard.h"

//constructs IDCard by reading input info from user
IDCard::IDCard()
{
	IDCard::readinfo();
}

//Asks for additional information, including ID number and DOB
void IDCard::readinfo()
{
	std::cout << "ID Number: ";
	std::getline(std::cin, IDNumber);
	bool valid = false;
	while (!valid)
	{
		std::cout << "DOB mmddyy (0 if none): ";
		std::getline(std::cin, birth_date);
		valid = Card::validDate(birth_date);  //makes sure entered DOB is valid, then sets valid flag to true
	}
}

//return birthdate of IDCard
std::string IDCard::get_birth_date() const
{
	return birth_date;
}

//prints info on an IDCard
void IDCard::print() const
{
	Card::print();  //first calls base class Card's print function to print basic info
	std::cout << "|     ID # : " << IDNumber << std::endl;  //then prints info specific to ID card
	std::cout << "|      DOB : ";
	printDate(this->get_birth_date());
	std::cout << std::endl << "|";
}