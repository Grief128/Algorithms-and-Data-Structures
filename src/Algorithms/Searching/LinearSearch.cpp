#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;


/*-----------------------------------------------------*/
template <class T, class I>
auto linearSearch(const T& item, I begin, I end)
{
    while (begin != end) {
        if (*begin == item) return begin;
        ++begin;
    }

    return begin;
}


/*-----------------------------------------------------*/
template <class T, class C>
bool exists(const T& item, const C& container)
{
    auto it = linearSearch(item, std::begin(container), std::end(container));
    return (it != std::end(container));
}


/*-----------------------------------------------------*/
void showOutput(const std::string& juice, const std::vector<std::string>& juices)
{
    cout << juice << ": "
        << boolalpha << exists(juice, juices) << "\n";
}


/*-----------------------------------------------------*/
int main()
{
    vector<string> juices = { "orange", "lemon", "pineapple", "strawberry" };

    showOutput("orange", juices);
    showOutput("lemon", juices);
    showOutput("grape", juices);
    showOutput("pineapple", juices);

    cout << "\n\n";
    return 0;
}
