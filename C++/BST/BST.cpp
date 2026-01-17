#include <iostream>
#include "BST.h"
using namespace std;

int main(){
    BST<int> bst;

    bst.insert(400); // 0
    bst.insert(500); // 0
    bst.insert(200); // 0
    bst.insert(300); // 1
    bst.insert(100); // 1
    bst.insert(700); // 1
    bst.insert(600); // 2
    bst.insert(450); // 1
    bst.insert(470); // 2

    // Search
    cout<< bst.find(300)<<endl;
    cout<< bst.find(50)<<endl;

    // Erase
    bst.erase(500);
    cout<< bst.find(500);
}