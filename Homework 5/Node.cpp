#include "Node.h"

Node::Node(const int& _data) : data(_data)
{
	previous = nullptr;
	next = nullptr;
}