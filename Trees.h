// Assignment3_DS.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct binaryTreeNode
{
    vector<string> info;
    binaryTreeNode *lnode;
    binaryTreeNode *rnode;
};

class BinaryTree
{
protected:
    binaryTreeNode *root;

private:
    void copyTree(binaryTreeNode *&copiedTreeRoot, binaryTreeNode *otherTreeRoot);
    void destroy(binaryTreeNode *&p);
    void inorder(binaryTreeNode *p) const;
    int height(binaryTreeNode *p) const;
    int max(int x, int y) const;
    int nodeCount(binaryTreeNode *p) const;

public:
    void printNode(binaryTreeNode *p) const;
    const BinaryTree &operator=(const BinaryTree &other);
    bool isEmpty() const;
    void inorderTraversal() const;
    int treeHeight() const;
    int treeNodeCount() const;
    void destroyTree();
    BinaryTree();
    BinaryTree(const BinaryTree &other);
    ~BinaryTree();
};

// Binary Tree
BinaryTree::BinaryTree()
{
    root = NULL;
}

BinaryTree::BinaryTree(const BinaryTree &other)
{
    if (other.root == NULL)
        root = NULL;
    else
        copyTree(root, other.root);
}

BinaryTree::~BinaryTree()
{
    destroy(root);
}

const BinaryTree &BinaryTree::operator=(const BinaryTree &other)
{
    if (this != &other)
    {
        if (root != NULL)
            destroy(root);

        if (other.root == NULL)
            root = NULL;
        else
            copyTree(this->root, other.root);
    }
    return *this;
}

void BinaryTree::inorderTraversal() const
{
    inorder(root);
}

int BinaryTree::treeNodeCount() const
{
    return nodeCount(root);
}

int BinaryTree::treeHeight() const
{
    return height(root);
}

bool BinaryTree::isEmpty() const
{
    if (root == NULL)
        return true;
    return false;
}

void BinaryTree::destroyTree()
{
    destroy(root);
}

// private member functions
void BinaryTree::printNode(binaryTreeNode *p) const
{
    if (p != NULL)
    {
        vector<string> student_info = p->info;
        cout << "[";
        for (int i = 0; i < student_info.size(); i++)
        {
            cout << student_info[i];
            if (i != student_info.size() - 1)
                cout << ", ";
        }
        cout << "]\n";
    }
}

int BinaryTree::max(int x, int y) const
{
    return x >= y ? x : y;
}

void BinaryTree::inorder(binaryTreeNode *p) const
{
    if (p != NULL)
    {
        inorder(p->lnode);
        printNode(p);
        inorder(p->rnode);
    }
}

int BinaryTree::height(binaryTreeNode *p) const
{
    if (p == NULL)
        return 0;
    else
        return 1 + max(height(p->lnode), height(p->rnode));
}

int BinaryTree::nodeCount(binaryTreeNode *p) const
{
    if (p == NULL)
        return 0;
    else
        return nodeCount(p->lnode) + nodeCount(p->rnode) + 1;
}

void BinaryTree::copyTree(binaryTreeNode *&copiedTreeRoot, binaryTreeNode *otherTreeRoot)
{
    if (otherTreeRoot == NULL)
        copiedTreeRoot = NULL;
    else
    {
        copiedTreeRoot = new binaryTreeNode;
        copiedTreeRoot->info = otherTreeRoot->info;
        copyTree(copiedTreeRoot->lnode, otherTreeRoot->lnode);
        copyTree(copiedTreeRoot->rnode, otherTreeRoot->rnode);
    }
}

void BinaryTree::destroy(binaryTreeNode *&p)
{
    if (p != NULL)
    {
        destroy(p->lnode);
        destroy(p->rnode);
        delete p;
        p = NULL;
    }
}

class BST : public BinaryTree
{
public:
    void search(int id);
    void insertStudent(vector<string> item);
    void deleteStudent(int id);

private:
    void deleteNode(binaryTreeNode *&p);
};

// Binary Search Tree
void BST::search(int id)
{
    binaryTreeNode *current;
    bool found = false;

    if (root == NULL)
        cerr << "can't search an empty tree" << endl;

    current = root;
    while (current != NULL && !found)
    {
        int currentID = stoi(current->info[0]);
        if (currentID == id)
        {
            found = true;
        }
        else if (currentID < id)
        {
            current = current->rnode;
        }
        else
        {
            current = current->lnode;
        }
    }

    if (found)
    {
        cout << "Student is found." << endl;
        printNode(current);
    }
    else
    {
        cout << "Student not found!" << endl;
    }
}

void BST::insertStudent(vector<string> item)
{
    binaryTreeNode *current;
    binaryTreeNode *trailCurrent;
    binaryTreeNode *newNode;

    newNode = new binaryTreeNode;
    // assert(newNode != NULL);
    newNode->info = item;
    newNode->lnode = NULL;
    newNode->rnode = NULL;

    if (root == NULL)
    {
        root = newNode;
    }
    else
    {
        current = root;

        while (current != NULL)
        {
            trailCurrent = current;
            int current_id = stoi(current->info[0]);

            if (current_id == stoi(item[0]))
            {
                cout << "The Student already exists!" << endl;
                return;
            }
            else if (current_id < stoi(item[0]))
            {
                current = current->rnode;
            }
            else
            {
                current = current->lnode;
            }
        }
        if (stoi(trailCurrent->info[0]) < stoi(item[0]))
        {
            trailCurrent->rnode = newNode;
        }
        else
        {
            trailCurrent->lnode = newNode;
        }
    }
}

void BST::deleteNode(binaryTreeNode *&p)
{
    binaryTreeNode *current;
    binaryTreeNode *trailCurrent;
    binaryTreeNode *temp;

    if (p == NULL)
        cout << "can't delete a null node" << endl;

    else if (p->lnode == NULL && p->rnode == NULL)
    {
        temp = p;
        p = NULL;
        delete temp;
    }
    else if (p->rnode == NULL)
    {
        temp = p;
        p = temp->lnode;
        delete temp;
    }
    else if (p->lnode == NULL)
    {
        temp = p;
        p = temp->rnode;
        delete temp;
    }
    else
    {
        current = p->lnode;
        trailCurrent = NULL;

        while (current->rnode != NULL)
        {
            trailCurrent = current;
            current = current->rnode;
        }

        p->info = current->info;

        if (trailCurrent == NULL)
            p->lnode = current->lnode;
        else
            trailCurrent->rnode = current->lnode;

        delete current;
    }
}

void BST::deleteStudent(int id)
{
    binaryTreeNode *current;
    binaryTreeNode *trailCurrent;
    bool found = false;

    if (root == NULL)
        cout << "can't delete from an empty tree" << endl;
    else
    {
        current = root;
        trailCurrent = root;

        while (current != NULL && !found)
        {
            int current_id = stoi(current->info[0]);

            if (current_id == id)
            {
                found = true;
            }
            else
            {
                trailCurrent = current;

                if (current_id > id)
                {
                    current = current->lnode;
                }
                else
                    current = current->rnode;
            }
        }
        if (current == NULL)
            cout << "Student not found!" << endl;
        else if (found)
        {
            cout << "Student is Found!" << endl;
            printNode(current);

            if (current == root)
                deleteNode(root);
            else if (stoi(trailCurrent->info[0]) < id)
                deleteNode(trailCurrent->rnode);
            else
                deleteNode(trailCurrent->lnode);

            cout << "Student is deleted.\n";
        }
    }
}


class AVL : public BinaryTree
{
private:
    void deleteNode(binaryTreeNode *&node);
    int balanceFactor(binaryTreeNode *node);
    int height(binaryTreeNode *root);
    binaryTreeNode *rotateRight(binaryTreeNode *node);
    binaryTreeNode *rotateLeft(binaryTreeNode *node);
    void setHeight(binaryTreeNode *node);
    binaryTreeNode *balance(binaryTreeNode *node);
    binaryTreeNode *balance(binaryTreeNode *node);

public:
    void search(int id);
    void insertStudent(vector<string> data);
    void deleteStudent(int id);
};

// ========================== Helper Functions ==========================

// Function to calculate balance factor of node
int AVL::balanceFactor(binaryTreeNode *node)
{
    if (node == nullptr)
        return 0;
    return height(node->lnode) - height(node->rnode);
}

int AVL::height(binaryTreeNode *root)
{
    if (root == nullptr)
        return 0;
    int left_height = height(root->lnode);
    int right_height = height(root->rnode);
    return 1 + std::max(left_height, right_height);
}

// balancing the tree
binaryTreeNode *AVL::balance(binaryTreeNode *node)
{
    setHeight(node);
    if (balanceFactor(node) == 2)
    {
        if (balanceFactor(node->lnode) < 0)
            node->lnode = rotateLeft(node->lnode);
        return rotateRight(node);
    }
    else if (balanceFactor(node) == -2)
    {
        if (balanceFactor(node->rnode) > 0)
            node->rnode = rotateRight(node->rnode);
        return rotateLeft(node);
    }
    return node;
}


// Function to perform right rotation
binaryTreeNode *AVL::rotateRight(binaryTreeNode *node)
{
    binaryTreeNode *newRoot = node->lnode;
    node->lnode = newRoot->rnode;
    newRoot->rnode = node;
    return newRoot;
}

// Function to perform left rotation
binaryTreeNode *AVL::rotateLeft(binaryTreeNode *node)
{
    binaryTreeNode *newRoot = node->rnode;
    node->rnode = newRoot->lnode;
    newRoot->lnode = node;
    setHeight(node);
    setHeight(newRoot);
    return newRoot;
}

// ========================== Functions To Be used ==========================
// Function to remove a student record from AVL Tree

void AVL::deleteStudent(int id)
{
    binaryTreeNode *current;
    binaryTreeNode *trailCurrent;
    bool found = false;

    if (root == NULL)
        cout << "can't delete from an empty tree" << endl;
    else
    {
        current = root;
        trailCurrent = root;

        while (current != NULL && !found)
        {
            int current_id = stoi(current->info[0]);

            if (current_id == id)
            {
                found = true;
            }
            else
            {
                trailCurrent = current;

                if (current_id > id)
                {
                    current = current->lnode;
                }
                else
                    current = current->rnode;
            }
        }
        if (current == NULL)
            cout << "Student not found!" << endl;
        else if (found)
        {
            cout << "Student is Found!" << endl;
            printNode(current);

            if (current == root)
                deleteNode(root);
            else if (stoi(trailCurrent->info[0]) < id)
                deleteNode(trailCurrent->rnode);
            else
                deleteNode(trailCurrent->lnode);

            cout << "Student is deleted.\n";
        }
    }
}

void AVL::search(int id)
{
    binaryTreeNode *current;
    bool found = false;

    if (root == NULL)
        cerr << "can't search an empty tree" << endl;

    current = root;
    while (current != NULL && !found)
    {
        int currentID = stoi(current->info[0]);
        if (currentID == id)
        {
            found = true;
            break;
        }
        else if (currentID < id)
        {
            current = current->rnode;
        }
        else
        {
            current = current->lnode;
        }
    }
    if (found)
    {
        cout << "Student is found." << endl;
        printNode(current);
    }
    else
    {
        cout << "Student not found!" << endl;
    }
}

void AVL::insertStudent(vector<string> data)
{
    binaryTreeNode *current;
    binaryTreeNode *trailCurrent;
    binaryTreeNode *newNode;

    newNode = new binaryTreeNode;
    // assert(newNode != NULL);
    newNode->info = data;
    newNode->lnode = NULL;
    newNode->rnode = NULL;

    if (root == NULL)
    {
        root = newNode;
    }
    else
    {
        current = root;

        while (current != NULL)
        {
            trailCurrent = current;
            int current_id = stoi(current->info[0]);

            if (current_id == stoi(data[0]))
            {
                cout << "The Student already exists!" << endl;
                return;
            }
            else if (current_id < stoi(data[0]))
            {
                current = current->rnode;
            }
            else
            {
                current = current->lnode;
            }
        }
        if (stoi(trailCurrent->info[0]) < stoi(data[0]))
        {
            trailCurrent->rnode = newNode;
        }
        else
        {
            trailCurrent->lnode = newNode;
        }
    }

    // balancing the tree after insirtion
    root = balance(root);
}
