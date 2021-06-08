#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
using namespace std;


/*-----------------------------------------------------*/
template <class T, class I>
auto binarySearch(const T& item, I begin, I end)
{
    size_t len = end - begin;
    size_t a = 0;
    size_t b = len - 1;

    while (a <= b)
    {
        auto mid = (a + b) / 2;

        if (item == *(begin + mid))
            return (begin + mid);

        if (item < *(begin + mid))
            b = mid - 1;
        else
            a = mid + 1;
    }

    return end;
}


/*-----------------------------------------------------*/
template <class T, class C>
bool available(const T& item, const C& container)
{
    auto it = binarySearch(item, std::begin(container), std::end(container));
    return (it != std::end(container));
}


/*-----------------------------------------------------*/
int main()
{
    vector<string> foods = { "bread", "cheese", "chocolate", "pizza", "steak" };

    for (;;)
    {
        cout << "Enter your order: ";
        string order;
        cin >> order;

        if (available(order, foods)) {
            cout << ">> " << order << " is available. Nice meal!\n\n";
        } else {
            cout << ">> " << order << " is not available in the menu. Try again!\n\n";
        }
    }

    return 0;
}
