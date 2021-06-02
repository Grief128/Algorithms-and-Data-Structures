#include <iostream>
#include <string>
using namespace std;

#include "String.h"
#include "HashTable.h"


int main()
{
    Data::HashTable<int, 20> names;

    names.insert("Phill", 29);
    names.insert("Ariane", 25);
    names.insert("Ryan", 22);
    names.insert("Heather", 30);

    cout << names.get("Phill") << "\n";
    cout << names.get("Ariane") << "\n";
    cout << names.get("Ryan") << "\n";
    cout << names.get("Heather") << "\n";

    cout << "\n\n";
    return 0;
}
