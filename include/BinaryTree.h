#pragma once
#include <string>


template<class T>
class BinaryTreeNode
{
    public:
    BinaryTreeNode(T val, BinaryTreeNode* left , BinaryTreeNode* right);
    BinaryTreeNode(T val);
    
    inline BinaryTreeNode* get_left(){return this->left;}
    inline BinaryTreeNode* get_right(){return this->right;}
    inline T get_val(){return this->val;}
    inline bool if_leaf() {return (this->left == nullptr && this->right == nullptr);}

    private:
        BinaryTreeNode* left;
        BinaryTreeNode* right;
        T val;
};
