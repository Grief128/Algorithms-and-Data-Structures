#pragma once

#include <cstdint>
#include <cassert>
#include <initializer_list>


namespace Data
{
    template <typename T>
    class Array
    {
    private:
        static constexpr size_t Max_Cap { 128 };
        size_t _capacity = Max_Cap;
        size_t _length = 0;
        T* _data = nullptr;

    public:
        Array()
        {
            _data = new T[Max_Cap];
        }


        Array(const T& data, size_t many)
        {
            _data = new T[Max_Cap];
            _capacity = Max_Cap;
            _length = many;
            for (size_t i = 0; i < many; ++i) {
                _data[i] = data;
            }
        }


        Array(const std::initializer_list<T>& args)
        {
            _capacity = getNextCap(args.size());
            _length = args.size();
            _data = new T[_capacity];
            size_t i = 0;
            for (const T& a : args) {
                _data[i++] = a;
            }
        }


        ~Array()
        {
            if (_data) {
                delete[] _data;
                _data = nullptr;
            }
        }


        Array(const Array& other)
        {
            *this = other;
        }


        T& operator = (const Array& other)
        {
            reset(getNextCap(other.capacity()));
            _length= other.length();

            size_t count = 0;
            for (const T& i : other)
                _data[count++] = i;

            return *this;
        }


        Array(Array&& other)
        {
            _length = other.length();
            _capacity = other.capacity();
            _data = other._data;

            other._capacity = Max_Cap;
            other._length = 0;
            other._data = new T[Max_Cap];
        }


        template <typename... Args>
        void append(Args&&... args)
        {
            if (_length == _capacity) {
                auto temp = _data;
                _data = new T[_capacity += Max_Cap];

                for (size_t i=0; i < _capacity; ++i) {
                    _data[i] = temp[i];
                }

                delete[] temp;
            }

            T item(args...);
            _data[_length] = item;
            _length++;
        }


        T& at(size_t index) const
        {
            assert(index <= _length);
            return _data[index];
        }


        T& operator[](size_t index)
        {
            assert(index <= _length);
            return _data[index];
        }


        size_t capacity() const { return _capacity; }
        size_t length() const { return _length; }
        bool   isEmpty() const { return length() == 0; }
        T* begin() { return &_data[0]; }
        T* end()   { return &_data[_length]; }


    private:
        size_t getNextCap(size_t cap)
        {
            while (cap % Max_Cap != 0) ++cap;
            return cap;
        }


        void reset(size_t capacity)
        {
            _length = 0;
            _capacity = capacity;

            if (_data) delete[] _data;
            _data = new T[_capacity];
        }
    };
}
