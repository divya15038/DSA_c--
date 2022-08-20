//xoring: Given a vector of integers, all the integers except one are stored twice. Find the unique element.
//Time Complexity: O(n)
#include<iostream>
#include<vector>
using namespace std;

int findUniqueElement(vector<int> v) {
    int ans = v[0];
    for(int i=1; i<v.size(); i++){
        ans ^= v[i];
    }
    return ans;
}

int main() {
    vector<int> v = {1, 2, 3, 1, 4, 2, 3};
    cout << findUniqueElement(v);
    return 0;
}