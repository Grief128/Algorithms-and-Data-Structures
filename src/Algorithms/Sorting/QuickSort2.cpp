#include <iostream>
#include <vector>
using namespace std;


/*-----------------------------------------------------------*/
template <typename T>
void swapVals(T& a, T& b)
{
    auto tmp = a;
    a = b;
    b = tmp;
}


/*-----------------------------------------------------------*/
template <typename I>
auto partition(I begin, I end)
{
    auto pivot = end - 1;
    auto i = begin;
    for (auto j = begin; j != pivot; ++j)
    {
        if (*j < *pivot){
            swapVals(*i++, *j);
        }
    }

    std::swap(*i, *pivot);
    return i;
}


/*-----------------------------------------------------------*/
template <typename I>
void quickSort(I begin, I end)
{
    if (std::distance(begin, end) > 1)
    {
        auto bound = partition(begin, end);
        quickSort(begin, bound);
        quickSort(bound+1, end);
    }
}


/*-----------------------------------------------------------*/
int main()
{
    vector<int> values = { 9 ,8 ,7, 6, 5, 4, 3, 2, 1 };
    quickSort(values.begin(), values.end());

    for (int n : values)
        cout << n << " ";

    cout << "\n\n";
    return 0;
}
