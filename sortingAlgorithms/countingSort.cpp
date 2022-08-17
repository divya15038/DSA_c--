//counting sort: Takes into consideration the frquency of elements. The range of elements in array shouldn't be large. Time complexity: O(n + range)
#include<bits/stdc++.h>
using namespace std;

void countingSort(int * arr, int n) {
    //find the size of freq array
    int largest = INT_MIN;
    for(int i=0; i<n; i++) {
        largest = max(largest, arr[i]);
    }

    //create the frequency vector
    vector<int> freq(largest+1, 0);

    //fill in the freq array
    for(int i=0; i<n; i++){
        freq[arr[i]]++;
    }

    //insert values into the original array in sorted order
    int j = 0; //iterating through the freq array
    for(int i=0; i<=largest; i++){
        while(freq[i]>0){
            arr[j] = i;
            freq[i]--;
            j++;
        }
    }

}

int main() {
    int arr[] = {23, 5, 13, 23, 22};
    int n = sizeof(arr)/sizeof(int);

    countingSort(arr, n);
    for(auto x: arr){
        cout << x << " ";
    }
    return 0;
}