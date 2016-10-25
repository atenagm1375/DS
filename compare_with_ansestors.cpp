// Ashena Gorgan Mohammadi, 610394128

/* distinguish whether there is any child which is bigger than its ancestors
 * in a binary tree.
 */

#include <iostream>
#include "BinaryTree.h"
#include <cstdlib>

using namespace std;

void pre_order_traversal(node<int> *T, int& max){
    if(T != 0){
        if(T->data > max){
            cout << "YES" << endl;
            exit(0);
        }
        pre_order_traversal(T->left, max);
        pre_order_traversal(T->right, max);
    }
}

void is_bigger_than_ancestors(node<int> *T){
    int max = T->data;
    pre_order_traversal(T, max);
}

int main(){
    BinaryTree<int> bt;
    bt.insert(10);
    bt.insert(6);
    bt.insert(7);
    bt.insert(2);
    bt.insert(1);
    bt.insert(0);
    bt.insert(3);
    bt.insert(4);
    is_bigger_than_ancestors(bt.root);
    cout << "NO" << endl;
    return 0;
}
