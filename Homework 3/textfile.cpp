#include <string>
#include <iostream>
#include <fstream>
#include "textfile.h"

//constructs new textfile object, then reads data with read_data
textfile::textfile(std::string _filename) : characters(0), lines(0), filename(_filename)
{
	textfile::read_data();
}

//opens filestream to first count characters, words, and lines
void textfile::read_data()
{
	input_file.open(filename);

	//counts characters by counting offset of get pointer
	input_file.seekg(0, std::ios::end);
	characters = input_file.tellg();

	//resets get pointer to beginning
	input_file.seekg(0, std::ios::beg);

	int count_lines = 0;
	int count_words = 0;
	std::string input;

	while (!input_file.fail())
	{
		input_file >> input; //gets a words, then increments count_words

		count_words++;
		char ch;
		input_file.get(ch);
		if (ch == '\n') //if the next character is a newline character, it must be another line, so increment count_lines
		{
			input_file.unget();  //have to unget to put '\n' back
			count_lines++;
		}
	}

	words = count_words;  //words is the total amount of words counted after running through file
	lines = count_lines;//words is the total amount of lines counted after running through file


	input_file.close();  //close file after reading
}

//returns number of lines in textfile
int textfile::get_lines() const
{
	return lines;
}

//returns name of textfile
std::string textfile::get_filename() const
{
	return filename;
}

//returns true if this textfile has fewer lines than another, otherwise return false
bool textfile::operator < (const textfile* other) const
{
	return (this->get_lines() < other->get_lines());
}

//prints name, number of characters, and number of words to an output stream
void textfile::print_data(std::ofstream& out)
{
	out << "File Name: " << filename << std::endl;
	out << "Number of characters: " << characters << std::endl;
	out << "Number of words: " << words << std::endl;
}

//returns true if this textfile has same number of lines, otherwise return false
bool textfile::operator == (const textfile* other) const
{
	return (this->get_lines() == other->get_lines());
}
