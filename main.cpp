#include <iostream>
#include <string>
#include "stack.h"
#include "stack.cpp"

using namespace std;

int main()
{
    // Works with any type — that is the point of the template.
    Stack<int> numbers(3);

    numbers.push(10);
    numbers.push(20);
    numbers.push(30);

    cout << "size      : " << numbers.get_top() << endl;
    cout << "top       : " << numbers.stack_top() << endl;

    // FILO — the last value pushed comes back first.
    cout << "pop       : " << numbers.pop() << endl;
    cout << "pop       : " << numbers.pop() << endl;
    cout << "size now  : " << numbers.get_top() << endl;
    cout << "is_empty  : " << boolalpha << numbers.is_empty() << endl;

    Stack<string> words(2);
    words.push("hello");
    words.push("world");

    cout << "word top  : " << words.stack_top() << endl;
    cout << "word pop  : " << words.pop() << endl;

    // Deep copy — the copy owns its own buffer.
    Stack<string> copy = words;
    cout << "copy top  : " << copy.stack_top() << endl;

    return 0;
}
