#include <iostream>
#include <string>
using namespace std;

#include "Stack.h"
#include "String.h"


template <typename T>
void showStack(Data::Stack<T>& s)
{
    cout << "Top --> ";
    while (!s.isEmpty()) {
        cout << s.pop() << " ";
    }

    cout << "\n";
}


int main()
{
    Data::Stack<int> stack;

    stack.push(10);
    stack.push(5);
    stack.push(15);
    showStack(stack);

    stack.push(10);
    stack.push(5);
    stack.push(15);
    stack.pop();
    showStack(stack);


    Data::Stack<Data::String> stones;

    stones.push("Peridot");
    stones.push("Garnet");
    stones.push("Ruby");
    showStack(stones);

    stones.push("Peridot");
    stones.push("Garnet");
    stones.push("Ruby");
    stones.pop();
    showStack(stones);

    cout << "\n\n";
    return 0;
}
