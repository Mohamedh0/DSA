#pragma once

template <class Ty>
class Node{
public:
    Node *prev, *next;
    Ty value;

    Node(Node *prev, Ty value, Node *next){
        this->prev=prev;
        this->value = value;
        this->next=next;
    }
};