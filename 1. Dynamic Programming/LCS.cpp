#include <bits/stdc++.h>
using namespace std;

/*
    Longest Common Subsequence (LCS)
    ------------------------
    Given two strings, find the length of the longest subsequence present in both of them.
    A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.

    Example:
    Input: "AGGTAB", "GXTXAYB"
    Output: 4
    Explanation: The longest common subsequence is "GTAB" which has length 4.

    Approach:
        1. Brute Force: Generate all subsequences of both strings and find the longest common one.
           Time complexity: O(2^m * 2^n)
        2. Dynamic Programming: Use a 2D array to store lengths of longest common subsequence of substrings.
           Time complexity: O(m*n)
           Space complexity: O(m*n)

    Intuition for DP:
        1. Create a matrix of size (m+1) * (n+1).
        2. If both the strings are equal and 1 character long then DP[1][1] = 1, else 0.
        3. To fill DP[i][j], check if the current characters of both strings match, if match then add 1 to the
           LCS length found at DP[i-1][j-1].
        4. If doesn't match, then we take LCS found so far, which is calculated by taking the maximum of the 
           LCS found by excluding the current character of either string.
*/

int longestCommonSubsequence(string s1, string s2){

    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> DP(m+1, vector<int>(n+1, 0)); // Step 1

    for(int i=0; i<=m; i++) DP[i][0] = 0; // Step 2
    for(int j=0; j<=n; j++) DP[0][j] = 0; // Step 2

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            DP[i][j] = (s1[i-1] == s2[j-1])? DP[i-1][j-1] +1 : max(DP[i-1][j], DP[i][j-1]); // Step 3 and 4)
        }
    }
    return DP[m][n];
}

int main() {
    
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    cout<< longestCommonSubsequence(s1, s2)<<endl;

    return 0;
}