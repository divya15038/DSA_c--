//pascal's triangle: Given a number n as input, return a vector of vector containing the first n rows of pascal's triangle.
//Time Complexity: O(n^3)
#include<iostream>
#include<vector>
using namespace std;
int factorial(int n) {
    //base case 
    if(n==0 || n==1){
        return 1;
    }
    return factorial(n-1)*n;
}

vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> res;
    int row = 0;
    while(row<n){
        vector<int> temp;
        for(int i=0; i<row+1; i++){
            int ans = factorial(row)/(factorial(i)*factorial(row-i));
            temp.push_back(ans);
        }
        res.push_back(temp);
        row++;
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> pasTri = pascalTriangle(n);
    for(int i=0; i<pasTri.size(); i++){
        for(int j=0; j<pasTri[i].size(); j++){
            cout << pasTri[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}