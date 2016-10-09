// Ashena Gorgan Mohammadi, 610394128

/* It is possible to implement a stack using a queue. To do so, for push method,
 * it is needed to put the value being pushed in the empty queue and copy the
 * the other one into it.
 */

#include <iostream>
#include <queue>

using namespace std;

template<class T> class stack{

    public:
        stack() {};

        void push(T& val){
            if(Q1.empty())
                enqueue(Q1, Q2, val);
            else
                enqueue(Q2, Q1, val);
        }

        void pop(){
            !Q1.empty() ? Q1.pop() : Q2.pop();
        }

        T top(){
            return !Q1.empty() ? Q1.front() : Q2.front();
        }

        bool empty(){
            return Q1.empty() && Q2.empty();
        }

    private:
        queue<T> Q1;
        queue<T> Q2;

        void enqueue(queue<T>& q1, queue<T>& q2, T& val){
            q1.push(val);
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }
};

int main(){
    stack<int> S;
    for(int i = 1; i <= 10; i++)
        S.push(i);
    for(int i = 1; i <= 5; i++){
        cout << S.top() << " ";
        S.pop();
    }
    cout << endl;
    for(int i = 1; i <= 5; i++)
        S.push(i);
    while(!S.empty()){
        cout << S.top() << " ";
        S.pop();
    }
    return 0;
}