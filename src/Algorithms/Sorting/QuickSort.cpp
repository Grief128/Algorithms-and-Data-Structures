#include <iostream>
#include <vector>
using namespace std;


/*-----------------------------------------------------------*/
template <class T>
void swapVals(T& a, T& b)
{
    auto temp = a;
    a = b;
    b = temp;
}


/*-----------------------------------------------------------*/
int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; ++j)
    {
        if (arr[j] < pivot) {
            i++;
            swapVals(arr[i], arr[j]);
        }
    }

    swapVals(arr[i + 1], arr[high]);
    return (i + 1);
}


/*-----------------------------------------------------------*/
void quickSort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}


/*-----------------------------------------------------------*/
int main()
{
    vector<int> values = { 9 ,8 ,7, 6, 5, 4, 3, 2, 1 };
    quickSort(values, 0, values.size() - 1);

    for (int n : values)
        cout << n << " ";

    cout << "\n\n";
    return 0;
}
