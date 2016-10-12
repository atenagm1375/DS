// Ashena Gorgan Mohammadi, 610394128

/* A simple linked list is given. The task is to reverse the order of elements
 * in the list. Beginning from last, we put the very last element as new head
 * and change all the links to point to their previous elements.
 */

#include <iostream>
#include "SimpleLinkedList.h"

using namespace std;

template<class T> void reverseList(SimpleLinkedList<T>& list){
    Node<T> *temp = list.getHead();
    for(int i = 0; i < list.size() - 2; i++)
        temp = temp->link; // always pointing to the element before the last modified element
    Node<T> *newHead = temp->link; // keeps the last element of the base list as head of the new one
    int l = list.size() - 2;
    while(temp != list.getHead()){
        temp->link->link = temp;
        l--;
        temp = list.getHead();
        for(int i = 0; i < l; i++)
            temp = temp->link;
    }
    list.getHead()->link->link = temp;
    list.getHead()->link = 0;
    list.setHead(newHead);
}

int main(){
    SimpleLinkedList<int> list;
    int i;
    cout << "Enter integers of the list(ctrl+D for finish):";
    while(cin >> i)
        list.insertLast(i);
    cout << endl;
    reverseList(list);
    Node<int> *node = list.getHead();
    while(node != 0){
        cout << node->getData() << " ";
        node = node->link;
    }
    return 0;
}