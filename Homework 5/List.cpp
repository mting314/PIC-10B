#include "List.h"
#include "Node.h"
#include "Iterator.h"
#include <assert.h>
#include <iostream>

List::List()
{
	first = nullptr;
	last = nullptr;
}

void List::push_back(const int& data)
{
	Node* insertion = new Node(data);
	if (last == nullptr) //if list is empty
	{
		last = insertion;
		first = insertion;
	}
	else
	{
		insertion->previous = last;
		last->next = insertion;
		last = insertion;
	}
}

void List::push_front(const int& data)
{
	Node* insertion = new Node(data);
	if (first == nullptr) //if list is empty
	{
		last = insertion;
		first = insertion;
	}
	else
	{
		insertion->next = first;
		first->previous = insertion;
		first = insertion;
	}
}

void List::insert(Iterator pos, int data)
{
	Node* after = pos.position;
	Node* before = after->previous;

	if (after == nullptr) push_back(data);
	else if (before == nullptr) push_front(data);
	else
	{
		Node* insertion = new Node(data);
		insertion->next = after;
		insertion->previous = before;

		before->next = insertion;
		after->previous = insertion;
	}

}

Iterator List::erase(Iterator pos)
{
	assert(pos.position != nullptr); //make sure not removing something that doesn't exist, like if list is empty

	Node* removal = pos.position;

	Node* before = removal->previous;
	Node* after = removal->next;

	delete removal;

	if (before == nullptr) //removing first element
	{
		first = after;
	}
	else before->next = after;

	if (after == nullptr) //removing last element, don't want else if here because theoretically both after and before could be null if there's only 1 element in the list
	{
		last = before;
	}
	else after->previous = before;

	Iterator r;
	r.position = after;
	r.container = this;
	return r;
}

void List::reverse()
{
	assert(first != nullptr);
	Node* temp;
	Iterator iter = begin();
	Iterator stop = end();


	while (iter != stop)
	{
		//switch each node's previous and next, "reverse" the direction of each
		temp = iter.position->next;
		iter.position->next = iter.position->previous;
		iter.position->previous = temp;
		//actually need to traverse "backwards" because what was the next node is now the previous one
		--iter;
	}
	//have to deal with first and last
	temp = this->first;
	this->first = this->last;
	this->last = temp;
}

Iterator List::begin()
{
	Iterator beginning;
	beginning.position = first;
	beginning.container = this;
	return beginning;
}

Iterator List::end()
{
	Iterator ending;
	ending.position = nullptr;
	ending.container = this;
	return ending;
}

void List::sort()
{
	assert(first != nullptr);

	bool needed_swap = false;

	int temp;

	Node* current = first;
	Node* end = nullptr;
	
	do
	{
		needed_swap = false;
		current = first;

		while (current->next != end)
		{
			if (current->data > current->next->data)
			{
				temp = current->data;
				current->data = current->next->data;
				current->next->data = temp;

				needed_swap = true;
			}
			current = current->next;
		}
		end = current;
	}
	while (needed_swap);
}

void List::merge(List& other)
{
	Iterator iter = begin();
	Iterator other_iter = other.begin();

	while (iter.position->next != nullptr && other_iter.position != nullptr)
	{
		++iter;
		insert(iter, other_iter.position->data);
		++other_iter;
	}

	while (other_iter.position != nullptr)
	{
		push_back(other_iter.position->data);
		++other_iter;
	}
}

std::ostream& operator << (std::ostream& out, List l)
{
	out << "(";
	Iterator almost_end = l.end();
	--almost_end;
	for (Iterator iter = l.begin(); iter != almost_end; ++iter)
	{
		out << *iter << ",";
	}

	out << *almost_end;
	out << ")";

	return out;
}