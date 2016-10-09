// Ashena Gorgan Mohammadi, 610394128

/* Using a stack, we want to understand if the second string can be made from
 * the first one or not. Since the letters are distinct, in each stage, by checking
 * equality of the top of the stack and the pointer of the second string, we can 
 * realise whether we can make it or not*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isPossible(string A, string B){
    stack<char> check;
    int j = 0;
    for(int i = 0; i < A.size(); i++){
        check.push(A[i]);
        while(!check.empty() && check.top() == B[j]){
            check.pop();
            j++;
        }
    }
    return j == B.size();
}

int main(){
    string A, B;
    cin >> A >> B;
    isPossible(A, B) ? cout << "YES" << endl : cout << "NO" << endl;
    return 0;
}