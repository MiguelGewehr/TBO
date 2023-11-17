#ifndef _BINARY_TREE_
#define _BINARY_TREE_

#define int Key;
#define char Value;

typedef Node Node;
typedef struct Tree Tree;

Node *node_construct(Node *left, Node *right, Key key, Value value);
Node* rotate_right(Node *n);

#endif