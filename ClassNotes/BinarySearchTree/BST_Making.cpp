#include <bits/stdc++.h>
using namespace std;

class Treenode
{
public:
    int data;
    Treenode *left;
    Treenode *right;
    Treenode *parent;

    Treenode(int num);
    Treenode(int num, Treenode *par);
};

Treenode::Treenode(int num)
{
    this->data = num;
    this->left = NULL;
    this->right = NULL;
    this->parent = NULL;
}

Treenode::Treenode(int num, Treenode *par)
{
    this->data = num;
    this->left = NULL;
    this->right = NULL;
    this->parent = par;
}

class BinarySearchTree
{
private:
    Treenode *root;

    Treenode *find_successor(Treenode *node);
    Treenode *find_predecessor(Treenode *node);
    void insert_number(Treenode *newnode, Treenode *node);
    bool search_node(int num, Treenode *node);
    Treenode *findPosition(int num, Treenode *node);
    Treenode *delete_node(int num, Treenode *node);
    void preorder(Treenode *node);
    void inorder(Treenode *node);
    void postorder(Treenode *node);
    int height(Treenode *node);
    int find_successor(Treenode *node, vector<int> v);
    int find_predecessor(Treenode *node, vector<int> v);

public:
    BinarySearchTree();
    void insert_number(int n);
    bool search_node(int num);
    Treenode *findPosition(int num);
    int find_successor(int num);
    int find_predecessor(int num);
    Treenode *delete_node(int num);
    void preorder();
    void inorder();
    void postorder();
    int height();
    int minimum();
    int maximum();
};

BinarySearchTree::BinarySearchTree()
{
    this->root = NULL;
}

void BinarySearchTree::insert_number(int num)
{
    Treenode *newnode = new Treenode(num);

    if (this->root == NULL)
    {
        this->root = newnode;
    }
    else
    {
        this->insert_number(newnode, this->root);
    }
}

void BinarySearchTree::insert_number(Treenode *newnode, Treenode *node)
{
    if (newnode->data <= node->data)
    {
        if (node->left)
        {
            this->insert_number(newnode, node->left);
        }
        else
        {
            node->left = newnode;
        }
    }
    else
    {
        if (node->right)
        {
            this->insert_number(newnode, node->right);
        }
        else
        {
            node->right = newnode;
        }
    }
}

bool BinarySearchTree::search_node(int num)
{
    return this->search_node(num, this->root);
}

bool BinarySearchTree::search_node(int num, Treenode *node)
{
    if (!node)
    {
        return false;
    }
    else if (node->data == num)
    {
        return true;
    }
    else if (num < node->data)
    {
        return this->search_node(num, node->left);
    }
    else
    {
        return this->search_node(num, node->right);
    }
}

Treenode *BinarySearchTree::findPosition(int num)
{
    if (this->root->data == num)
        return this->root;
    else
        return this->findPosition(num, this->root);
}

Treenode *BinarySearchTree::findPosition(int num, Treenode *node)
{
    if (!node)
        return NULL;
    else if (node->data == num)
        return node;
    else if (num < node->data)
        return this->findPosition(num, node->left);
    else
        return this->findPosition(num, node->right);
}

Treenode *BinarySearchTree::find_successor(Treenode *node)
{
    while (node->left)
        node = node->left;
    return node;
}

Treenode *BinarySearchTree::find_predecessor(Treenode *node)
{
    while (node->right)
        node = node->right;
    return node;
}

Treenode *BinarySearchTree::delete_node(int num)
{
    this->root = this->delete_node(num, this->root);
}

Treenode *BinarySearchTree::delete_node(int num, Treenode *node)
{
    if (!node)
        return node;

    if (num < node->data)
        node->left = this->delete_node(num, node->left);
    else if (num > node->data)
        node->right = this->delete_node(num, node->right);
    else
    {
        // Case 1 : No children
        if (!(node->left) and !(node->right))
            node = NULL;

        // Case 2 : One Child
        else if (!(node->right))
            node = node->right;
        else if (!(node->left))
            node = node->left;

        // Case 3 : Two children
        else
        {
            Treenode *successor = this->find_successor(node->right);
            node->data = successor->data;
            node->right = this->delete_node(successor->data, node->right);

            /*
            Treenode* predecessor = this->find_predecessor(node->left);
            node->data = predecessor->data;
            node->left = this->delete_node2(predecessor->data, node->left);
            */
        }
    }
    return node;
}

void BinarySearchTree::preorder()
{
    this->preorder(this->root);
    cout << endl;
}

void BinarySearchTree::preorder(Treenode *node)
{
    cout << (node->data) << " ";

    if (node->left)
        this->preorder(node->left);

    if (node->right)
        this->preorder(node->right);
}

void BinarySearchTree::inorder()
{
    this->inorder(this->root);
    cout << endl;
}

void BinarySearchTree::inorder(Treenode *node)
{
    if (node->left)
        this->inorder(node->left);

    cout << (node->data) << " ";

    if (node->right)
        this->inorder(node->right);
}

void BinarySearchTree::postorder()
{
    this->postorder(this->root);
    cout << endl;
}

void BinarySearchTree::postorder(Treenode *node)
{
    if (node->left)
        this->postorder(node->left);

    if (node->right)
        this->postorder(node->right);

    cout << (node->data) << " ";
}

int BinarySearchTree::height()
{
    return this->height(this->root);
}

int BinarySearchTree::height(Treenode *node)
{
    int h = 0;

    if (node)
    {
        int l_height = height(node->left);
        int r_height = height(node->right);

        int max_height = max(l_height, r_height);

        h = max_height + 1;
    }

    return h;
}

int BinarySearchTree::minimum() 
{
    Treenode *node = this->root;
    
    while (node->left) {
        node = node->left;
    }

    return (node->data);
}

int BinarySearchTree::maximum()
{
    Treenode *node = this->root;

    while (node->right) {
        node = node->right;
    }

    return (node->data);
}

int BinarySearchTree::find_predecessor(int num)
{
    vector<int> v;
    this->find_predecessor(this->root, v);

    int lb = lower_bound(v.begin(), v.end(), num) - v.begin();

    if (lb != 0)
        return v[lb-1];
    else 
        return INT_MIN;
}

int BinarySearchTree::find_predecessor (Treenode *node, vector<int> v)
{
    if (node->left)
        this->find_predecessor(node->left, v);

    v.push_back(node->data);

    if (node->right)
        this->find_predecessor(node->right, v);
}

int BinarySearchTree::find_successor(int num)
{
    vector<int> v;
    this->find_successor(this->root, v);

    int ub = lower_bound(v.begin(), v.end(), num) - v.begin();

    if (ub != v.size())
        return v[ub];
    else    
        return INT_MAX;
}

int BinarySearchTree::find_successor(Treenode *node, vector<int> v)
{
    if (node->left) 
        this->find_successor(node->left, v);

    v.push_back(node->data);

    if (node->right)
        this->find_successor(node->right, v);
}

int main()
{
    BinarySearchTree bst;

    freopen("btsPractice.txt", "w", stdout);

    bst.insert_number(2);
    bst.insert_number(7);
    bst.insert_number(6);
    bst.insert_number(8);
    bst.insert_number(3);
    bst.insert_number(1);
    bst.insert_number(2);
    bst.insert_number(7);
    bst.insert_number(10);
    // bst.insert_number(13);

    cout << "Height: " << bst.height() << endl;

    bst.inorder();
    bst.preorder();
    bst.postorder();

    bst.delete_node(10);

    bst.preorder();
}