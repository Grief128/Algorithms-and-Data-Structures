#include <iostream>
#include <string>
using namespace std;


/*-----------------------------------------------------*/
template <class T>
void swapVals(T& a, T& b)
{
    auto temp = a;
    a = b;
    b = temp;
}


/*-----------------------------------------------------*/
template <class T>
auto& selectionSort(T& arr)
{
    size_t mid = 0;
    size_t i, j;

    for (i = 0; i < arr.size(); ++i) {
        for (j = i, mid = i; j < arr.size(); ++j) {
            if (arr[j] < arr[mid]) {
                mid = j;
            }
        }

        swapVals(arr[i], arr[mid]);
    }

    return arr;
}


/*-----------------------------------------------------*/
int main()
{
    string letters = "yfduifybfdsauiyreqwuiowpqrkfdhsafjnvcmxbmvhdjskadh";

    cout << selectionSort(letters);

    cout << "\n\n";
    return 0;
}
