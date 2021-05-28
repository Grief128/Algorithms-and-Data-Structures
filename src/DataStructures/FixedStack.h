#pragma once

#include <cstdint>
#include <cassert>


namespace Data
{
    template <typename T, size_t Capacity>
    class FixedStack
    {
    private:
        T _data[Capacity];
        size_t _length = 0;

    public:
        FixedStack() {}


        FixedStack(const FixedStack& other)
        {
            *this = other;
        }


        FixedStack& operator = (const FixedStack& other)
        {
            for (size_t i = 0; i < _length; ++i)
                _data[i] = other._data[i];
            return *this;
        }


        template <typename... Args>
        T push(Args&&... args)
        {
            assert(_length < Capacity);
            T item(args...);
            _data[_length] = item;
            ++_length;
            return item;
        }


        T pop()
        {
            assert(_length > 0);
            T item = _data[_length-1];
            --_length;
            return item;
        }


        T peak() const
        {
            return _data[_length-1];
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
            return Capacity;
        }
    };
}
