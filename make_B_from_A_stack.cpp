// Ashena Gorgan Mohammadi, 610394128

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