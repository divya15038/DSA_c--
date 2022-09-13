#include<bits/stdc++.h>
using namespace std;

bool duplicateParentheses(string str){
    stack<char> s;
    
    for(char ch: str){
        if(ch == ')'){
            char top = s.top();
            int elementsInside = 0;
            while(s.top() != '('){
                elementsInside++;
                top = s.top();
                s.pop();
            }
            s.pop();
            if(elementsInside<1){
                return true;
            }
        }
        else{
            s.push(ch);
        }
    }
    return false;
}

int main(){
    string str = "((a+b)+((c+d)))";
    cout << duplicateParentheses(str);
    return 0;
}