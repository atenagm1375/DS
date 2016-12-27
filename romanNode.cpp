// Ashena Gorgan Mohammadi, 610394128

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

template<class T> struct node{
    T data;
    node<T> *left;
    node<T> *right;
    int descendants;
    bool isRoman;
};

template<class T> class BinaryTree{

public:

    BinaryTree(){
        root = 0;
    }

    void insert(T val){
        if(root != 0)
            insert(val, root);
        else{
            root = new node<T>;
            root->data = val;
            root->left = 0;
            root->right = 0;
            root->descendants = 0;
            root->isRoman = false;
        }
    }

    node<T> *root;

private:

    void insert(T val, node<T> *leaf){
        if(val < leaf->data){
            if(leaf->left != 0)
                insert(val, leaf->left);
            else{
                leaf->left = new node<T>;
                leaf->left->data = val;
                leaf->left->left = 0;
                leaf->left->right = 0;
                leaf->left->descendants = 0;
                leaf->left->isRoman = false;
            }
        }
        else{
            if(leaf->right != 0)
                insert(val, leaf->right);
            else{
                leaf->right = new node<T>;
                leaf->right->data = val;
                leaf->right->left = 0;
                leaf->right->right = 0;
                leaf->right->descendants = 0;
                leaf->right->isRoman = false;
            }
        }
    }
};

vector<node<int> *> *ans;

void roman(node<int> *root){
    if(root == 0)
        return;
    if(root->right == 0 && root->left == 0){
        root->descendants = 1;
        root->isRoman = true;
        return;
    }
    int r = root->data;
    int ldes = 0;
    int rdes = 0;
    bool isLroman = false;
    bool isRroman = false;
    if(root->right != 0){
        roman(root->right);
        rdes = root->right->descendants;
        isRroman = root->right->isRoman;
        if(root->left == 0)
            isLroman = true;
    }
    if(root->left != 0){
        roman(root->left);
        ldes = root->left->descendants;
        isLroman = root->left->isRoman;
        if(root->right == 0)
            isRroman = true;
    }
    //cout << abs(ldes - rdes) << endl;
    if(abs(ldes - rdes) <= 5 && isLroman && isRroman)
        root->isRoman = true;
    else{
        root->isRoman = false;
    }
    root->descendants = ldes + rdes + 1;
    if(abs(ldes - rdes) > 5 && isLroman && isRroman)
        ans->push_back(root);
}

int main(){
    BinaryTree<int> bt;
    for(int i = 10; i <= 12; i++)
        bt.insert(i);
    for(int i = 9; i >= 1; i--)
        bt.insert(i);
    ans = new vector<node<int> *>();
    roman(bt.root);
    for(int i = 0; i < ans->size(); i++)
        cout << ans->at(i)->data << endl;
}
