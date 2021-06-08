#include <iostream>
#include <string>
#include <vector>
using namespace std;


/*-----------------------------------------------------*/
auto& insertionSort(vector<string>& arr)
{
    for (size_t i = 1; i < arr.size(); ++i)
    {
        auto temp = arr[i];
        size_t b = i;

        for (; (b > 0) && (temp < arr[b - 1]); --b) {
            arr[b] = arr[b - 1];
        }

        arr[b] = temp;
    }

    return arr;
}


/*-----------------------------------------------------*/
void printNames(const vector<string>& names)
{
    cout << "\n";

    for (const string& n : names) {
        cout << "- " << n << "\n";
    }
}


/*-----------------------------------------------------*/
auto getNames()
{
    vector<string> ns;
    string name;

    cout << "Enter names[-1 to end]: ";
    while (cin >> name) {
        if (name == "-1") break;
        ns.push_back(name);
    }

    return insertionSort(ns);
}


/*-----------------------------------------------------*/
int main()
{
    printNames(getNames());

    cout << "\n\n";
    return 0;
}
