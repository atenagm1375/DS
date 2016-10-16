// Ashena Gorgan Mohammadi, 610394128

/* The task is to reverse the order of elements in a bidirectional linked list.
 * To do so, we need to reverse all the PLINKs and SLINKs.
 */

#include <iostream>
#include "Doubly_linked_list.h"

using namespace std;

template<class T> void reverse_doubly_linked_list(DoublyLinkedList<T>& list){
    DNode<T> *temp = list.getHead();
    DNode<T> *comp = list.getHead();
    DNode<T> *aid = 0;

    while(true){
        aid = temp->PLink;
        temp->PLink = temp->SLink;
        temp->SLink = aid;
        temp = temp->PLink;
        if(temp == comp)
            break;
    }

    if(aid != 0){
        list.setHead(aid->PLink);
    }
}

int main(){
    DoublyLinkedList<int> D;
    for(int i = 0; i < 10; i++)
        D.insertFirst(i);
    reverse_doubly_linked_list(D);
    DNode<int> *temp = D.getHead();
    for(int i = 0; i < 10; i++){
        cout << temp->data << endl;
        temp = temp->SLink;
    }
    return 0;
}