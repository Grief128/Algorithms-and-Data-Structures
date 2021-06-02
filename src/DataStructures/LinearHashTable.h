#pragma once

#include <cstdint>
#include <cassert>
#include "String.h"


namespace Data
{
    template <typename T>
    struct HashItem
    {
        Data::String key;
        T value;

        HashItem() {}
        HashItem(const Data::String& key, const T& value) : key(key), value(value) {}
    };
}


namespace Data
{
    template <typename T>
    class LinearHashTable
    {
        HashItem<T>** _data;
        size_t _capacity;

    public:
        LinearHashTable(size_t capacity)
        {
            _capacity = nextPrime(capacity);
            _data = new HashItem<T>*[_capacity];
            for (size_t i = 0; i < _capacity; ++i) {
                _data[i] = nullptr;
            }
        }


        ~LinearHashTable()
        {
            for (size_t i = 0; i < _capacity; ++i) {
                if (_data[i]) {
                    delete _data[i];
                }
            }

            delete _data;
        }


        template <typename... Args>
        void insert(const Data::String& key, Args&&... value)
        {
            size_t pos = hash(strToInt(key), _capacity);

            for (;;) {
                if (_data[pos] == nullptr) {
                    _data[pos] = new HashItem<T>(key, value...);
                    break;
                } else {
                    ++pos;
                }
            }
        }


        T get(const Data::String& key)
        {
            size_t pos = hash(strToInt(key), _capacity);

            for (;;) {
                auto* item = _data[pos];
                if (_data[pos])
                {
                    if (_data[pos]->key == key) {
                        return _data[pos]->value;
                    } else {
                        pos += 1;
                        continue;
                    }
                }
                else if (_data == nullptr)
                {
                    pos += 1;
                    continue;
                }
                else
                {
                    assert(true);
                }
            }
        }


    private:
        size_t hash(size_t key, size_t _capacity)
        {
            return (key & 0x7FFFFFFF) % _capacity;
        }


        size_t strToInt(const Data::String& str)
        {
            size_t value = 7;

            for (char c : str) {
                value = 31 * value + (uint32_t)c;
            }

            return value;
        }

        bool isNumPrime(size_t n)
        {
            if (n <= 1)  return false;
            if (n <= 3)  return true;

            if (n%2 == 0 || n%3 == 0) return false;

            for (size_t i=5; i*i<=n; i += 6)
                if (n%i == 0 || n%(i+2) == 0)
                   return false;

            return true;
        }


        size_t nextPrime(size_t num)
        {
            if (num <= 1) return 2;
            while (!isNumPrime(num)) ++num;
            return num;
        }
    };
}
