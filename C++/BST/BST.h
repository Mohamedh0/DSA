#pragma once
#include "Node.h"

#include <iostream>
using namespace std;

template <class Ty>
class BST
{
private:
	Node<Ty>* root;
	int size;

public:
	BST() {
		root = nullptr;
		size = 0;
	}

	~BST() {
		while (root != nullptr)
		{
			erase(root->value);
		}
	}

	bool empty() {
		return (root == nullptr);
	}

	void insert(Ty value) {
		if (empty()) {
			root = new Node<Ty>(value);
			size++;
			return;
		}

		auto iterator = root;

		while (value != iterator->value)
		{
			//check if it's larger
			if (value > iterator->value) {
				
				if (iterator->right == nullptr) {
					iterator->right = new Node<Ty>(value);
					size++;
					return;
				}
				else {//right != nullptr
					iterator = iterator->right;
				}
			}
			//check if it's smaller
			else {
				if (iterator->left == nullptr) {
					iterator->left = new Node<Ty>(value);
					size++;
					return;
				}
				else {//left != nullptr
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

	void erase(Ty value) {
		if (empty()) {
			return;
		}

		auto iterator = root;
		auto parent = root;
		while (true)
		{
			//check if larger
			if (value > iterator->value) {

				if (iterator->right != nullptr) {
					parent = iterator;
					iterator = iterator->right;
				}
				else {
					//empty right
					return;
				}
			}
			//check if smaller
			else if (value < iterator->value) {

				if (iterator->left != nullptr) {
					parent = iterator;
					iterator = iterator->left;
				}
				else {
					//left empty
					return;
				}
			}

			//value is found!
			//iterator is holding the node that will be deleted
			//parent is holding the parent node
			else {
				
				//1st case - no child - leaf
				if (iterator->left == nullptr && iterator->right == nullptr) {

					if (root == iterator) {
						//no child & root
						delete root;
						root = nullptr;
						size--;
						return;
					}

					if (parent->right == iterator) {
						parent->right = nullptr;
					}
					else {
						parent->left = nullptr;
					}
					delete iterator;
					size--;
					return;
				}
				//2nd case - one child
				else if (iterator->left == nullptr || iterator->right == nullptr) {

					if (root == iterator) {
						//one child & root
						root = (root->right != nullptr ? root->right : root->left);
						delete iterator;
						size--;
						return;
					}

					auto temp = (iterator->right != nullptr ? iterator->right : iterator->left);

					if (parent->right == iterator) {
						parent->right = temp;
					}
					else {
						parent->left = temp;
					}
					delete iterator;
					size--;
					return;

				}
				//3rd case - two child
				else {

					auto smallestRight = iterator->right;

					while (smallestRight->left != nullptr)
					{
						smallestRight = smallestRight->left;
					}

					iterator->value = smallestRight->value;
					iterator = iterator->right;
					value = smallestRight->value;
				}
			}
		}
	}
};

