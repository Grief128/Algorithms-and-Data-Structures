#pragma once

#include <cstdint>
#include <cstring>
#include <cassert>


namespace Data
{
    class String
    {
    private:
        static constexpr size_t Max_Cap { 128 };
        size_t _length = 0;
        size_t _capacity = 0;
        char* _data = nullptr;

    public:
        String()
        {
            _length = 0;
            _capacity = Max_Cap;
            _data = new char[Max_Cap];
            _data[0] = 0;
        }


        String(const char* str)
        {
            assert(str != nullptr);
            _length = strlen(str);
            _capacity = getNextCap(_length);
            _data = new char[_capacity];
            strcpy(_data, str);
        }


        String(const String& str)
        {
            *this = str;
        }


        String& operator = (const String& str)
        {
            _length = str._length;
            _capacity = getNextCap(_length);

            if (_data) delete[] _data;
            _data = new char[_capacity];
            strcpy(_data, str._data);
            return *this;
        }


        String(String&& str)
        {
            _capacity = str._capacity;
            _length = str._length;
            _data = str._data;

            str._length = 0;
            str._capacity = Max_Cap;
            str._data = new char[Max_Cap];
            str._data[0] = 0;
        }


        ~String()
        {
            if (_data) {
                delete[] _data;
                _data = nullptr;
            }
        }


        char at(size_t index) const
        {
            assert(index <= _length);
            return _data[index];
        }


        char& operator[](size_t index)
        {
            assert(index <= _length);
            return _data[index];
        }


        char& operator[](size_t index) const
        {
            assert(index <= _length);
            return _data[index];
        }


        bool operator == (const String& other)
        {
            if (other._length != _length) return false;
            size_t i = 0;
            for (char c : *this) {
                if (c != other[i++])
                    return false;
            }

            return true;
        }


        operator const char* ()
        {
            return _data;
        }


        String& operator += (const String& str)
        {
            _length += str._length;
            if (_length >= _capacity) {
                _capacity = getNextCap(_length);
                auto temp = _data;
                _data = new char[_capacity];
                strcpy(_data, temp);
            }

            strcat(_data, str._data);
            return *this;
        }


        String operator + (const String& str) const
        {
            String temp = *this;
            temp += str;
            return temp;
        }


        bool operator > (const String& other) const
        {
            return _data[0] > other._data[0];
        }


        bool operator < (const String& other) const
        {
            return _data[0] < other._data[0];
        }


        bool operator == (const String& other) const
        {
            return _data[0] == other._data[0];
        }


        bool operator >= (const String& other) const
        {
            return _data[0] >= other._data[0];
        }


        size_t length() const { return _length; }
        size_t capacity() const { return _capacity; }
        bool isEmpty() const { return _length == 0; }

        char* begin() { return _data; }
        char* end()   { return &_data[_length]; }
        const char* cStr() const { return _data; }


    private:
        size_t getNextCap(size_t cap)
        {
            while (cap % Max_Cap != 0) ++cap;
            return cap;
        }
    };
}
