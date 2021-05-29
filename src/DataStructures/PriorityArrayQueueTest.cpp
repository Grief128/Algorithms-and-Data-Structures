#include <iostream>
#include <string>
using namespace std;

#include "DataStructures/PriorityArrayQueue.h"
#include "DataStructures/String.h"


template <typename T, size_t Cap = 10>
void showQueue(Data::PriorityArrayQueue<T, Cap>& s)
{
    cout << "First --> ";
    while (!s.isEmpty()) {
        cout << s.dequeue() << " ";
    }

    cout << "\n";
}


int main()
{
    Data::PriorityArrayQueue<int, 10> nums;

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


    Data::PriorityArrayQueue<Data::String, 10> fruits;

    fruits.enqueue("Apple");
    fruits.enqueue("Tomato");
    fruits.enqueue("Grape");
    showQueue(fruits);

    fruits.enqueue("Apple");
    fruits.enqueue("Tomato");
    fruits.enqueue("Grape");
    fruits.dequeue();
    showQueue(fruits);

    cout << "\n\n";
    return 0;
}
