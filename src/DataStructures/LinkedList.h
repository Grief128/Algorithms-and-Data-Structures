#pragma once

#include <initializer_list>
#include <cassert>


namespace Data
{
    template <typename T>
    struct LinkedListNode
    {
        T data;
        LinkedListNode<T>* prev = nullptr;
        LinkedListNode<T>* next = nullptr;

    public:
        LinkedListNode(const T& data) : data(data) {}
    };
}


namespace Data
{
    template <typename T>
    class LinkedListIterator
    {
    private:
        LinkedListNode<T>* _node = nullptr;

    public:
        LinkedListIterator(LinkedListNode<T>* node) : _node(node) {}

        T& operator * () { return _node->data; }
        T* operator -> () { return &_node->data; }
        bool operator!=(const LinkedListIterator& other) const { return _node != other._node; }
        bool operator==(const LinkedListIterator& other) const { return _node == other._node; }

        LinkedListIterator operator ++ ()
        {
            _node = _node->next;
            return *this;
        }


        LinkedListIterator operator -- ()
        {
            _node = _node->prev;
            return *this;
        }
    };
}



namespace Data
{
    template <typename T>
    class LinkedList
    {
    private:
        LinkedListNode<T>* _start = nullptr;
        LinkedListNode<T>* _end = nullptr;
        size_t _length = 0;

    public:
        LinkedList()
        {
        }


        ~LinkedList()
        {
            while (!isEmpty()) {
                this->removeFirst();
            }
        }


        template <typename... Args>
        void append(Args... args)
        {
            auto node = new LinkedListNode<T>(args...);

            if (_start == nullptr) {
                node->prev = nullptr;
                node->next = nullptr;
                _start = _end = node;
            } else {
                node->prev = _end;
                node->next = nullptr;
                _end->next = node;
                _end = node;
            }

            ++_length;
        }


        template <typename... Args>
        void preppend(Args&&... args)
        {
            auto node = new LinkedListNode<T>(args...);

            if (_start == nullptr) {
                node->prev = nullptr;
                node->next = nullptr;
                _start = _end = node;
            } else {
                node->prev = nullptr;
                node->next = _start;
                _start->prev = node;
                _start = node;
            }

            ++_length;
        }


        void removeLast()
        {
            if (isEmpty()) {
                return;
            } else if (length() == 1) {
                delete _start;
                _start = _end = nullptr;
            } else {
                auto temp = _end;
                _end = _end->prev;
                _end->next = nullptr;
                delete temp;
            }

            --_length;
        }


        void removeFirst()
        {
            if (isEmpty()) {
                return;
            } else if (length() == 1) {
                delete _start;
                _start = _end = nullptr;
            } else {
                auto temp = _start;
                _start = _start->next;
                delete temp;
            }

            --_length;
        }


        template <typename F>
        void traverse(F func)
        {
            auto i = _start;
            while (i != nullptr) {
                func(i->data);
                i = i->next;
            }
        }


        size_t length() const { return _length; }
        bool isEmpty() const { return (_length == 0);}
        T first() const { return _start->data; }
        T last() const { return _end->data; }

        LinkedListIterator<T> begin() { return _start; }
        LinkedListIterator<T> end()   { return _end->next; }
    };

}
