#pragma once
#include "Node.h"

template <class Ty>
class DLL
{
private:
	Node<Ty>* head, * tail;
	int length;

public:

	DLL() {
		head = tail = nullptr;
		length = 0;
	}
	bool empty() {
		return (head == nullptr);
	}
	int get_length() {
		return length;
	}
	Ty& operator[](int rank) {
		auto p = head;

		for (int i = 0; i < rank; i++) {
			p = p->next;
		}
		return p->value;
	}
	Ty& traverse_from_tail(int rank) {
		auto p = tail;

		for (int i = 0; i < rank; i++) {
			p = p->prev;
		}
		return p->value;
	}
	void push_front(Ty value) {
		if (empty()) {
			head = new Node<Ty>(nullptr, value, head);
			tail = head;
			length++;
			return;
		}
		head->prev = new Node<Ty>(nullptr, value, head);
		head = head->prev;
		length++;
	}
	void push_back(Ty value) {
		if (empty()) {
			tail = new Node<Ty>(tail, value, nullptr);
			head = tail;
			length++;
			return;
		}
		tail->next = new Node<Ty>(tail, value, nullptr);
		tail = tail->next;
		length++;
	}
	void pop_front() {
		if (empty()) {
			return;
		}
		if (head == tail) {
			delete head;
			head = tail = nullptr;
			length = 0;
			return;
		}
		auto p = head;
		head = head->next;
		delete p;
		head->prev = nullptr;
		length--;
	}
	void pop_back() {
		if (empty()) {
			return;
		}
		if (tail == head) {
			delete tail;
			tail = head = nullptr;
			length = 0;
			return;
		}
		auto p = tail;
		tail = tail->prev;
		delete p;
		tail->next = nullptr;
		length--;
	}
};

