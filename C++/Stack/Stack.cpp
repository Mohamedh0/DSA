#include <iostream>
#include "Stack.h"
using namespace std;

int main(){
    Stack<int> stack;
    
    // Test empty on new stack
    cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << endl;
    
    // Test push
    cout << "\nPushing 10, 20, 30..." << endl;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    // Test top
    cout << "Top element: " << stack.top() << endl;
    
    // Test empty after push
    cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << endl;
    
    // Test pop and top
    cout << "\nPopping elements:" << endl;
    while(!stack.empty()){
        cout << "Top: " << stack.top() << endl;
        stack.pop();
    }
    
    // Test empty after popping all
    cout << "\nIs stack empty after popping all? " << (stack.empty() ? "Yes" : "No") << endl;
    
    return 0;
}