#include <bits/stdc++.h>
using namespace std;

/*
    Lonngest Increasing Subsequence (LIS)
    ------------------------
    Given an unsorted array of integers, find the length of longest increasing subsequence.

    Example:
    Input: [10, 9, 2, 5, 3, 7, 101, 18]
    Output: 4
    Explanation: The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4.

    Approach:
        1. Brute Force: Generate all subsequences and find the longest increasing one.
           Time complexity: O(2^n)
        2. Dynamic Programming: Use a 1D array to store the length of longest increasing subsequence at each index.
           Time complexity: O(n^2)
           Space complexity: O(n)
        3. Dynamic Programming with Binary Search: Use a 1D array to store the smallest tail of all increasing 
           subsequences with different lengths.
           Time complexity: O(n log n)
           Space complexity: O(n)

    Intuition for DP1:
        1. Create a DP array of size n.
        2. Iterate over each element in the inout array, and for each element in the input array iterate back
           (using j) to the 0th index and check if the current element can be added after it, if so update
           DP[i] = DP[j] + 1.
        3. Keep track of a value with store the max value found in the DP array.

    Intuition for DP2:
        1. Create a DP array of size n, and insert the 1st element of the input array in it.
        2. Iterate over rest of the element of the input array, and for each element check if the lower
           bound of the current element is found in the DP, if ont found insert it, if found and it is not equals
           to itself then replace it with the lower bound, what this means is if the LIS can be formed using the lower bound
           of the current element then the LIS can also be formed with the current element.
        3. Keep track of a value for the max length found in the DP.
*/

int LIS(vector<int>& arr){
    int n = arr.size();
    vector<int> DP(n, 1);
    int maxLength = 1;

    for(int i=0; i<n; i++){
        for(int j=i; j>=0; j--){
            if(arr[i] > arr[j]) DP[i] = max(DP[i], DP[j] + 1);
        }
        maxLength = max(maxLength, DP[i]);
    }
    return maxLength;
}

int longestIncreasingSubsequence(vector<int>& arr){

    int n = arr.size();
    vector<int> DP;
    DP.push_back(arr[0]); // Step 1
    int maxLength = 1; // Step 3

    for(int i=1; i<n; i++){
        auto it = lower_bound(DP.begin(), DP.end(), arr[i]); // Step 2

        if(it == DP.end()) DP.push_back(arr[i]);
        else if(*it != arr[i]) *it = arr[i];

        maxLength = max(maxLength, (int)DP.size());
    }

    return maxLength;
}

int main() {

    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    cout<< longestIncreasingSubsequence(arr)<<endl; // 4
    cout<< LIS(arr)<<endl; // 4
    
    return 0;
}