//string compression: We are given a vector of characters(sorted) and we must compress this vector using two rules:
//If the number of ocurrences of a character are more than 1, append the character followed by the number of occurences, otherwise just append the character.
//Time Complexity: O(length of the string)
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

vector<char> stringCompression(vector<char> &str){
    str.push_back('0');
    int currLen = 1;
    int n = str.size()-1;
    for(int i=0; i<n; i++){
        if(str[i+1] != str[i]){
            string len = to_string(currLen);
            str.push_back(str[i]);
            if(currLen > 1 && currLen < 10){
                str.push_back(len[0]);
            } else if(currLen >= 10){
                int j = 0;
                while(j!=len.length()){
                    str.push_back(len[j]);
                    j++;
                }
            } 
            currLen = 1;
        } else {
            currLen++;
        }

    }
    while(n>=0){
        str.erase(str.begin());
        n--;
    }
    return str;
}

int main() {
    vector<char> exp = {'a', 'a', 'b', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'd', 'd'};
    vector<char> res =  stringCompression(exp);
    for(auto x: res){
        cout << x;
    }
    return 0;
}