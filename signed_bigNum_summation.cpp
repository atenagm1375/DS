// Ashena Gorgan Mohammadi, 610394128

/* Two signed integers are given. The task is to show them in a simple linked list and
 * add them up. Their implementation of them in the list is: +1297 -----> + 7 9 2 1
 * The process has been divided into two parts. If the two inputs have the same sign, 
 * they are added based on the "add" function; otherwise, they are subtracted in "sub"
 * function. "isBigger" is a function that distinguishes which one of these inputs with 
 * different signs is bigger, ignoring their signs.
 */

#include <iostream>
#include "SimpleLinkedList.h"
#include <string>

using namespace std;

void add(SimpleLinkedList<char> num1, SimpleLinkedList<char> num2, SimpleLinkedList<char>& ans){

    Node<char> *n1 = num1.getHead()->link;
    Node<char> *n2 = num2.getHead()->link;

    while(n1 != 0){
        int a = (n1->getData() - '0') + (n2->getData() - '0');
        ans.insertLast((a % 10) + '0');
        n1 = n1->link;
        n2 = n2->link;
        if(n1 == 0){
            if(a / 10 != 0){
                ans.insertLast(a / 10 + '0');
                return;
            }
        }
        else
            n1->setData((char)(n1->getData() + a / 10));
    }
}

bool isBigger(SimpleLinkedList<char>& num1, SimpleLinkedList<char>& num2){

    Node<char> *n1 = num1.getHead()->link;
    Node<char> *n2 = num2.getHead()->link;

    while(n1->link != 0){
        n1 = n1->link;
        n2 = n2->link;
    }

    if(n1->getData() < n2->getData())
        return false;
    else if(n1->getData() > n2->getData())
        return true;
    if(n1->link == 0 && n2->link == 0 && n1->getData() == n2->getData())
        return true;

    while(n1->getData() == n2->getData()){
        Node<char> *p1 = num1.getHead()->link;
        Node<char> *p2 = num2.getHead()->link;

        while(p1->link != n1){
            p1 = p1->link;
            p2 = p2->link;
        }

        if(p1->getData() < p2->getData())
            return false;
        else if(p1->getData() > p2->getData())
            return true;

        n1 = p1;
        n2 = p2;

        if(n1 == num1.getHead()->link){
            if(p1->getData() < p2->getData())
                return false;
            else
                return true;
        }
    }
    return true;
}

void sub(SimpleLinkedList<char> num1, SimpleLinkedList<char> num2, SimpleLinkedList<char>& ans){

    ans.insertFirst(num1.getHead()->getData());
    Node<char> *n1 = num1.getHead()->link;
    Node<char> *n2 = num2.getHead()->link;

    while(n1 != 0){
        int a;
        if(n1->getData() >= n2->getData())
            a = n1->getData() - n2->getData();
        else{
            a = (n1->getData() - '0' + 10) - (n2->getData() - '0');
            n1->link->setData((n1->link->getData() - '0' - 1) + '0');
        }

        ans.insertLast(a + '0');
        n1 = n1->link;
        n2 = n2->link;
    }

    while(true){
        Node<char> *node = ans.getHead()->link;

        while(node->link != 0)
            node = node->link;

        if(node->getData() == '0')
            ans.remove(node);
        else
            break;

        if(ans.size() == 1){
            ans.getHead()->setData('0');
            return;
        }
    }
}

void sum(SimpleLinkedList<char>& num1, SimpleLinkedList<char>& num2, SimpleLinkedList<char>& ans){

    if(num1.getHead()->getData() == num2.getHead()->getData()){
        ans.insertFirst(num1.getHead()->getData());
        add(num1, num2, ans);
        return;
    }

    isBigger(num1, num2) ? sub(num1, num2, ans) : sub(num2, num1, ans);
}

int main(){
    string num1, num2;
    cout << "Enter two signed integers:" << endl;
    cin >> num1 >> num2;

    SimpleLinkedList<char> bigNum1, bigNum2;
    bigNum1.insertFirst(num1[0]);
    bigNum2.insertFirst(num2[0]);

    for(int i = num1.size() - 1; i > 0; i--)
        bigNum1.insertLast(num1[i]);

    for(int i = num2.size() - 1; i > 0; i--)
        bigNum2.insertLast(num2[i]);

    Node<char> *n1 = bigNum1.getHead();
    Node<char> *n2 = bigNum2.getHead();

    while(n1->link != 0 || n2->link != 0){
        if(n1->link == 0)
            bigNum1.insertLast('0');
        else if(n2->link == 0)
            bigNum2.insertLast('0');
        n1 = n1->link;
        n2 = n2->link;
    }

    SimpleLinkedList<char> ans;
    sum(bigNum1, bigNum2, ans);

    Node<char> *node = ans.getHead();
    cout << "The list is ";
    while(node != 0){
        cout << node->getData() << " ";
        node = node->link;
    }
    return 0;
}