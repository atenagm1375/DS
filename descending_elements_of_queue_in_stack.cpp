// Ashena Gorgan Mohammadi, 610394128

/* This program is to put elements of a queue in a stack with descending order without
 * using any other data structure. To do so, two stacks were declared. Each time, The
 * front element of the queue is compared with the top of the stack of answer. If it
 * was less than that, we put the elements of answer stack into the aid stack until 
 * the top becomes less than or equal to the front element of the queue. Put the element
 * in place then
 */

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

template<class T> stack<T> sortQueue(queue<T> Q){
    stack<T> ans;
    stack<T> s;
    ans.push(Q.front());
    Q.pop();
    while(!Q.empty()){
        while(!ans.empty() && Q.front() < ans.top()){
            s.push(ans.top());
            ans.pop();
        }
        ans.push(Q.front());
        Q.pop();
        while(!s.empty()){
            ans.push(s.top());
            s.pop();
        }
    }
    return ans;
}

int main(){
    queue<int> Q;
    for(int i = 1; i <= 10; i++)
        Q.push(i);
    stack<int> ans = sortQueue(Q);
    while(!ans.empty()){
        cout << ans.top() << " ";
        ans.pop();
    }
    return 0;
}