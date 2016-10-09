// Ashena Gorgan Mohammadi, 610394128

/* This program evaluates whether the number of 0s and 1s in a binary string
 * are equal or not using a stack. The algorithm works as follows:
 * each time, if stack is empty, the character is pushed into the stack; otherwise, if 
 * the pointed character is different from the top of the stack, we pop an element from
 * the stack; elsewhere, we push the element into the stack. If stack is empty at the end,
 * then the number of 0s and 1s are equal
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int status(string str){
    stack<char> binary;
    for(int i = 0; i < str.size(); i++){
        if(binary.empty() || binary.top() == str[i])
            binary.push(str[i]);
        else
            binary.pop();
    }
    if(binary.empty())
        return 0;
    return (int)binary.top();
}

int main(){
    string binaryStr;
    cin >> binaryStr;
    int ans = status(binaryStr);
    if(ans == 0)
        cout << "Equal" << endl;
    else if(ans == (int)'1')
        cout << "1s are more than 0s" << endl;
    else
        cout << "0s are more than 1s" << endl;
}