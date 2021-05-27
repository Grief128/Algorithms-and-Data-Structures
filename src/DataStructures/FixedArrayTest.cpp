#include <iostream>
#include <string>
using namespace std;

#include "FixedArray.h"


int main()
{
    Data::FixedArray<int, 10> ar(999);

    for (int i : ar)
        cout << i << " ";

    ar[9] = 111;
    cout << "\n" << ar.at(9) << "\n";

    Data::FixedArray<string, 5> langs({"C++", "Java", "Python", "C#", "Rust"});
    for (const string& l : langs)
        cout << l << "\n";


    cout << "\n\n";
    return 0;
}
