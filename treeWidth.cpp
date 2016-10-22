// Ashena Gorgan Mohammadi, 610394128

#include <iostream>
#include "BinaryTree.h"
#include <algorithm>

using namespace std;

template<class T> int levelWidth(Node<T> *root, int level){
    if(root == 0)
        return 0;
    if(level == 1)
        return 1;
    return levelWidth(root->left, level - 1) + levelWidth(root->right, level - 1);
}

template<class T> int depth(Node<T> *root){
    if(root == 0)
        return 0;
    return 1 + max(depth(root->left), depth(root->right));
}

template<class T> int treeWidth(Node<T> *root){
    int width = 0;
    for(int i = 0; i < depth(root); i++){
        int temp = levelWidth(root, i + 1);
        width = max(temp, width);
    }
    return width;
}