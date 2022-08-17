//bubble sort: take larger element to the end by repeatedly swapping adjacent elements. Time Complexity: O(n^2)
#include<iostream>
using namespace std;

void bubbleSort(int *arr, int n) {
    for(int i=0; i<=n-1; i++){
        for(int j=0; j<=n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
int main() {
    int arr[] = {12, 65, 3, 67, 89, 45, 2};
    int n = sizeof(arr)/sizeof(int);

    bubbleSort(arr, n);
    for(auto x: arr){
        cout << x << " ";
    }
    return 0;
}