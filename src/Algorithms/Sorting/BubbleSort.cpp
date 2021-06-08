#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;


/*-----------------------------------------------------*/
template <class T>
void swapValues(T& a, T& b)
{
    auto temp = a;
    a = b;
    b = temp;
}


/*-----------------------------------------------------*/
void bubbleSort(vector<int>& arr)
{
    for (size_t a = 0; a < arr.size() - 1; ++a) {
        for (size_t i = a + 1; i < arr.size(); ++i) {
            if (arr[a] > arr[i]) {
                swapValues(arr[i], arr[a]);
            }
        }
    }
}


/*-----------------------------------------------------*/
void print(const vector<int>& nums, string text = "")
{
    if (!text.empty())
        cout << text << ": ";

    for (int n : nums)
        cout << n << " ";

    cout << "\n";
}


/*-----------------------------------------------------*/
auto generateArray(int num)
{
    vector<int> ns;
    for (int i = 0; i < num; ++i) {
        ns.push_back(rand() % 0xff);
        if (rand() % 2 == 1) ns[i] *= -1;
    }

    return ns;
}


/*-----------------------------------------------------*/
int main()
{
    srand(time(nullptr));

    cout << "Enter number of values to be generated: ";
    int num;
    cin >> num;

    auto nums = generateArray(num);
    print(nums, ">> Non ordered");

    bubbleSort(nums);
    print(nums, ">> Ordered");


    cout << "\n\n";
    return 0;
}
