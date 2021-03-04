#include "BinaryTree.h"

BinaryTreeNode::BinaryTreeNode(std::string val, BinaryTreeNode* left , BinaryTreeNode* right)
{
    this->val = val;
    this->left = left;
    this->right = right;
}

BinaryTreeNode::BinaryTreeNode(std::string val)
{
    this->val = val;
    this->left = nullptr;
    this->right = nullptr;
}