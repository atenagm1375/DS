// Ashena Gorgan Mohammadi, 610394128

#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <cmath>

using namespace std;

void evaluate(stack<int> *operands, stack<char> *operators){
    int a = operands->top();
    operands->pop();
    int b = operands->top();
    operands->pop();
    if(operators->top() == '+')
        operands->push(b + a);
    else if(operators->top() == '-')
        operands->push(b - a);
    else if(operators->top() == '*')
        operands->push(b * a);
    else if(operators->top() == '/')
        operands->push(b / a);
    else if(operators->top() == '^')
        operands->push(pow(b, a));
    operators->pop();
    //cout << operands->top() << endl;
}

bool hasHigherPrecedence(char a, char b){
    if(a == '(')
        return false;
    else if(b == '(')
        return true;
    else if(a == '^' && b != '^')
        return true;
    else if((a == '*' || a == '/') && (b == '-' || b == '+'))
        return true;
    return false;
}

int evaluate_expresion(string exp){
    int ans = 0;
    stack<char> operators;
    stack<int> operands;
    for(int i = 0; i < exp.size(); i++){
        string str = "";
        while(exp[i] >= '0' && exp[i] <= '9')
            str += exp[i++];
        if(str != "")
            operands.push(atoi(str.c_str()));
        if(operators.empty())
            operators.push(exp[i]);
        else if(exp[i] == '(')
            operators.push(exp[i]);
        else if(exp[i] == ')'){
            while(operators.top() != '(')
                evaluate(&operands, &operators);
            operators.pop();
        }
        else if(hasHigherPrecedence(exp[i], operators.top()))
            operators.push(exp[i]);
        else{
            while(!operators.empty() && !hasHigherPrecedence(exp[i], operators.top()))
                evaluate(&operands, &operators);
            operators.push(exp[i]);
        }
        //cout << "operand: " << operands.top() << endl;
    }
    return operands.top();
}

int main(){
    string exp;
    getline(cin, exp, '=');
    cout << evaluate_expresion(exp) << endl;
    return 0;
}