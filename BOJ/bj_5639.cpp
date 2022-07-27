#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Node {
    public:
    int key;
    Node* leftChild = NULL;
    Node* rightChild = NULL;

    Node(int val) {
        key = val;
    }
    ~Node();
    void addLeftChild(Node* child) {
        leftChild = child;
    }
    void addRightChild(Node* child) {
        rightChild = child;
    }
};

void insertNode(Node* root, int key);
void postOrderTraverse(Node* root);

int main() {
    int key;
    Node* root = NULL;
    while (cin >> key)
    {   
        if (root == NULL) {
            root = new Node(key);
        }
        else {
            insertNode(root, key);
        }

    }
    postOrderTraverse(root);
    
    return 0;
}

void insertNode(Node* root, int key) {
    if (root->key > key) {
        if (root->leftChild == NULL) {
            Node* newNode = new Node(key);
            root->addLeftChild(newNode);
        }
        else {
            insertNode(root->leftChild, key);
        }
    }
    else {
        if (root->rightChild == NULL) {
            Node* newNode = new Node(key);
            root->addRightChild(newNode);
        }
        else {
            insertNode(root->rightChild, key);
        }
    }
}

void postOrderTraverse(Node* root) {
    if (root != NULL) {
        postOrderTraverse(root->leftChild);
        postOrderTraverse(root->rightChild);
        printf("%d\n", root->key);
        free(root);
    }
}