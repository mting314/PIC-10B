#pragma once
#include <iostream>
#include <string>
#include "Card.h"
#ifndef IDCard_h
#define IDCard_h

class IDCard : public Card
{
private:
	std::string IDNumber;
	std::string birth_date;
public:
	IDCard();

	void readinfo();
	std::string get_birth_date() const;
	void print() const;
};


#endif