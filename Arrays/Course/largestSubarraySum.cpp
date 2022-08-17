//Largest sub Array sum
//1.Brute force approach: Time Complexity: O(n^2)
#include<bits/stdc++.h>
#include<climits>
using namespace std;

int largestSubarraySum(int * arr, int n) {
    int largestSum = 0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int sum = 0;
            for(int k=i; k<=j; k++){
                sum += arr[k];
            }
            largestSum = max(largestSum, sum);
        }
    }
    return largestSum;
}

//2.Prefix Sum Approach: Time Complexity: O(n^2)
int largestSubarraySumPrefix(int * arr, int n) {
    int prefix[n] = {0};
    int largestSum = INT_MIN;
    prefix[0] = arr[0];
    for(int i=1; i<n; i++){
        prefix[i] = prefix[i-1] + arr[i];
    }

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int currSum = i>0 ? prefix[j] - prefix[i-1]: prefix[i];
            largestSum = max(largestSum, currSum);
        }
    }
    return largestSum;
}

//3. Kadane's Algorithm approach: Time Complexity: o(n)
int largestSubArraySumKadane(int *arr, int n) {
    int currSum = 0;
    int largestSum = 0;

    for(int i=0; i<n; i++) {
        currSum += arr[i];
        if(currSum < 0) {
            currSum = 0;
        }
        largestSum = max(largestSum, currSum);
    }
    return largestSum;
}

int maxSumSubarray2(vector<int> arr) {
    bool flag = true;
    for(auto x: arr) {
        if(x>=0){
            flag = false;
            break;
        }
    }
    
    int currSum = 0; 
    int largestSum = INT_MIN;
    int n = arr.size();
    if(!flag){
        for(int i=0; i<n; i++){
            currSum += arr[i];
            if(currSum<0) {
                currSum = 0;
            }
            largestSum = max(largestSum, currSum);
        }
    } else {
        for(int i=0; i<n; i++){
            largestSum = max(largestSum, arr[i]);
        }
    }
    
    return largestSum;
}

int main() {
    int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    vector<int> a= {-1, -2, -3, -4, -5};
    int n = sizeof(arr)/sizeof(int);

    cout << largestSubarraySum(arr, n) << " ";
    cout << largestSubarraySumPrefix(arr, n) << " ";
    cout << largestSubArraySumKadane(arr, n);
    cout << maxSumSubarray2(a);
    return 0;
}