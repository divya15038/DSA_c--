//vowel find: Given a string of lowercase English alphabets, return a string that contains all the vowels in serial order.
//Time Complexity: O(n)
#include<bits/stdc++.h>
using namespace std;

string vowelFind(string str){
    cout << str << endl;
    int n = str.length();
    for(int i=0; i<n; i++){
        if(!((str[i] == 'a') || (str[i] == 'e') || (str[i] == 'i') || (str[i] == 'o') || (str[i] == 'u'))){
            str.erase(str.begin() + i);
            i--;
        }
        cout << str << endl;
    }
    return str;
}

int main() {
    string s = "aeoibsddaeioudb";
    cout << vowelFind(s);
    return 0;
}