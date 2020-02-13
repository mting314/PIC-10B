#pragma once
#include <iostream>
#include <string>
#ifndef Card_h
#define Card_h
class Card
{
public:
private:
	std::string institution;
	std::string holder_name;
	std::string exp_date;


public:
	Card();
	virtual void readinfo();
	virtual void print() const;
	std::string get_exp_date() const;
	bool operator <= (const Card &other ) const;
	bool isNumber(const std::string &test) const;
	bool validDate(const std::string &test) const;
	void printDate(const std::string &date) const;
};


#endif