//Largest sub Array sum
//1.Brute force approach: Time Complexity: O(n^2)
#include<iostream>
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

int main() {
    int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
    int n = sizeof(arr)/sizeof(int);

    cout << largestSubarraySum(arr, n) << " ";
    cout << largestSubarraySumPrefix(arr, n);
    return 0;
}