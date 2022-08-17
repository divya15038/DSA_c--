//printing pairs: Time Complexity: O(n^2)
#include<iostream>
using namespace std;

void printPairs(int * arr, int n) {
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            cout << arr[i] << "," << arr[j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arr[] = {4, 5, 2, 3, 6};
    int n = sizeof(arr)/sizeof(n);

    printPairs(arr, n);
    return 0;
}