#pragma once

#include <cassert>
#include <cstdint>
#include "Array.h"


namespace Data
{
    template <typename T>
    class Stack
    {
    private:
        Data::Array<T> _data;
        size_t _length = 0;

    public:
        Stack() {}


        Stack(const Stack& other)
        {
            *this = other;
        }


        Stack& operator = (const Stack& other)
        {
            _data = other._data;
            _length = other._length;
            return *this;
        }


        template <typename... Args>
        T push(Args&&... args)
        {
            T item(args...);
            _data.append(item);
            _length++;
            return item;
        }


        T pop()
        {
            assert(!_data.isEmpty());
            T item = _data.at(_length-1);
            _length--;
            return item;
        }


        T peak() const
        {
            assert(!_data.isEmpty());
            return _data.at(_length-1);
        }


        size_t length() const
        {
            return _length;
        }


        bool isEmpty() const
        {
            return _length == 0;
        }


        size_t capacity() const
        {
            return _data.capacity();
        }
    };
}
