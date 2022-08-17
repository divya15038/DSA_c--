//Array reverse: Time complexity: O(n/2)
#include<iostream>
using namespace std;

void arrayReverse(int * arr, int n) {
    int start = 0;
    int end = n-1, temp;
    while(start < end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main() {
    int arr[] = {12, 23, 24, 25};
    int n = sizeof(arr)/sizeof(n);

    arrayReverse(arr, n);
    for(auto x: arr) {
        cout << x << " ";
    }
    return 0;
}