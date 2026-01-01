#pragma once
#include "Node.h"
using namespace std;

template <class Ty>
class SLL
{
private:
	Node<Ty>* head;
	int length;

public:
	SLL() {
		head = nullptr;
		length = 0;
	}
	~SLL() {
		while (head != nullptr)
		{
			pop_front();
		}
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
	void push_front(Ty value) {// O(1)
		head = new Node<Ty>(value, head);
		length++;
	}

	void pop_front() {
		if (empty()) {
			return;
		}
		auto p = head;
		head = head->next;

		delete p;
		length--;
	}

	void push_back(Ty value) {
		if (empty()) {
			push_front(value);
			return;
		}
		auto p = head;

		while (p->next != nullptr)
		{
			p = p->next;
		}
		// p->next == nullptr
		p->next = new Node<Ty>(value, nullptr);
		length++;
	}
	void pop_back() {
		if (empty()) {
			return;
		}
		if (head->next == nullptr) {
			pop_front();
			return;
		}

		auto p = head;

		while (p->next->next != nullptr)
		{
			p = p->next;
		}
		//p->next->next == nullptr
		delete p->next;
		p->next = nullptr;
		length--;
	}

	void push_after(int rank, Ty value) {
		auto p = head;

		for (int i = 0; i < rank; i++) {
			p = p->next;
		}
		p->next = new Node<Ty>(value, p->next);
		length++;
	}

	void push_at(int rank, Ty value) {
		auto p = head;

		for (int i = 0; i < rank - 1; i++) {
			p = p->next;
		}
		p->next = new Node<Ty>(value, p->next);
		length++;
	}
	void pop_at(int rank) {
		if (empty()) {
			return;
		}
		auto p = head;

		for (int i = 0; i < rank - 1; i++) {
			p = p->next;
		}

		auto temp = p->next->next;
		delete p->next;
		p->next = temp;
		length--;
	}

	Node<Ty>* begin() {
		return head;
	}
	Node<Ty>* end() {
		return nullptr;
	}

	class iterator {
	public:
		Node<Ty>* it;

		void operator=(Node<Ty>* x) {
			it = x;
		}

		bool operator!=(Node<Ty>* x) {
			return (it != x);
		}

		void operator++(int) {
			it = it->next;
		}
		void operator++() {
			it = it->next;
		}

		Ty operator*() {
			return it->value;
		}
		Ty operator*(int) {
			return it->value;
		}

		Node<Ty>* operator+(int place) {
			for (int i = 1; i <= place; i++) {
				it = it->next;
			}
			return it;
		}
	};
};

