//check permutation: Check if two strings are permuations of each other.
//Time Complexity: O(nlogn)
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

bool checkPermutation(string str1, string str2) {
    if(str1.length() != str2.length()){
        return false;
    }
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    for(int i=0; i<str1.length(); i++){
        if(str1[i] != str2[i]){
            return false;
        }
    }
    return true;
}

int main() {
    string s1 = "test", s2 = "sest";
    if(checkPermutation(s1, s2)){
        cout << "Second string is a permutation of first string." << endl;
    } else {
        cout << "Second string is not a permutation of first string." << endl;
    }
    return 0;
}