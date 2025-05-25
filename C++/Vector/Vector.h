#pragma once
#include <iostream>
using namespace std;

template <class TY>
class Vector
{
private:
    int size, capacity;
    TY *arr;

    // Doubles the capacity of the vector and copies existing elements
    void expand()
    {
        capacity *= 2;
        TY *temp = new TY[capacity]{};
        for (int i = 0; i < size; i++)
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }

public:
    // Default constructor initializing an empty vector with capacity 2
    Vector()
    {
        size = 0;
        capacity = 2;
        arr = new TY[capacity]{};
    }

    // Constructor initializing vector with specified capacity
    Vector(int capacity)
    {
        this->capacity = capacity;
        size = 0;
        arr = new TY[capacity]{};
    }

    // Destructor to free allocated memory
    ~Vector()
    {
        delete[] arr;
    }

    // Returns the current number of elements in the vector
    int get_size()
    {
        return size;
    }

    // Returns the current capacity of the vector
    int get_capacity()
    {
        return capacity;
    }

    // Checks if the vector is full (size equals capacity)
    bool full()
    {
        return (size == capacity);
    }

    // Checks if the vector is empty
    bool empty()
    {
        return (size == 0);
    }

    // Accesses element at specified index
    TY &operator[](int index)
    {
        return arr[index];
    }

    // Adds an element to the end of the vector
    void push_back(TY value)
    {
        if (full())
        {
            expand();
        }
        arr[size] = value;
        size++;
    }

    // Removes the last element from the vector
    void pop_back()
    {
        if (empty())
        {
            return;
        }
        size--;
    }

    // Adds an element to the front of the vector
    void push_front(TY value)
    {
        if (full())
        {
            expand();
        }
        for (int i = size; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = value;
        size++;
    }

    // Removes the first element from the vector
    void pop_front()
    {
        if (empty())
        {
            return;
        }
        if (size == 1)
        {
            pop_back();
        }
        for (int i = 0; i <= size - 2; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    // Reduces capacity to match the current size
    void shrink_to_fit()
    {
        capacity = size;
        TY *temp = new TY[capacity]{};
        for (int i = 0; i < size; i++)
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }
};