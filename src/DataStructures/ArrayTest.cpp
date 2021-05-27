#include <iostream>
#include <string>
using namespace std;

#include "Array.h"



int main()
{
    Data::Array<int> ar(3, 10);

    ar[2] = 666;
    ar.append(777);
    ar.append(222);
    ar.append(111);

    for (int i : ar)
        cout << i << " ";

    Data::Array<string> fruits({"apple", "orange", "grape"});

    auto moreFruits = std::move(fruits);
    moreFruits.append("strawberry");
    moreFruits.append("guava");

    cout <<"\n\n";
    for (const string& f : fruits)
        cout << f << "\n";

    cout <<"\n\n";
    for (const string& f : moreFruits)
        cout << f << "\n";


    cout << "\n\n";
    return 0;
}
