#pragma once

template <class Ty>
class Node{
public:
    Node *left, *right;
    Ty value;

    Node(Ty value){
        this->value = value;
        right = left = nullptr;
    }
};