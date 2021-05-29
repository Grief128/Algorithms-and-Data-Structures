#pragma once

#include <cstdint>
#include <cassert>
#include "LinkedList.h"


namespace Data
{
    template <typename T>
    class Queue
    {
    private:
        LinkedList<T> _data;
        size_t _length = 0;

    public:
        Queue() {}


        Queue(const Queue& other)
        {
            *this = other;
        }

        Queue& operator = (const Queue& other)
        {
            _length = other._length;
            _data = other._data;
            return *this;
        }


        template <typename... Args>
        T enqueue(Args&&... args)
        {
            T item(args...);
            _data.append(item);
            _length++;
            return item;
        }


        T dequeue()
        {
            assert(!isEmpty());
            auto item = _data.first();
            _length--;
            _data.removeFirst();
            return item;
        }


        T peakFront()
        {
            assert(!isEmpty());
            return _data.first();
        }


        size_t length() const { return _length; }
        bool isEmpty() const { return length() == 0; }
    };
}
