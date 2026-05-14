#include <bits/stdc++.h>
using namespace std;

/*
(3/Neetcode150)
    Problem Statement
    --------------------
    Two Sum: Given an array of integers nums and an integer target, return the indices i and j such that
    nums[i] + nums[j] == target and i != j.
    You may assume that every input has exactly one pair of indices i and j that satisfy the condition.
    Return the answer with the smaller index first.

    Example 1:
    Input: 
    nums = [3,4,5,6], target = 7
    Output: [0,1]
    Explanation: nums[0] + nums[1] == 7, so we return [0, 1].

    Example 2:
    Input: nums = [4,5,6], target = 10
    Output: [0,2]

    Example 3:
    Input: nums = [5,5], target = 10
    Output: [0,1]

    Intuition:
    --------------------
    Approach1: n*n loop, to check over array element, for each element in the array to find sum of two is making
    the target.
    Time complexity: O(n*n), Space complexity: O(1)

    Approach2: Keep a map of each element of the array mapped to it's index, now loop over the array check for
    each element in the array that if it's complement was stored already in the map, if so return the pair of
    currIndex and the index of the complement found in the map. 
    Time complexity: O(n), Space complexity: O(n)

    Note: If we had a sorted array, we could have solved it by two pointers approach in O(n) time & O(1) space.
*/

pair<int, int> twoSum(vector<int>& nums, int target){
    unordered_map<int, int> indexMap;

    for(int i=0; i<nums.size(); i++){
        int complement = target-nums[i];

        if(indexMap.find(complement) != indexMap.end()){
            return {indexMap[complement], i};
        }

        indexMap[nums[i]] = i;
    }

    return {-1, -1};
}

int main() {

    vector<int> arr{3,4,5,6};
    int target = 7;

    pair<int, int> ans = twoSum(arr, target);

    cout<<"{"<<ans.first<<", "<<ans.second<<"}"<<endl;

    return 0;
}