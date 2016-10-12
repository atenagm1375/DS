// Ashena Gorgan Mohammadi, 610394128

/* The task is to remove all repeated elements from the list. To Do so, we traverse
 * the list. from head up to that point is checked. If it was repeated, then that node
 * is ommited.
 */

#include <iostream>
#include "SimpleLinkedList.h"

using namespace std;

void omit_repeated(SimpleLinkedList<int>& list){
    Node<int> *temp = list.getHead();
    int place = 1;
    while(temp != 0){
        Node<int> *cur = list.getHead();
        bool t = true;
        while(t && cur != temp){
            if(cur->getData() == temp->getData()){
                cout << temp->getData() << " is omited from place " << place << endl;
                Node<int> *node = temp->link;
                list.remove(temp);
                temp = node;
                t = false;
            }
            cur = cur->link;
        }
        if(t)
            temp = temp->link;
        place++;
    }
}

int main(){
    SimpleLinkedList<int> list;
    cout << "Enter the elements of the list(ctrl+D to end):" << endl;
    int a;
    while(cin >> a)
        list.insertLast(a);
    omit_repeated(list);
    return 0;
}