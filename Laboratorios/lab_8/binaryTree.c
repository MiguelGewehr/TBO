#include "binaryTree.h"

struct Node{
    Node *left;
    Node *right;
    Key key;
    Value value;
};

struct Tree{
    Node *root;
};

Node* rotate_right(Node *n){
    Node *t = n->left;
    n->left = t->right;
    t->right = n;
    return t;
}

Node* rotate_left(Node *n){
    Node *t = n->right;
    n->right = t->left;
    t->left = n;
    return t;
}

Node *node_construct(Node *left, Node *right, Key key, Value value){

    Node *node = (Node*) malloc(sizeof(Node));

    node->left = left;
    node->right = right;
    node->key = key;
    node->value = value;
    
    return node;
}