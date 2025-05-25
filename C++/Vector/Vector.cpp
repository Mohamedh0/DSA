#include "Vector.h"

int main()
{
    // Initialize a Vector of integers 
    Vector<int> v;

    // Add elements to the back
    v.push_back(100);
    v.push_back(200);
    v.push_back(300);

    // Add an element to the front
    v.push_front(50);

    // Print the vector
    cout << "Vector elements: ";
    for (int i = 0; i < v.get_size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    // Print size and capacity
    cout << "Size: " << v.get_size() << endl;         
    cout << "Capacity: " << v.get_capacity() << endl;

    // Remove the first element
    v.pop_front();
    cout << "After pop_front, elements: ";
    for (int i = 0; i < v.get_size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    // Shrink to fit
    v.shrink_to_fit();
    cout << "After shrink_to_fit, capacity: " << v.get_capacity() << endl;


    // Initialize a Vector of strings with capacity 4
    // Example 2 
    Vector<string> vec(4);

    // Check if vector is empty
    cout << "Is vector empty? " << (vec.empty() ? "Yes" : "No") << endl;

    // Add string elements
    vec.push_back("Apple");
    vec.push_back("Banana");
    vec.push_back("Cherry");
    vec.push_back("Date");

    // Check if vector is full
    cout << "Is vector full? " << (vec.full() ? "Yes" : "No") << endl;

    // Print all elements
    cout << "Vector elements: ";
    for (int i = 0; i < vec.get_size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    // Pop an element from the back
    vec.pop_back();
    cout << "After pop_back, elements: ";
    for (int i = 0; i < vec.get_size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}