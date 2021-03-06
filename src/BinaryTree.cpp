#include "BinaryTree.h"

template <class T>
BinaryTreeNode<T>::BinaryTreeNode(T val, BinaryTreeNode* left , BinaryTreeNode* right)
{
    this->val = val;
    this->left = left;
    this->right = right;
}
template <class T >
BinaryTreeNode<T>::BinaryTreeNode(T val)
{
    this->val = val;
    this->left = nullptr;
    this->right = nullptr;
}