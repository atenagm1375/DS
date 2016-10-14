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
    	int min = S.top();
        S.pop();
        while(!S.empty() && S.top() >= min){
            int aid = S.top();
            S.pop();
        	while(ans.front() > aid){
                ans.push(ans.front());
                ans.pop();
            }
            ans.push(aid);
        	while(aid >= ans.front()){
        		ans.push(ans.front());
        		ans.pop();
        	}
        }
        ans.push(min);
    }
    return ans;
}

int main(){
    stack<int> S;
    S.push(-1);
    S.push(2);
    S.push(-3);
    S.push(-1);
    S.push(1);
    S.push(5);
    queue<int> ans = sort(S);
    while(!ans.empty()){
        cout << ans.front() << " ";
        ans.pop();
    }
    return 0;
}
