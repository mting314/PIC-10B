#include "textfile.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main() 
{
	string firstfile, secondfile;

	//prompt user for file names
	bool valid = false;
	ifstream test;
	
	//test whether the file actually exists
	while (!valid)
	{
		cout << "Enter the name of file 1: ";
		getline(cin, firstfile);
		test.open(firstfile);
		//failbit will be true if file doesn't exist or can't be opened
		if (test.fail())
		{
			cout << "Could not find this file. Try again." << endl;
		}
		else valid = true;  //if file could be opened, input is valid
		test.close();  //have to close file after opening
	}

	valid = false; //reset valid flag for second input

	while (!valid)
	{
		cout << "Enter the name of file 2: ";
		getline(cin, secondfile);
		test.open(secondfile);
		//failbit will be true if file doesn't exist or can't be opened
		if (test.fail())
		{
			cout << "Could not find this file. Try again." << endl;
		}
		else valid = true; //if file could be opened, input is valid
		test.close(); //have to close file after opening
	}

	//create pointers to textfile objects, one for each file
	textfile * first = new textfile(firstfile);
	textfile * second = new textfile(secondfile);

	//create ofstream object for writing results
	ofstream output_data;
	output_data.open("Properties.txt");

	//print results of counting to Properties.txt
	first->print_data(output_data);
	output_data << endl;
	second->print_data(output_data);
	output_data << endl;

	//compare both files with overloaded operators, print to Properties.txt which one has more lines
	if (*second < first)
	{
		output_data << "The file named \"" << second->get_filename() << "\" has less lines than \"" << first->get_filename() << "\".";
	}
	else if(*first == second) output_data << "Both files have the same number of lines."; 
	else
	{
		output_data << "The file named \"" << second->get_filename() << "\" has more lines than \"" << first->get_filename() << "\".";

	}

	delete first;
	delete second;

	output_data.close();
}