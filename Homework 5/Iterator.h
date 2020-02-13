#pragma once
#include "Node.h"
#include "List.h"
#ifndef Iterator_h


class Iterator
{
public:
	Iterator();

	int operator*() const;

	void operator++();

	void operator--();

	bool operator==(const Iterator& other) const;

	bool operator!=(const Iterator& other) const;

private:
	Node* position;
	const List* container;
	friend class List;
};

#endif // !Iterator_h
