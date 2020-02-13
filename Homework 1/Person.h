#ifndef PERSON_H
#define PERSON_H
#include <string>

#pragma once


class Person {
public:
	Person(const std::string &input_name, const char &input_marker);
	std::string get_name() const;
	int get_score() const;
	void increase_score();
	char get_marker() const;
	void switch_marker();
	bool operator > (const Person &other) const;
private:
	int score;
	std::string name;
	char marker; //this alternates between X and O every round
};

#endif