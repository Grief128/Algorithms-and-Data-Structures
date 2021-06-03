#include <iostream>
#include <string>
using namespace std;

#include "DataStructures/String.h"
#include "DataStructures/BinaryTree.h"


int main()
{
    Data::BinaryTree<std::string> colors;
    colors.insert("red");
    colors.insert("blue");
    colors.insert("green");
    colors.insert("black");
    colors.insert("white");

    cout << "Min: " << colors.min()->data << "\n";
    cout << "Max: " << colors.max()->data << "\n";

    cout << "\nAll itens:\n";
    colors.traverse([](const string& c) {
        cout << c << "\n";
    }, Data::BinaryTree<string>::Traverse::Post_Order);


    Data::BinaryTree<int> numbers;
    numbers.insert(11);
    numbers.insert(22);
    numbers.insert(333);
    numbers.insert(44);
    numbers.insert(55);

    cout << "\n\nMin: " << numbers.min()->data << "\n";
    cout << "Max: " << numbers.max()->data << "\n";

    cout << "\nAll itens:\n";
    numbers.traverse([](int c) {
        cout << c << "\n";
    }, Data::BinaryTree<int>::Traverse::Pre_Order);


    cout << "\n\n";
    return 0;
}
