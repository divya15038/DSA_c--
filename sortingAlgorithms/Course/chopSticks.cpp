//chopsticks: We are given an array length[] that contains the length of n sticks. We need to find the number of pairs that can be formed from these sticks such that the difference between the lengths of two sticks is at most D.

//1.Brute force approach: starting from the first element, find an element such that difference of lengths between two sticks is at most D.
//If two such sticks are found, then increment count by 1. Otherwise if no such stick is found move to the next stick.
//Time Complexity: O(n^2)
#include<bits/stdc++.h>
using namespace std;

int chopSticks(vector<int> len, int D) {
    int count = 0;
    for(int i=0; i<len.size(); i++){
        for(int j=i+1; j<len.size(); j++){
            int diff = abs(len[i] - len[j]);
            if(diff <= D){
                count++;
                len.erase(len.begin() + j);
                break;
            }
        }
    }
    return count;
}

//2. Sorted approach: Firstly sort the given array. Compute the difference between consecutive lengths, if they match the criteria, increment the counter. If they don't match the criteria, there is no other possible way since the difference is the smallest possible.
//Time Complexity: O(nlogn)
int chopSticks1(vector<int> len, int D){
    int pair = 0;
    sort(len.begin(), len.end());

    for(int i=0; i<len.size()-1; i++){
        if(len[i+1] - len[i] < D){
            pair++;
            i++;
        }
    }
    return pair;
}

int main(){
    vector<int> length = {1, 3, 3, 9, 4, 5, 3, 2, 1};
    int diff; 
    cin >> diff;
    cout << chopSticks(length, diff) << endl;
    cout << chopSticks1(length, diff);
    return 0;
}