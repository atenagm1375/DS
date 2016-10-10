// Ashena Gorgan Mohammadi, 610394128

/* The task is to put elements of a stack in a queue in descending order.
 * To do so, each time we have to compare top of stack with the front of 
 * queue. If it was bigger, then we have to enqueue the front element of
 * queue and dequeue it.
 */

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

template<class T> queue<T> sort(stack<T> S){
    queue<T> ans;
    while(!S.empty()){
        ans.push(S.top());
        while(ans.front() < S.top()){
            ans.push(ans.front());
            ans.pop();
        }
        S.pop();

    }
    return ans;
}

int main(){
    stack<int> S;
    for(int i = 10; i >= 1; i--)
        S.push(i);
    queue<int> ans = sort(S);
    while(!ans.empty()){
        cout << ans.front() << " ";
        ans.pop();
    }
    return 0;
}