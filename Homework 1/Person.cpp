#include "Person.h"

Person::Person(const std::string &input_name, const char &input_marker) : score(0), marker(input_marker), name(input_name) //all players start with 0 score
{
}

std::string Person::get_name() const {
	return name;
}

//Accessors
int Person::get_score() const {
	return score;
}

char Person::get_marker() const {
	return marker;
}

//Increases score for when a round is won
void Person::increase_score() {
	score++;
}

//Switches from X to O, or O to X after the end of a round and the sides switch
void Person::switch_marker() {
	if (marker == 'X')
		marker = 'O';
	else
		marker = 'X'; //otherwise the marker was an 'O' so it's guaranteed to be an X now
}

//Used for comparing the scores to see who should win the tournament overall
bool Person::operator > (const Person &other) const
{
	return (this->score > other.get_score());
}