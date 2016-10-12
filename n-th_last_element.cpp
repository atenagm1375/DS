// Ashena Gorgan Mohammadi, 610394128

#include <iostream>
#include "SimpleLinkedList.h"

using namespace std;

int nth_last_element(SimpleLinkedList<int>& list, int n){
    Node<int> *temp = list.getHead();
    Node<int> *ans = list.getHead();
    for(int i = 0; i < n - 1; i++)
        temp = temp->link;
    while(temp->link != 0){
        temp = temp->link;
        ans = ans->link;
    }
    return ans->getData();
}

int main(){
    SimpleLinkedList<int> list;
    int num;
    cout << "Enter number of elements of the list:";
    cin >> num;
    cout << "Enter the elements of the list:" << endl;
    for(int i = 0; i < num; i++){
        int a;
        cin >> a;
        list.insertLast(a);
    }
    int n;
    cout << endl << "Enter n:";
    cin >> n;
    cout << nth_last_element(list, n) << endl;
    return 0;
}