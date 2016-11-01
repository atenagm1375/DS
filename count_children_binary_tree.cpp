// Ashena Gorgan Mohammadi, 610394128

#include <iostream>
#include "BinaryTree.h"

using namespace std;

template<class X> void count_children(node<X> *T, int& left, int& right){
    if(T != 0){
        if(T->left != 0){
            left = left + 1;
            count_children(T->left, left, right);
        }
        if(T->right != 0){
            right = right + 1;
            count_children(T->right, left, right);
        }
    }
}

int main(){
    BinaryTree<int> T;
    cout << "How many nodes would you like to insert?" << endl;
    int n;
    cin >> n;
    cout << "Enter the values:" << endl;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        T.insert(a);
    }
    int lchilds = 0, rchilds = 0;
    count_children(T.root, lchilds, rchilds);
    cout << "Number of left branches and right branches in order: ";
    cout << lchilds << " " << rchilds << endl;
    return 0;
}