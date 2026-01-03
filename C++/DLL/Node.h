#pragma once

template <class Ty>
class Node
{
public:
	Ty value;
	Node* prev, * next;

	Node(Node* prev, Ty value, Node* next) 
	{
		this->prev = prev;
		this->value = value;
		this->next = next;
	}
};