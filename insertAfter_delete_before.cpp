// Ashena Gorgan Mohammadi, 610394128

/* functions for inserting a node after a specified node in bidirectional list and 
 * removing a node from list which is before an specified node.
 */

#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

void insertAfter(DNode<int> *T, DNode<int> *X, int val){
    DNode<type> *temp = new DNode(val);
    temp->SLINK = X->SLINK;
    temp->PLINK = X;
    X->SLINK->PLINK = temp;
    X->SLINK = temp;
}

void deleteBefore(DNode<int> *T, DNode<int> *X){
    DNode<int> *temp = X->PLINK;
    temp->PLINK->SLINK = X;
    X->PLINK = temp->PLINK;
    temp->SLINK = temp->PLINK = 0;
    delete temp;
}

int main(){
    DoublyLinkedList<int> list;
    ...
    DNode<int> *T = list.getHead();
    list.insertAfter(T, X, val);
    list.deleteBefore(T, X);
    return 0;
}