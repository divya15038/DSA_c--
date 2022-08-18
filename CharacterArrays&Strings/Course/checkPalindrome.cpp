//check palindrome: Determine whether the given string made up of alphabets is a plaindrome or not. Time Complexity: O(n). Here,we consider case senstivity.
#include<iostream>
using namespace std;

bool checkPalindrome(string str) {
    int n = str.length();
    for(int i=0; i<n; i++){
        if(str[i] != str[n-i-1]){
            return false;
        }
    }
    return true;
}   

int main() {
    string test = "diyjid";
    if(checkPalindrome(test)){
        cout << "The given string is a palindrome." << endl;
    } else {
        cout << "The given string is not a palindrome." << endl;
    }
    return 0;
}