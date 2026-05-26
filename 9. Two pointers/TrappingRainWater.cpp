#include <bits/stdc++.h>
using namespace std;

/*
(14/Neetcode150)
    Problem Statement
    --------------------
    Trapping Rain Water: You are given an array of non-negative integers height which represent an elevation map. 
    Each value height[i] represents the height of a bar, which has a width of 1.
    Return the maximum area of water that can be trapped between the bars.

    Example 1:
    Input: height = [0,2,0,3,1,0,1,3,2,1]
    Output: 9

    Constraints:
    - 1 <= height.length <= 1000
    - 0 <= height[i] <= 1000

    Intuition
    --------------------
    Aproach1:  Take 2 pointers, 1 from left another from right, at whichever point we get less height, we start moving
    inwards from there, until we found something bigger than that, otherwise we keep adding the current pointers height
    minus the height of the bar found in the way. We repeat this till left pointer crosses the right one.

*/

int rainWaterStored(vector<int>& height){
    int res = 0;
    int left = 0, right = height.size()-1;

    while(left < right){
        int minn = min(height[left], height[right]);
        if(minn == height[left]){
            left++;
            while(left<right && height[left]<minn){
                res += minn - height[left];
                left++;
            }
        }
        else{
            right--;
            while(left<right && height[right]<minn){
                res += minn - height[right];
                right--;
            }
        }
    }

    return res;
}

int main() {
    vector<int> height = {0,2,0,3,1,0,1,3,2,1};

    cout<<rainWaterStored(height)<<endl;

    return 0;
}