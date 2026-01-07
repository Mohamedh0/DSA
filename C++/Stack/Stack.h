#pragma once
#include "Node.h"
using namespace std;

template <class Ty>
class Stack{
private:
    Node<Ty>* head;
public:
    Stack(){
        head = nullptr;
    }

    ~Stack(){
        while(head != nullptr){
            pop();
        }
    }

    bool empty(){
        return (head == nullptr);
    }

    Ty& top(){
        return head->value;
    }

	void push(Ty value) {
		head = new Node<Ty>(value, head);
	}

	void pop() {
		if (empty()) {
			return;
		}
		auto p = head;
		head = head->next;

		delete p;
	}
};