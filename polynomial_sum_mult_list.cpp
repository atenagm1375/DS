// Ashena Gorgan Mohammadi, 610394128

/* summation and multiplication of polynomials implemented as linked lists
 */

#include <iostream>
#include "SimpleLinkedList.h"

using namespace std;

struct polynomial{
    int power;
    int factor;
};

void sum(SimpleLinkedList<polynomial>& p1, SimpleLinkedList<polynomial>& p2, SimpleLinkedList<polynomial>& ans){
    Node<polynomial> *n1 = p1.getHead();
    Node<polynomial> *n2 = p2.getHead();

    while(n1 != 0 && n2 != 0){
        if(n1 == 0){
            ans.insertLast(n2->getData());
            n2 = n2->link;
        }
        else if(n2 == 0){
            ans.insertLast(n1->getData());
            n1 = n1->link;
        }
        else{
            if(n1->getData().power > n2->getData().power){
                ans.insertLast(n1->getData());
                n1 = n1->link;
            }
            else if(n1->getData().power < n2->getData().power){
                ans.insertLast(n2->getData());
                n2 = n2->link;
            }
            else{
                polynomial p;
                p.power = n1->getData().power;
                p.factor = n1->getData().factor + n2->getData().factor;
                ans.insertLast(p);
                n1 = n1->link;
                n2 = n2->link;
            }
        }
    }
}

void mult(SimpleLinkedList<polynomial>& p1, SimpleLinkedList<polynomial>& p2, SimpleLinkedList<polynomial>& ans){
    
    Node<polynomial> *n1 = p1.getHead();
    while(n1 != 0){
        Node<polynomial> *n2 = p2.getHead();
        while(n2 != 0){
            polynomial p;
            p.power = n1->getData().power + n2->getData().power;
            p.factor = n1->getData().factor * n2->getData().factor;

            if(ans.empty()){
                ans.insertLast(p);
                n2 = n2->link;
                continue;
            }
            Node<polynomial> *temp = ans.getHead();

            while(temp != 0){
                if(p.power < temp->getData().power && (temp->link == 0 || 
                p.power > temp->link->getData().power)){
                    Node<polynomial> *n = new Node<polynomial>(p);
                    ans.insert(temp, n);
                    break;
                }
                else if(p.power == temp->getData().power){
                    polynomial val;
                    val.factor = temp->getData().factor + p.factor;
                    val.power = p.power;
                    temp->setData(val);
                    break;
                }
                else
                    temp = temp->link;
            }
            n2 = n2->link;
        }
        n1 = n1->link;
    }
}

int main(){
    SimpleLinkedList<polynomial> p1, p2;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        polynomial p;
        cin >> p.power >> p.factor;
        p1.insertLast(p);
    }
    for(int i = 0; i < m; i++){
        polynomial p;
        cin >> p.power >> p.factor;
        p2.insertLast(p);
    }

    SimpleLinkedList<polynomial> ansSum;
    sum(p1, p2, ansSum);
    Node<polynomial> *node = ansSum.getHead();
    while(node != 0){
        cout << node->getData().factor << "x^" << node->getData().power;
        node = node->link;
        if(node != 0)
            cout << " + ";
    }
    cout << endl;

    SimpleLinkedList<polynomial> ansMult;
    mult(p1, p2, ansMult);
    node = ansMult.getHead();
    while(node != 0){
        cout << node->getData().factor << "x^" << node->getData().power;
        node = node->link;
        if(node != 0)
            cout << " + ";
    }
    return 0;
}