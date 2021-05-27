#pragma once

#include <cstdint>
#include <cassert>
#include <initializer_list>


namespace Data
{
    template <typename T, size_t Size>
    class FixedArray
    {
    private:
        T _data[Size];

    public:
        FixedArray() {}


        FixedArray(const T& item)
        {
            for (size_t i = 0; i < Size; ++i) {
                _data[i] = item;
            }
        }


        FixedArray(const std::initializer_list<T>& args)
        {
            assert(args.size() <= Size);
            size_t count = 0;
            for (const T& i : args) {
                _data[count++] = i;
            }
        }


        FixedArray(const FixedArray& arr)
        {
            *this = arr;
        }


        FixedArray& operator = (const FixedArray& arr)
        {
            for (size_t i = 0; i < Size; ++i) {
                _data[i] = arr[i];}
            return *this;
        }


        T& operator [](size_t index)
        {
            assert(index < Size);
            return _data[index];
        }


        T at(size_t index) const
        {
            assert(index < Size);
            return _data[index];
        }


        T* begin() { return &_data[0]; }
        T* end()   { return &_data[Size]; }


        size_t capacity() const { return Size; }
    };
}
