#pragma once

template <class TY>
class Node{
public:
    TY value;
    Node* next;

private:
    Node(TY value, Node* next){
        this->value = value;
        this->next = next;
    }
};
