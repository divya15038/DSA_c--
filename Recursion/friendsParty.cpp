//friends' party: Given n friends, each friend could be either single or paired up. One friend can be paired up only once. Find the 
//total number of ways in which friends can be paired up or remain single.
//Time Complexity: O()
//Space complexity:  O()
#include<iostream>
using namespace std;

int numOfWays(int n) {
    //base case 
    if(n == 1 || n == 2){
        return n;
    }
    //recursive case
    return numOfWays(n-1) + (n-1)*numOfWays(n-2);
}

int main() {
    int n;
    cin >> n;

    cout << numOfWays(n);
    return 0;
}