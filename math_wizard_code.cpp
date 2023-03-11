#include<bits/stdc++.h>
using namespace std;

//function to evaluate postfix expression
double evaluatePostfix(string expression){
    stack <double> stack;
    for(int i=0;i<expression.length();i++){
        if(expression[i]>='0' && expression[i]<='9'){
           stack.push(expression[i]-'0');
        }
        else{
            double operand1 = stack.top();
            stack.pop();
            double operand2 = stack.top();
            stack.pop();
            switch (expression[i])
            {
            case '+':
                stack.push(operand2+operand1);
                break;
            case '-':
                stack.push(operand2-operand1);
                break;
            case '*':
                stack.push(operand2*operand1);
                break;
            case '/':
                stack.push(operand2/operand1);
                break;
            default:
                break;
            }
        }
    }
    return stack.top();
}

//function to calcultae the precedence of the operators
int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

//to convert string symbol to equivalent symbol string
string getSymbol(string word) {

    if(word.length() == 1) return word;
    if(word == "zero") return "0";
    if(word == "one") return "1";
    if(word == "two") return "2";
    if(word == "three") return "3";
    if(word == "four") return "4";
    if(word == "five") return "5";
    if(word == "six") return "6";
    if(word == "seven") return "7";
    if(word == "eight") return "8";
    if(word == "nine") return "9";
    if(word == "plus") return "+";
    if(word == "subtract") return "-";
    if(word == "multiply") return "*";
    if(word == "divide") return "/";
    if(word == "equals") return "=";
    return "";
}

//function to convert infix expression to postfix 
string infixToPostfix(string expression)
{
 
    stack<char> stack;
    string result;
 
    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
            || (c >= '0' && c <= '9'))
            result += c;
        else if (c == '(')
            stack.push('(');
        else if (c == ')') {
            while (stack.top() != '(') {
                result += stack.top();
                stack.pop();
            }
            stack.pop();
        }
        else {
            while (!stack.empty()
                   && precedence(expression[i]) <= precedence(stack.top())) {
                result += stack.top();
                stack.pop();
            }
            stack.push(c);
        }
    }
    while (!stack.empty()) {
        result += stack.top();
        stack.pop();
    }
 
    return result;
}

int main() {
        freopen("TMW_small.txt", "r", stdin);
        freopen("output_TMW_small.txt", "w", stdout);
    int t;
    cin >> t;
    int case_count = 1;
    while(t--) {
        string str;
        string equation = "";
        while(1) {
            cin >> str;
            if(str == "equals" || str == "=") break;
             string temp = getSymbol(str);
             equation += temp;
        }
        string word;
        cin >> word;
        double ans = stod(word);
        equation = infixToPostfix(equation);
        double res = evaluatePostfix(equation);
        cout << "Case #" << case_count << ": ";
        if(ans == res) cout << "true\n";
        else cout << "false\n";
        case_count++;
    }
}
