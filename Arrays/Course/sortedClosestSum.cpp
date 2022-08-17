//sorted pair sum: Find the pair from an array with the closest sum to the given value. Time Complexity: O(n)
#include<bits/stdc++.h>
using namespace std;

pair<int, int> closestSum(vector<int> arr, int x){
    int r = arr.size() -1, l = 0;
    int ans_r, ans_l, diff = INT_MAX;

    while(r>l) {
        if(abs(arr[r] + arr[l] - x) < diff){
            diff = abs(arr[r] + arr[l] - x);
            ans_r = arr[r];
            ans_l = arr[l];
        }
        if(arr[r] + arr[l] < x){
            l++;
        } else {
            r--;
        }
    }
    return make_pair(ans_l, ans_r);
}

int main() {
    vector<int> arr = {10, 22, 28, 29, 30, 40};
    int key;
    cin >> key;
    cout << closestSum(arr, key).first << "," << closestSum(arr, key).second;
    return 0;
}