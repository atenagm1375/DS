// Ashena Gorgan Mohammadi, 610394128

/* A bigNum is represented as a linked list. The task is to increment it by one.
 * If the right most character is not 9, then the task is done only by incrementing
 * that only character. Otherwise, it is needed to do the incrementation as far as 
 * there are 9s as digits.
 */

#include <iostream>
#include <string>
#include "SimpleLinkedList.h"

using namespace std;

void plus1(SimpleLinkedList<char>& bigNum){
    Node<char> *last = bigNum.getHead();
    while(last->link != 0)
        last = last->link;
    while(true){
        if(last->getData() < '9'){
            last->setData((char)(last->getData() + 1));
            break;
        }
        else{
            last->setData('0');
            Node<char> *temp = last;
            last = bigNum.getHead();
            while(last->link != temp)
                last = last->link;
        }
        if(last == bigNum.getHead()){
            if(last->getData() < '9'){
                last->setData((char)(last->getData() + 1));
                break;
            }
            else{
                last->setData('0');
                bigNum.insertFirst('1');
                break;
            }
        }
    }
}

int main(){
    SimpleLinkedList<char> bigNum;
    string str;
    cin >> str;
    for(int i = 0; i < str.size(); i++)
        bigNum.insertLast(str[i]);
    plus1(bigNum);
    Node<char> *node = bigNum.getHead();
    while(node != 0){
        cout << node->getData();
        node = node->link;
    }   
    return 0;
}