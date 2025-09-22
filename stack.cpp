#include <iostream>
#include "stack.h"

using namespace std;

template <typename T>
Stack<T>::Stack(int c)
{
    this->capacity = c;
    this->top = 0;
    data = new T[c];
}

template <typename T>
Stack<T>::Stack(const Stack<T> &rhs)
{
    this->capacity = rhs.capacity;
    this->top = rhs.top;
    data = new T[capacity];

    for (int i = 0; i < top; i++)
    {
        data[i] = rhs.data[i];
    }
}

template <typename T>
bool Stack<T>::is_empty()
{
    if (top == 0)
        return true;
    else
        return false;
}

template <typename T>
bool Stack<T>::is_full()
{
    if (top == capacity)
        return true;
    else
        return false;
}

template <typename T>
void Stack<T>::push(int n)
{
    if (!is_full())
    {
        data[top] = n;
        top++;
    }
    else
        exit(0);
}

template <typename T>
T Stack<T>::pop()
{
    if (!is_empty)
    {
        T popped_num = data[top];
        top--;
        return popped_num;
    }
    else
        exit(0);
}

template <typename T>
int Stack<T>::get_top()
{
    return top;
}

template <typename T>
T Stack<T>::stack_top()
{
    return data[top - 1];
}

template <typename T>
Stack<T>::~Stack()
{
    this->capacity = 0;
    this->top = 0;
    delete[] data;
}

template <typename T>
Stack<T> &Stack<T>::operator=(const Stack<T> &rhs)
{
    if (this != &rhs)
    {
        delete[] data;

        this->capacity = rhs.capacity;
        this->top = rhs.top;
        data = new T[capacity];

        for (int i = 0; i < top; i++)
        {
            data[i] = rhs.data[i];
        }
    }

    return *this;
}
