//unique subsets:find the unique subsets for a given array of integers, keep track of duplicates and sort the answer in acscending order.
//Time complexity:
//Space complexity:
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

void helperUniqueSubsets(vector<int> nums, vector<int> output, int i,vector<vector<int>> &res) {
    //base case
    if(i == nums.size()) {
        if(output.size() == 0){
            output.push_back(-1);
        }
        res.push_back(output);
        return ;
    }
    //recursive case
    output.push_back(nums[i]);
    helperUniqueSubsets(nums, output, i+1, res);
    
    output.pop_back();
    helperUniqueSubsets(nums, output, i+1, res);
    return ;
}

vector<vector<int>> uniqueSubsets(vector<int> nums){
    vector<int> output;
    vector<vector<int>> res;
    helperUniqueSubsets(nums, output, 0, res);
    sort(res.begin(), res.end());
    res[0].pop_back();
    res.erase(unique(res.begin(), res.end()), res.end());
    return res;
}

int main() {
    vector<int> nums = {0, 1, 4, 4};
    vector<vector<int>> res = uniqueSubsets(nums);

    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}