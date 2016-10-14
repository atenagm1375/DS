// Ashena Gorgan Mohammadi, 610394128

/* The task is to implement a stack with a simple linked list. push is the same
 * as insertFirst and pop is the same as removeFirst.
 */

#include <iostream>
#include "SimpleLinkedList.h"

using namespace std;

template<class T>class stack{

    public:

        stack(){ }

        void push(T val){
            myStack.insertFirst(val);
        }

        void pop(){
            if(!empty())
                myStack.removeFirst();
            else
                cout << "No elements to be poped" << endl;
        }

        T top(){
            return myStack.getHead()->getData();
        }

        bool empty(){
            return myStack.empty();
        }

    private:

        SimpleLinkedList<T> myStack;
};

int main(){
    stack<int> S;
    for(int i = 0; i < 5; i++)
        S.push(i + 1);
    cout << S.top() << endl;
    S.pop();
    cout << S.top() << endl;
    for(int i = 10; i <15; i++)
        S.push(i);
    while(!S.empty()){
        cout << S.top() << endl;
        S.pop();
    }
    S.pop();
    return 0;
}