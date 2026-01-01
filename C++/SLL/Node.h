#pragma once

template <class Ty>
class Node
{
public:
	Ty value;
	Node* next;

	Node(Ty value, Node* next)
		: value(value), next(next)
	{}
};