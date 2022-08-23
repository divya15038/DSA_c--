//print all subsets of a given string
//Time Complexity: O(2^n)
//Space Complexity: O(n)
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

bool compare(string a, string b){
    if(a.length() == b.length()){
        return a < b;
    }
    return a.length() < b.length();
}

void printSubsets(char *input, char *output, int i, int j, vector<string> &v){
    //base case 
    if(input[i] == '\0'){
        output[j] = '\0';
        string temp(output);
        v.push_back(temp);
        return;
    }
    //recursive case
    //include the ith character in output array
    output[j] = input[i];
    printSubsets(input, output, i+1, j+1, v);
    //don't include the ith character in input array
    printSubsets(input, output, i+1, j, v);
}

int main() {
    char input[100], output[100];
    cin >> input;

    vector<string> v;
    printSubsets(input, output, 0, 0, v);

    //sort according to lenght and then lexicographically
    sort(v.begin(), v.end(), compare);

    for(auto x: v){
        cout << x << endl;
    }
    return 0;
}