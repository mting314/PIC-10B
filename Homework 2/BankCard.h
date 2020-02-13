#pragma once
#include <iostream>
#include <string>
#include "Card.h"
#ifndef BANKCARD_H
#define BANKCARD_H

class BankCard : public Card
{
private:
	std::string account_number;
	std::string CSC;
public:
	BankCard();
	void readinfo();
	void print() const;
	bool validCSC(const std::string &testCSC) const;
};

#endif

