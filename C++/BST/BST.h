#pragma once
#include "Node.h"
using namespace std;

template <class Ty>
class BST{
private:
    Node<Ty>* root;
    int size;

public:
    BST(){
        root = nullptr;
        size = 0;
    }

    bool empty(){
        return (root == nullptr);
    }

    void insert(Ty value){
        int steps = 0;
        if(empty()){
            root = new Node<Ty>(value);
            size++;
            cout<<"Steps " << steps<<endl;
            return;
        }
        auto iterator = root;
        while(value != iterator->value){
            if(value > iterator->value){
                if(iterator->right == nullptr){
                    iterator->right = new Node<Ty>(value);
                    size++;
                    cout<<"Steps " << steps<<endl;
                    return;
                }

                else{
                    steps++;
                    iterator = iterator->right;
                }
            }

            else{
                if(iterator->left == nullptr){
                    iterator->left = new Node<Ty>(value);
                    size++;
                    cout<<"Steps " << steps<<endl;
                    return;
                }

                else{
                    steps++;
                    iterator = iterator->left;
                }
            }
        }
    }

	bool find(Ty value) {
		if (empty()) {
			return false;
		}
		int steps = 0;
		auto iterator = root;

		while (value != iterator->value)
		{
			if (value > iterator->value && iterator->right != nullptr) {
				steps++;
				iterator = iterator->right;
			}
			else if (value < iterator->value && iterator->left != nullptr) {
				steps++;
				iterator = iterator->left;
			}
			else {
				//greater & empty right
				//smaller & empty left
				cout << "Steps: " << steps << endl;
				return false;
			}

		}
		cout << "Steps: " << steps << endl;
		return true;
	}
};