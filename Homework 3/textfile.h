#include <string>
#include <fstream>
#pragma once
#ifndef textfile_h
#define textfile_h

class textfile {
private:
	int characters;
	int lines;
	int words;
	std::string filename;
	std::ifstream input_file;
	
public:
	textfile(const std::string _filename);
	void read_data();
	int get_lines() const;
	std::string get_filename() const;
	bool operator < (const textfile* other) const;
	bool operator == (const textfile* other) const;
	void print_data(std::ofstream& out);
};

#endif