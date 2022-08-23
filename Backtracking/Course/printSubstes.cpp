//print all subsets of a given string
//Time Complexity: O(2^n)
//Space Complexity: O(n)
#include<bits/stdc++.h>
using namespace std;

void printSubsets(char *input, char *output, int i, int j){
    //base case 
    if(input[i] == '\0'){
        output[j] = '\0';
        cout << output << endl;
        return;
    }
    //recursive case
    //include the ith character in output array
    output[j] = input[i];
    printSubsets(input, output, i+1, j+1);
    //don't include the ith character in input array
    printSubsets(input, output, i+1, j);
}

int main() {
    char input[100], output[100];
    cin >> input;

    
    printSubsets(input, output, 0, 0);
    return 0;
}