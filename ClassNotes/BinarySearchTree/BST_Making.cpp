#include<bits/stdc++.h>
using namespace std;

class Treenode {
public:
    int data;
    Treenode* left;
    Treenode* right;
    Treenode* parent;

    Treenode (int num);
    Treenode (int num, Treenode* par);
};

Treenode::Treenode(int num)
{
    this->data = data;
    this->left = NULL;
    this->right = NULL;
    this->parent = NULL;
}

Treenode::Treenode(int num, Treenode* par)
{
    this->data = data;
    this->left = NULL;
    this->right = NULL;
    this->parent = par;
}

class BinarySearchTree {
private:
    Treenode* root;

public:
    BinarySearchTree();
    void in_order();
    void pre_order();
    void post_order();
    Treenode* search_node (int num);
    void insert_node (int num);
    void delete_node (int num);
};

BinarySearchTree::BinarySearchTree()
{
    this->root = NULL;
}

void BinarySearchTree::insert_node(int num)
{
    Treenode* newnode = new Treenode(num);
    
}