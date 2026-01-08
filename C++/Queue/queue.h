#pragma once
#include "Node.h"
using namespace std;

template<class Ty>
class Queue{
private:
    Node<Ty> *head, *tail;
    int length;

public:
    Queue(){
        head = tail = nullptr;
        length = 0;
    }

    ~Queue(){
        while(!empty()){
            pop();
        }
    }

    bool empty(){
        return (head == nullptr);
    }

    Ty& front(){
        return head->value;
    }

    Ty& back(){
        return tail->value;
    }

	void push(Ty value) {
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
	void pop() {
		if (empty()) {
			return;
		}
		if (head->next == nullptr) {
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
	
};