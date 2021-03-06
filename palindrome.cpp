// Ashena Gorgan Mohammadi, 610394128

/* This program evaluates whether a string is palindrome or not using a stack.
 * The characters of the string are put in stack. In each pop phase, the character
 * is compared with the first character of the string.
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isPalindrome(string str){
    stack<char> check;
    for(int i = 0; i < str.size(); i++)
        check.push(str[i]);
    int i = 0;
    while(!check.empty()){
        if(check.top() != str[i++])
            return false;
        check.pop();
    }
    return true;
}

int main(){
    string str;
    getline(cin, str);
    bool ans = isPalindrome(str);
    ans ? cout << "YES" << endl : cout << "NO" << endl;
}