/*mango tree: We are given a farm in the form a square matrix(n x n). Rahul must divide the farm into four parts by using a vertical and 
horizontal line. He will get the part of field with minimum number of trees. Thus, he must divide the field such that he gets 
the maximum possible share.
1. Brute Force Approach: Make cuts at every possible place and compute the number of trees in every quadrant, the minimum of these values 
should be stored temporarily in a variable say temp. We compare the maximum possible value with temp value and replace the max value if needed.
Time Complexity: O(n^4) will work okay till n = 100  (n^2 is needed to compute the trees in each partition and another n^2 is the no. of partitions possible.

2.Prefix Sum Approach: Create a prefix sum array for the 2d matrix such that element at [i,j] in the prefix matrix denotes the sum upto the 
indices i and j. We can easily find the share of each parition using the prefix matrix.
Time Complexity: O(n^2)*/
#include<bits/stdc++.h>
using namespace std;

int mangoTree(char arr[][10], int n){
    //create the prefix matrix
    int prefix[n][n] = {0};
    prefix[0][0] = arr[0][0] == '#'? 1:0;
    //fill in values for first column and first row
    for(int j=1; j<n; j++){
        prefix[0][j] = prefix[0][j-1] + (arr[0][j] == '#'? 1:0);
    }
    for(int i=1; i<n; i++){
        prefix[i][0] = prefix[i-1][0] + (arr[i][0] == '#'? 1:0);
    }
    //fill in prefix sum values for rest of the matrix
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + (arr[i][j] == '#'? 1:0);
        }
    }
    //Find the share of each partition
    int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
    int maxShare = 0, currShare = 0;

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1; j++){
            s1 += prefix[i][j];
            s2 += prefix[i][n-1] - s1;
            s3 += prefix[n-1][j] - s1;
            s4 += prefix[n-1][n-1] - s1 - s2 - s3; 
            currShare = min(s1,min(s2, min(s3, s4)));
            maxShare = max(maxShare, currShare);
            s1 = 0, s2 = 0, s3 = 0, s4 =0;
        }
    }

    return maxShare;
}

int main() {
    int n;
    cin >> n; 
     
    char arr[][10] = {{'.', '#', '#', '.', '.', '.'}, 
                     {'#', '.', '.', '#', '#', '.'},
                     {'.', '#', '.', '.', '.', '.'},
                     {'.', '#', '#', '.', '.', '#'}, 
                     {'#', '.', '.', '#', '#', '.'},
                     {'.', '#', '.', '.', '.', '.'}};
    
    cout << mangoTree(arr, n);
    return 0;
}