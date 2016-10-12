// Ashena Gorgan Mohammadi, 610394128

/* The task is to find an integer which is not in the list. max+1 is the answer in O(n).
 */

#include <iostream>
#include "SimpleLinkedList.h"

using namespace std;

int not_in_list(SimpleLinkedList<int>& list){
    int max = list.getHead()->getData();
    Node<int> *node = list. getHead();
    while(node != 0){
        if(node->getData() > max)
            max = node->getData();
        node = node->link;
    }
    return max + 1;
}

int main(){
    SimpleLinkedList<int> list;
    cout << "Enter elements of the list(ctrl+D to end):" << endl;
    int a;
    while(cin >> a)
        list.insertLast(a);
    cout << endl << not_in_list(list) << endl;
    return 0;
}