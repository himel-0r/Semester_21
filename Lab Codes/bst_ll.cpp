#include <bits/stdc++.h>
using namespace std;

class Treenode
{
public:
    int data;
    string name;
    int serial_no;
    int level_of_node;
    Treenode *left;
    Treenode *right;

    Treenode(int num);
};

Treenode::Treenode(int num)
{
    this->data = num;
    this->left = NULL;
    this->right = NULL;
    this->level_of_node = 0;
}

class BinarySearchTree
{
private:
    Treenode *root;
    int nodecount;

    Treenode *find_successor(Treenode *node);
    Treenode *find_predecessor(Treenode *node);
    void insert_number(Treenode *newnode, Treenode *node);
    bool search_node(int num, Treenode *node);
    Treenode *delete_node(int num, Treenode *node);
    void preorder(Treenode *node);
    void inorder(Treenode *node);
    void postorder(Treenode *node);
    int height(Treenode *node);
    bool complete();
    void complete(Treenode* node, vector<int> &v);
    bool perfect();
    bool perfect(Treenode* node, bool &ok, int lev);
    bool full_bt();
    bool full_bt(Treenode* node, bool &ok);
    bool balanced();
    bool balanced(Treenode* node, bool &ok);
    bool degenerate();
    bool left_skewed();
    bool right_skewed();
    void level_calc();
    void level_calc(Treenode *node, Treenode *par);

public:
    BinarySearchTree();
    void insert_number(int n); 
    bool search_node(int num);
    Treenode *delete_node(int num);
    void preorder();
    void inorder();
    void postorder();
    void check_bst_type();
    void print_tree();
};

BinarySearchTree::BinarySearchTree()
{
    this->root = NULL;
    this->nodecount = 0;
}

void BinarySearchTree::insert_number(int num)
{
    Treenode *newnode = new Treenode(num);
    (this->nodecount)++;

    if (this->root == NULL)
    {
        this->root = newnode;
    }
    else
    {
        this->insert_number(newnode, this->root);
    }

    // this->inorder();
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
    if (this->root != NULL) (this->nodecount)--;
    this->root = this->delete_node(num, this->root);

    // this->inorder();
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

bool BinarySearchTree::complete()
{
    vector<int> v;
    this->complete(this->root, v);

    vector<int> a(200, 0);
    int mx = v[0];

    for (int i=0; i<v.size(); i++) {
        a[v[i]]++;
        mx = max (mx, v[i]);
    }

    for (int i=0; i<mx; i++) {
        if (a[i] != (1<<i))
            return false;
    }

    return true;
}

void BinarySearchTree::complete(Treenode* node, vector<int> &v)
{
    v.push_back(node->level_of_node);

    if (node->left)
        this->complete(node->left, v);
    if (node->right)
        this->complete(node->right, v);
}

bool BinarySearchTree::perfect()
{
    int lev = -1;
    bool ok = true;

    this->perfect(this->root, ok, lev);

    return ok;
}

bool BinarySearchTree::perfect(Treenode *node, bool &ok, int lev)
{
    if (!ok) return ok;

    if (node->left == NULL && node->right == NULL) {
        if (lev < 0) 
            lev = node->level_of_node;
        else {
            if (lev != node->level_of_node) {
                ok = false;
                return ok;
            }
        }
    }
    
    if (node->right)
        this->perfect(node->right, ok, lev);
    if (node->left) 
        this->perfect(node->left, ok, lev);

    return ok;
}

bool BinarySearchTree::full_bt()
{
    bool ok = true;

    if (!(this->root)) return ok;

    this->full_bt(this->root, ok);

    return ok;
}

bool BinarySearchTree::full_bt(Treenode* node, bool &ok)
{
    if (!ok) return ok;

    if ((node->left == NULL) ^ (node->right == NULL)) {
        ok = false;
        return ok;
    }

    if (node->left) 
        full_bt(node->left, ok);

    if (node->right)
        full_bt(node->right, ok);

    return ok;
}

bool BinarySearchTree::balanced()
{
    bool ok = true;

    this->balanced(this->root, ok);

    return ok;
}

bool BinarySearchTree::balanced(Treenode* node, bool &ok) {
    if (!ok) return ok;

    if (abs(this->height(node->left) - this->height(node->right)) > 1) {
        ok = false;
        return ok;
    }

    if (node->left)
        this->balanced(node->left, ok);

    if (node->right)
        this->balanced(node->right, ok);

    return ok;
}

bool BinarySearchTree::degenerate()
{
    Treenode *node = this->root;

    while (node) {
        if ((node->left != NULL) && (node->right != NULL))
            return false;

        if (node->left)
            node = node->left;
        else if (node->right) 
            node = node->right;

        if (node == NULL)
            break;
    }

    return true;
}

bool BinarySearchTree::left_skewed()
{
    Treenode *node = this->root;

    while (node) {
        if (node->left == NULL && node->right != NULL)
            return false;
        
        node = node->left;
    }

    return true;
}

bool BinarySearchTree::right_skewed()
{
    Treenode* node = this->root;

    while (node) {
        if (node->right == NULL && node->left != NULL) 
            return false;

        node = node->right;
    }

    return true;
}

void BinarySearchTree::level_calc()
{
    this->root->level_of_node = 0;
    if (this->root->left)
        this->level_calc (this->root->left, this->root);
    if (this->root->right)
        this->level_calc (this->root->right, this->root);
}

void BinarySearchTree::level_calc(Treenode *node, Treenode *par)
{
    node->level_of_node = par->level_of_node + 1;

    if (node->left)
        this->level_calc(node->left, node);
    if (node->right)
        this->level_calc(node->right, node);
}

void BinarySearchTree::check_bst_type()
{
    if (this->full_bt()) {
        cout << "This is a full binary tree.\n";
    }
    if (this->complete()) {
        cout << "This binary tree is complete.\n";
    }
    if (this->balanced()) {
        cout << "Balanced binary tree.\n";
    }
    if (this->degenerate()) {
        cout << "Degenerate (or Pathological) Binary Tree";

        if (this->left_skewed())
            cout << " and Left-skewed BT\n";
        else if (this->right_skewed())
            cout << " and right-skewed BT\n";
        else 
            cout << ".\n";
    }

}

void BinarySearchTree::print_tree()
{
    int a[100000];

    memset (a, sizeof(a)/sizeof(a[0]), INT_MIN);
}

int main()
{
    BinarySearchTree b;

    b.insert_number(20);
    b.insert_number(30);
    b.insert_number(10);
    b.insert_number(34);
    b.insert_number(23);
    b.insert_number(13);
    b.insert_number(21);
    b.insert_number(12);

    b.pre
    
    
    order();

    b.delete_node(20);
}