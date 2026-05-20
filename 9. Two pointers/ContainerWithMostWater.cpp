#include <bits/stdc++.h>
using namespace std;

/*
(13/Neetcode150)
    Problem Statement
    --------------------
    Container With Most Water: You are given an integer array heights where heights[i] represents the height of the ith bar.

    You may choose any two bars to form a container. Return the maximum amount of water a container can store.

    Example 1:
    Input: height = [1,7,2,5,4,7,3,6]
    Output: 36

    Example 2:
    Input: height = [2,2,2]
    Output: 4

    Constraints:
    - 2 <= height.length <= 1000
    - 0 <= height[i] <= 1000

    Intuition:
    --------------------
    Aproach1: A n*n loop solution to check for the area created by all the i, j pair indices and maximize the answer.
    Time complexity: O(n*n), Space complexity: O(1)

    Aproach2: Keep a two pointers, 1 at left side another at right side which moves inward in the array, calculate the area within
    these 2 pointers, now to maximize the answer move 1 of the index inward which is having less height, the intuition behind moving
    the less heighted index is greater heighted index can hold water upto more capacity.
    Time complexity: O(n), Space complexity: O(1)
*/

int maxArea(vector<int>& height){
    int left = 0, right = height.size()-1;
    int res = 0;

    while (left<right){
        int area = (right-left) * min(height[left], height[right]);
        res = max(res, area);

        if(height[left] < height[right]) left++;
        else right--;
    }
    
    return res;
}

int main() {

    vector<int> height = {1,7,2,5,4,7,3,6};

    cout<<maxArea(height)<<endl;

    return 0;
}