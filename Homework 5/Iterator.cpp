#include "Iterator.h"
#include <assert.h>

Iterator::Iterator()
{
	position = nullptr;
	container = nullptr;
}

int Iterator::operator*() const
{
	assert(position != nullptr);
	return position->data;
}

void Iterator::operator++()
{
	assert(position != nullptr);
	position = position->next;
}

void Iterator::operator--()
{
	if (position == nullptr)
		position = container->last;
	else
		position = position->previous;
}

bool Iterator::operator==(const Iterator& other) const
{
	return (position == other.position);
}

bool Iterator::operator!=(const Iterator& other) const
{
	return (position != other.position);
}