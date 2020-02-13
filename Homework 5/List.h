#pragma once
#include "Node.h"
#include "Iterator.h"
#include <ostream>
#ifndef List_h

class List
{
public:
	List();

	void push_back(const int& data);

	void push_front(const int& data);

	void insert(Iterator pos, int data);

	Iterator erase(Iterator pos);

	void reverse();

	Iterator begin();

	Iterator end();

	void sort();

	void merge(List& other);

private:
	Node* first;
	Node* last;
	friend class Iterator;
	friend std::ostream& operator << (std::ostream& out, List l);
};

#endif // !List_h
