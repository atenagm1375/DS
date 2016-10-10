// Ashena Gorgan Mohammadi, 610394128

/* This program is to put elements of a queue in a stack with descending order without
 * using any other data structure. To do so, while front element of the queue is bigger
 * top element of the stack, we enqueue the elements of stack in the queue.
 */

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

template<class T> stack<T> sortQueue(queue<T> Q){
    stack<T> ans;
    //ans.push(Q.front());
    //Q.pop();
    while(!Q.empty()){
        ans.push(Q.front());
        Q.pop();
        while(!ans.empty() && Q.front() > ans.top()){
            Q.push(ans.top());
            ans.pop();
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