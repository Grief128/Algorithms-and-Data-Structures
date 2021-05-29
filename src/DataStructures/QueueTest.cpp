#include <iostream>
#include <string>
using namespace std;

#include "Queue.h"
#include "String.h"


template <typename T>
void showQueue(Data::Queue<T>& s)
{
    cout << "First --> ";
    while (!s.isEmpty()) {
        cout << s.dequeue() << " ";
    }

    cout << "\n";
}


int main()
{
    Data::Queue<int> nums;

    nums.enqueue(10);
    nums.enqueue(20);
    nums.enqueue(30);
    nums.enqueue(40);
    showQueue(nums);

    nums.enqueue(10);
    nums.enqueue(20);
    nums.enqueue(30);
    nums.dequeue();
    nums.enqueue(40);
    showQueue(nums);


    Data::Queue<Data::String> bands;

    bands.enqueue("Venom");
    bands.enqueue("Deicide");
    bands.enqueue("Marduk");
    showQueue(bands);

    bands.enqueue("Venom");
    bands.enqueue("Deicide");
    bands.enqueue("Marduk");
    bands.dequeue();
    showQueue(bands);

    cout << "\n\n";
    return 0;
}
