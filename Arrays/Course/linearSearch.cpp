//Linear Search: Time Complexity: O(n)
#include<iostream>
using namespace std;

int linearSearch (int * arr, int n, int key) {
    for(int i=0; i<n; i++){
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}
int main() {
    int a[] = {23, 43, 12, 7, 45, 34};
    int n = sizeof(a)/sizeof(int);

    int key;
    cin >> key;

    int idx = linearSearch(a, n, key);
    if(idx == -1) {
        cout << key << " not found in the given array";
    } else {
        cout << key << " is stored at index " << idx;
    }
    return 0;
}