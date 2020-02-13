#include <string>
#include <iostream>

#include "Card.h"

//Constructs a basic Card by calling readinfo
Card::Card()
{
	Card::readinfo();
}

//Asks user for basic Card information including institution name, holder name, and expiration date
void Card::readinfo()
{
	std::cout << "Institution Name: ";
	std::getline(std::cin, institution); //no input cleaning necessary on the name
	std::cout << "Holder Name: ";
	std::getline(std::cin, holder_name);//no input cleaning necessary on the name

	bool valid = false;
	while (!valid) //doesn't let user pass until they input valid expiration date
	{
		std::cout << "Expiration Date (0 if none): ";
		std::getline(std::cin, exp_date);
		valid = Card::validDate(exp_date);
	}
}

//prints out a date, or N/A if date is "0" 
void Card::printDate(const std::string &date) const
{
	if (date == "0") std::cout << "N/A";
	else std::cout << date.substr(0, 2) + "/" + date.substr(2, 2) + "/" + date.substr(4);
}

//prints information all basic cards have: institution, name, and exp date
void Card::print() const
{
	std::cout << "|" << std::endl << "| "+institution << std::endl << "|     name : " << holder_name << std::endl << "|      exp : ";
	Card::printDate(this->get_exp_date());
	std::cout << std::endl << "|" << std::endl;
}

std::string Card::get_exp_date() const
{
	return exp_date;
}

//overrides "less than or equal to" operator for Cards, eariler expiration dates are less than later ones
bool Card::operator <= (const Card &other) const
{
	if (this->get_exp_date() != other.get_exp_date())
	{
		//N/A expiration dates should sink to the bottom, so they automatically are greater
		if (this->get_exp_date() == "0") return false;
		if (other.get_exp_date() == "0") return true;

		//this card's year is less than the other card's year, this is less
		if (stoi(this->get_exp_date().substr(4)) < stoi(other.get_exp_date().substr(4)))
		{
			return true;
		}

		//this card's year is greater than the other card's year, this is neither less than nor equal to
		if (stoi(this->get_exp_date().substr(4)) > stoi(other.get_exp_date().substr(4)))
		{
			return false;
		}

		//this card's month is less than the other card's month, this is less
		if (stoi(this->get_exp_date().substr(0, 2)) < stoi(other.get_exp_date().substr(0, 2))) {
			return true;
		}

		//this card's month is greater than the other card's month, this is neither less than nor equal to
		if (stoi(this->get_exp_date().substr(0, 2)) > stoi(other.get_exp_date().substr(0, 2)))
		{
			return false;
		}

		//only case left if they have identical year and month, if this one's date is strictly greater, this one is greater
		if (stoi(this->get_exp_date().substr(2,2)) > stoi(other.get_exp_date().substr(2,2))) return false;
	}

	//if none of these cases trigger, our date must be less than or equal to the other
	return true;
	
}

//return true if chars in string are only 1-9, false if otherwise
bool Card::isNumber(const std::string &test) const
{
	for (int i = 0; i < test.length(); i++)
	{
		if (test[i] < '0' || test[i] > '9') return false;
	}
	return true;
}

//returns true if valid date, false if not
bool Card::validDate(const std::string &test) const
{
	if (!Card::isNumber(test)) //date must be only numbers
	{
		std::cout << "Not a numeric value! Try again." << std::endl;
		return false;
	}

	if (test == "0") //date can be 0
		return true;

	if (test.length() != 8) //date must be exactly 8 digits long always
	{
		std::cout << "Invalid format. Try Again." << std::endl;
		return false;
	}

	int month = stoi(test.substr(0, 2));
	//month (first 2 characters must be no greater than 12)
	if (month > 12)
	{
		std::cout << "Invalid Month. Try again." << std::endl;
		return false;
	}

	int day = stoi(test.substr(2, 2));
	//date (next 2 character) must be no greater than 31
	if (day > 31) 
	{
		std::cout << "Invalid Day. Try again." << std::endl;
		return false;
	}
	return true;
}