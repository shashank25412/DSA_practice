#include <bits/stdc++.h>
using namespace std;

/*
    Subset Sum Problem
    ------------------------
    Given a set of non-negative integers and a value sum,
    determine if there is a subset of the given set with sum equal to given sum.

    Example:
    Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
    Output: True
    Explanation: There is a subset (4, 5) with sum 9.

    Approach:
        1. Brute Force: Generate all subsets and check if any of them sums to the given value.
           Time complexity: O(2^n)
        2. Dynamic Programming: Use a 2D boolean array to store results of subproblems.
           Time complexity: O(n*sum)
           Space complexity: O(n*sum)

    Intuition for DP:
        1. Matrix of size n * sum+1, where n is the number of elements in the set.
        2. 0 sum can always be achieved with an empty set, so first column is true.
        3. Fill the corresponding cell, if arr[0] == j, means value at row 0 equals to j
        4. For each dp[i][j], we can check if that the sum (j) is already made without 
          considering the current element arr[i], if not, then we can check if
          we can achieve the sum by adding the current element.
*/

bool subsetSum(vector<int>& arr, int sum){
    int m = arr.size();
    vector<vector<bool>> DP(m, vector<bool>(sum+1, false)); // Step 1

    for(int i=0; i<m; i++) DP[i][0] = true; // Step 2
    for(int j=1; j<=sum; j++) DP[0][j] = (arr[0] == j); // Step 3

    for(int i=1; i<m; i++){
        for(int j=1; j<=sum; j++){
            DP[i][j] = DP[i-1][j] || (j>= arr[i] && DP[i-1][j-arr[i]]); // Step 4
        }
    }

    return DP[m-1][sum];
}

int main() {

    vector<int> arr = {3, 34, 4, 12, 5, 2};
    cout<< subsetSum(arr, 34)<<endl; // True

    return 0;
}