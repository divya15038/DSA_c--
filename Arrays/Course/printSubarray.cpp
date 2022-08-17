//print all subarrays: number of subarrys possible: (n-1)! Time Complexity: O(n^2)
#include<iostream>
using namespace std;

void printSubArrays(int * arr, int n) {
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++) {
            for(int k=i; k<=j; k++){
                cout << arr[k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    int arr[] = {1, 3, 4, 6, 8, 34};
    int n = sizeof(arr)/sizeof(int);

    printSubArrays(arr, n);
    return 0;
}