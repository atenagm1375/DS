// Ashena Gorgan Mohammadi, 610394128

#include <iostream>
#include "BinaryTree.h"
#include <cmath>
#include <algorithm>

using namespace std;

template<class T> bool isAVL(Node<T> *root){
    if(root == 0)
        return true;
    return isAVL(root->left) && isAVL(root->right) &&
     abs(depth(root->left) - depth(root->right)) <= 1;
}

template<class T> int depth(Node<T> *root){
    if(root == 0)
        return 0;
    return (1 + max(depth(root->left), depth(root->right)));
}