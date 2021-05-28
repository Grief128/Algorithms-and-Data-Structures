#include <iostream>
#include <string>
using namespace std;

#include "LinkedList.h"
#include "String.h"



int main()
{
    Data::LinkedList<int> nums;

    nums.preppend(1);
    nums.preppend(6);
    nums.preppend(3);
    nums.preppend(22);

    nums.append(111);
    nums.append(222);
    nums.append(333);

    nums.removeFirst();
    nums.removeLast();

    nums.traverse([](int n) {
       cout << n << " ";
    });

    cout << "\n\n";

    Data::LinkedList<Data::String> names;
    names.append("Tifanny");
    names.append("Claude");
    names.append("Yummy");
    names.append("Kate");

    for (const Data::String& n : names)
        cout << n.cStr() << "\n";

    cout << "\n\n";
    return 0;
}
