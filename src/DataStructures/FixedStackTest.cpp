#include <iostream>
#include <string>
using namespace std;

#include "DataStructures/FixedStack.h"
#include "DataStructures/String.h"


template <typename T>
void showStack(Data::FixedStack<T, 10>& s)
{
    cout << "Top --> ";
    while (!s.isEmpty()) {
        cout << s.pop() << " ";
    }

    cout << "\n";
}


int main()
{
    Data::FixedStack<int, 10> stack;

    stack.push(10);
    stack.push(5);
    stack.push(15);
    showStack(stack);

    stack.push(10);
    stack.push(5);
    stack.push(15);
    stack.pop();
    showStack(stack);


    Data::FixedStack<Data::String, 10> drinks;

    drinks.push("Beer");
    drinks.push("Whiskey");
    drinks.push("Vodka");
    showStack(drinks);

    drinks.push("Beer");
    drinks.push("Whiskey");
    drinks.push("Vodka");
    drinks.pop();
    showStack(drinks);

    cout << "\n\n";
    return 0;
}
