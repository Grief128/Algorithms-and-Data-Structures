#include <iostream>
#include <string>
using namespace std;

#include "DataStructures/String.h"



int main()
{
    Data::String name = "Sasha Grey";
    name += " and Tine Hott";

    Data::String actresses = name;
    cout << actresses;
    cout << name;

    cout << "\n\n";
    Data::String games;
    games = Data::String("Dragon Age\n") +
        Data::String(+ "Mass Effect Trilogy\n") +
        Data::String("Skyrim\n");

    auto title = std::move(games);
    cout << games;
    cout << title;

    cout << "\n\n";
    return 0;
}
