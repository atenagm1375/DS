// Ashena Gorgan Mohammadi, 610394128

#include <iostream>
#include "BinaryTree.h"

using namespace std;

template<class T> void swapTree(Node<T> *r){
    Node<T> *temp = r->left;
    r->left = r->right;
    r->right = temp;
    swapTree(r->left);
    swapTree(r->right);
}