#pragma once

#include <cstdint>
#include <cassert>

namespace Data
{
    template <typename T>
    struct BinaryTreeNode
    {
        T data;
        BinaryTreeNode<T>* left = nullptr;
        BinaryTreeNode<T>* right = nullptr;


        template <typename... Args>
        BinaryTreeNode(Args&&... args) : data(args...) {}
    };
}


namespace Data
{
    template <typename T>
    class BinaryTree
    {
    private:
        BinaryTreeNode<T>* _root = nullptr;

    public:
        enum class Traverse { Pre_Order, In_Order, Post_Order };

        BinaryTree()
        {
        }


        ~BinaryTree()
        {
            clearTree(_root);
        }


        template <typename... Args>
        void insert(Args&&... args)
        {
            auto item = T(args...);
            auto newNode = new BinaryTreeNode<T>(item);

            if (_root == nullptr)
            {
                _root = newNode;
            }
            else
            {
                BinaryTreeNode<T>* curNode = _root;
                BinaryTreeNode<T>* parentNode = nullptr;

                for (;;)
                {
                    parentNode = curNode;
                    if (item < curNode->data)
                    {
                        curNode = curNode->left;
                        if (curNode == nullptr) {
                            parentNode->left = newNode;
                            return;
                        }
                    }
                    else
                    {
                        curNode = curNode->right;
                        if (curNode == nullptr) {
                            parentNode->right = newNode;
                            return;
                        }
                    }
                }
            }
        }


        BinaryTreeNode<T>* min()
        {
            BinaryTreeNode<T>* last = nullptr;
            BinaryTreeNode<T>* curr = _root;

            while (curr != nullptr) {
                last = curr;
                curr = curr->left;
            }

            return last;
        }


        BinaryTreeNode<T>* max()
        {
            BinaryTreeNode<T>* last = nullptr;
            BinaryTreeNode<T>* curr = _root;

            while (curr != nullptr) {
                last = curr;
                curr = curr->right;
            }

            return last;
        }


        template <typename F>
        void traverse(F func, Traverse tr = Traverse::Pre_Order)
        {

            switch (tr)
            {
                case Traverse::Pre_Order:
                    preOrder(func, _root);
                    break;

                case Traverse::In_Order:
                    inOrder(func, _root);
                    break;

                case Traverse::Post_Order:
                    postOrder(func, _root);
                    break;
            }
        }


        BinaryTreeNode<T>* find(const T& item)
        {
            auto curNode = _root;

            while (curNode->data != item)
            {
                if (item < curNode->data) {
                    curNode = curNode->left;
                } else {
                    curNode = curNode->right;
                }

                if (curNode == nullptr) {
                    return nullptr;
                }
            }

            return curNode;
        }


    private:
        void clearTree(BinaryTreeNode<T>* root)
        {
            if (root != nullptr) {
                clearTree(root->left);
                clearTree(root->right);
                delete root;
            }
        }


        template <typename F>
        void preOrder(F func, BinaryTreeNode<T>* root)
        {
            if (root != nullptr) {
                func(root->data);
                preOrder(func, root->left);
                preOrder(func, root->right);
            }
        }


        template <typename F>
        void inOrder(F func, BinaryTreeNode<T>* root)
        {
            if (root != nullptr) {
                inOrder(func, root->left);
                func(root->data);
                inOrder(func, root->right);
            }
        }


        template <typename F>
        void postOrder(F func, BinaryTreeNode<T>* root)
        {
            if (root != nullptr) {
                postOrder(func, root->left);
                postOrder(func, root->right);
                func(root->data);
            }
        }
    };
}
