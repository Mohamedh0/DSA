#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    cout << "=== Queue Data Structure Test ===" << endl << endl;

    Queue<int> q;

    // Test 1: Check if queue is initially empty
    cout << "Test 1: Initial empty check" << endl;
    cout << "Is empty: " << (q.empty() ? "Yes" : "No") << endl;
    cout << "Expected: Yes" << endl << endl;

    // Test 2: Push elements
    cout << "Test 2: Push elements (10, 20, 30)" << endl;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << "Front: " << q.front() << " (Expected: 10)" << endl;
    cout << "Back: " << q.back() << " (Expected: 30)" << endl;
    cout << "Is empty: " << (q.empty() ? "Yes" : "No") << " (Expected: No)" << endl << endl;

    // Test 3: Pop element
    cout << "Test 3: Pop one element" << endl;
    q.pop();
    cout << "Front after pop: " << q.front() << " (Expected: 20)" << endl;
    cout << "Back: " << q.back() << " (Expected: 30)" << endl << endl;

    // Test 4: Pop remaining elements
    cout << "Test 4: Pop all remaining elements" << endl;
    q.pop();
    q.pop();
    cout << "Is empty: " << (q.empty() ? "Yes" : "No") << " (Expected: Yes)" << endl << endl;

    // Test 5: Test with strings
    cout << "Test 5: Queue with strings" << endl;
    Queue<string> strQueue;
    strQueue.push("Hello");
    strQueue.push("World");
    cout << "Front: " << strQueue.front() << " (Expected: Hello)" << endl;
    cout << "Back: " << strQueue.back() << " (Expected: World)" << endl << endl;

    cout << "=== All tests completed! ===" << endl;

    return 0;
}
