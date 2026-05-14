#include <bits/stdc++.h>
using namespace std;

/*
(1/Neetcode150)
    Problem Statement
    --------------------
    Contains Duplicate: Given an integer array nums, return true if any value appears more than once
    in the array, otherwise return false.

    Example 1:
    Input: nums = [1, 2, 3, 3]
    Output: true

    Example 2:
    Input: nums = [1, 2, 3, 4]
    Output: false

    Intuition:
    --------------------
    Approach1: For each element of the array, loop over the array again and check if any element
    in array which is coming again.
    Time complexity: O(n*n), Space complexity: O(1)

    Approach2: Store each element of the array and it's count in the map, once we get the count
    more than 1, beak out from the loop with true, else false.
    Time complexity: O(n), Space complexity: O(n) 
    Note: Instead of map we can also keep an index based array.
*/

bool haveDuplicates(vector<int>& arr){
    unordered_map<int, int> countMap;

    for(auto item: arr){
        countMap[item]++;
        if(countMap[item]>1) return true;
    }

    return false;
}

int main() {

    vector<int> arr{1, 2, 3, 4};
    
    cout<<haveDuplicates(arr);

    return 0;
}