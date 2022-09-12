#include<iostream>
#include "stackLL.h"
using namespace std;

int main(){
    Stack<char> ch;
    ch.push('h');
    ch.push('e');
    ch.push('l');
    ch.push('l');
    ch.push('o');
    ch.push('w');
    ch.push('o');
    ch.push('r');
    ch.push('l');
    ch.push('d');

    while(!ch.empty()){
        cout << ch.top();
        ch.pop();
    }
    return 0;
}