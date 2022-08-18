//remove duplicates: Remove duplicate characters from given string.
//Time complexity: O(nlogn)
#include<iostream>
#include<algorithm>
using namespace std;

string removeDuplicates(string str) {
    sort(str.begin(), str.end());
    int n = str.length();
    
    int i = 0;
    while(n>0){
        if(str[i] == str[i+1]){
            str.erase(i+1, 1);
        } else {
            i++;
        }
        n--;
    }

    return str;
}

int main() {
    string s1 = "geeksforgeek";
    cout << removeDuplicates(s1);
    return 0;
}