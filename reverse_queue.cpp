// Ashena Gorgan Mohammadi, 610394128

/* This program is to reverse the order of elements in a queue without using any
 * other data structure. The proccess is done using two queues. While one is empty,
 * the front elements of the main queue is pushed into it and all the elements of
 * the other helping queue are pushed into it.
 */

#include <iostream>
#include <queue>

using namespace std;

template<class T> queue<T> reverseQueue(queue<T>& Q1){
    queue<T> Q2, Q3;
    while(!Q1.empty()){
        if(Q2.empty()){
            Q2.push(Q1.front());
            while(!Q3.empty()){
                Q2.push(Q3.front());
                Q3.pop();
            }
        }
        else{
            Q3.push(Q1.front());     
            while(!Q2.empty()){
                Q3.push(Q2.front());
                Q2.pop();
            }
        }
        Q1.pop();
    }
    return !Q2.empty() ? Q2 : Q3;
}

int main(){
    queue<int> Q;
    for(int i = 1; i <= 10; i++)
        Q.push(i);
    Q = reverseQueue(Q);
    for(int i = 0; i < 10; i++){
        cout << Q.front() << " ";
        Q.pop();
    }
    return 0;
}