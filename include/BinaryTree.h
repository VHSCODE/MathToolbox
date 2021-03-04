#pragma once
#include <string>

class BinaryTreeNode
{
    public:
    BinaryTreeNode(std::string val, BinaryTreeNode* left , BinaryTreeNode* right);
    BinaryTreeNode(std::string);
    private:
        BinaryTreeNode* left;
        BinaryTreeNode* right;
        std::string val;
};