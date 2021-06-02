#pragma once

#include <cstdint>
#include <cassert>
#include "LinkedList.h"
#include "String.h"


namespace Data
{
    template <typename T>
    struct HashItem
    {
        Data::String key;
        T value;

        HashItem(const Data::String& key, const T& value) : key(key), value(value) {}
    };
}


namespace Data
{
    template <typename T, size_t Capacity>
    class HashTable
    {
        Data::LinkedList<HashItem<T>>* _data[Capacity];
        size_t _length = 0;

    public:
        HashTable()
        {
            for (size_t i = 0; i < Capacity; ++i) {
                _data[i] = nullptr;
            }
        }


        ~HashTable()
        {
            for (size_t i = 0; i < Capacity; ++i) {
                if (_data[i]) {
                    delete _data[i];
                }
            }
        }


        template <typename... Args>
        void insert(const Data::String& key, Args&&... value)
        {
            size_t pos = hash(strToInt(key), Capacity);
            if (_data[pos] == nullptr) {
                _data[pos] = new LinkedList<HashItem<T>>;
            }

            T item(value...);
            _data[pos]->append(HashItem(key, item));
        }


        T get(const Data::String& key)
        {
            size_t pos = hash(strToInt(key), Capacity);
            auto* list = _data[pos];
            assert(list != nullptr);

            for (const HashItem<T>& i : *list) {
                if (i.key == key) {
                    return i.value;
                }
            }
        }


    private:
        bool exists(Data::LinkedList<T>& list, const T& item)
        {
            for (const T& i : list) {
                if (i == item) {
                    return true;
                }
            }

            return false;
        }


        size_t hash(size_t key, size_t capacity)
        {
            return (key & 0x7FFFFFFF) % capacity;
        }


        size_t strToInt(const Data::String& str)
        {
            size_t value = 7;

            for (char c : str) {
                value = 31 * value + (uint32_t)c;
            }

            return value;
        }
    };
}
