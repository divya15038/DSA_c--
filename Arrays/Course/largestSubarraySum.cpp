//Largest sub Array sum
//1.Brute force approach: Time Complexity: O(n^2)
#include<iostream>
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

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(arr)/sizeof(int);

    cout << largestSubarraySum(arr, n);
    return 0;
}