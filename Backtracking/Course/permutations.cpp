//permuations: Find all the permutations for a given string of characters
//Time complexity:
//Space compleity:
#include<bits/stdc++.h>
using namespace std;

void permutations(string input, int l, int r) {
    if(l == r){
        cout << input << endl;
        return ;
    }
    for(int i=l; i<=r; i++){
        //swap the characters
        swap(input[l], input[i]);

        //call the function on the remaining part of the string
        permutations(input, l+1, r);

        //backtrack to the original array
        swap(input[l], input[i]);
    }
     
}

void permutations_(string input, string answer){
    //base case
    if(input.length() == 0){
        cout << answer << endl;
        return ;
    }
    //recursive case
    for(int i=0; i<input.length(); i++){
        char ch = input[i];
        string left_str = input.substr(0, i);
        string right_str = input.substr(i+1);
        string rest = left_str + right_str;
        permutations_(rest, answer + ch);
    }
}

int main(){
    string input;
    cin >> input;

    permutations(input, 0, input.length() - 1);
    permutations_(input, "");
    return 0;
}