#pragma once


#include <cassert>
#include <cstdint>


namespace Data
{
    template <typename T, size_t Capacity>
    class PriorityArrayQueue
    {
    private:
        T _data[Capacity];
        size_t _length = 0;

    public:
        PriorityArrayQueue()
        {
        }


        template <typename... Args>
        T enqueue(Args&&... args)
        {
            assert(_length != Capacity);
            T item(args...);

            size_t i = _length - 1;
            while (i >= 0 && _data[i] >= item) {
                _data[i+1] = _data[i];
                --i;
            }

            _data[i+1] = item;
            _length++;
            return item;
        }


        T dequeue()
        {
            assert(!isEmpty());
            auto item = _data[_length-1];
            _length--;
            return item;
        }


        T peakFirst()
        {
            assert(!isEmpty());
            return _data[0];
        }


        size_t length() const { return _length; }
        bool isEmpty() const { return _length == 0; }
    };
}
