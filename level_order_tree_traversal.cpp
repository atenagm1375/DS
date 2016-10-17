// Ashena Gorgan Mohammadi, 610394128

/* Traversing a binary tree in level order recursively. 
 */

#include <iostream>
#include "BinaryTree.h"

using namespace std;

template<class type> void level_order_traversal(BinaryTree<type> &T){
    for(int i = 1; i < T.height; i++)
        print_level(T.root, i);
}

template<class type> void print_level(Node<type> *root, int level){
    if(root == 0)
        return;
    if(level == 1)
        cout << root.data << " ";
    else{
        print_level(root->left, level - 1);
        print_level(root->right, level - 1);
    }
}

int main(){
    BinaryTree<int> T;
    ...
    level_order_taversal(T);
    return 0;
}