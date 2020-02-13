#pragma once
#ifndef Node_h

class Node
{
public:
	Node(const int& _data);

private:
	int data;
	Node* previous;
	Node* next;
	friend class List;
	friend class Iterator;
};

#endif