#include <bits/stdc++.h>
using namespace std;

/*
(9/Neetcode150)
    Problem Statement
    --------------------
    Longest Consecutive Sequence: Given an array of integers nums, return the length of the longest consecutive sequence of elements that can be formed.
    (A consecutive sequence is a sequence of elements in which each element is exactly 1 greater than the previous element.
    The elements do not have to be consecutive in the original array.)

    You must write an algorithm that runs in O(n) time.

    Example 1:
    Input: nums = [2,20,4,10,3,4,5]
    Output: 4
    Explanation: The longest consecutive sequence is [2, 3, 4, 5].

    Example 2:
    Input: nums = [0,3,2,5,4,6,1,1]
    Output: 7

    Constraints:
    - 0 <= nums.length <= 1000
    - -10^9 <= nums[i] <= 10^9

    Intuition:
    --------------------
    Aproach1: In the array we assume, each element as the starting point and checks for it's consecutive values, (also convert the array
    into a set for O(1) lookup). Keep track of answer/result variable, update it if found a maximum till now.
    Time complexity: O(n*n), Space complexity: O(n)

    Aproach2: Sort the array, start moving in the array from the 1st index, while moving in the array check if previous element is same
    as of the current one, consecutive value of the current one or something else, if is same as of the current just move ahead in the array
    and check same thing, if it is a consucutive of the current, we increase the length count by 1, if it is a far lying number, this could be
    possibly a new range starting from the current, so reset the length to deafult and continue the same. And each step we check for the max
    value found so far for our answer.
    Time complexity: O(n*logn), Space complexity: O(1)

    Aproach3: Similar to aproach1, instead of assuming every element of the array as the starting point, we do a check the if the current
    number is a consucutive number for any element in array, if not then only we assume it as the starting point. And then check for it's
    consecutive values. Again here we will keep track of answer/result variable,to find maximum till now.
    Time complexity: Amortized O(n), Space complexity: O(n)

    Aproach4: We keep one unordered_map, let's say aMap, in this map for each element (arr[i]) in array as key, we store value as 
    aMap[arr[i-1]] + 1 + aMap[arr[i]+1], so basically we are considering each element of the array as bridge that connects the consecutive
    numbers found in right of it and same for it's left. After updating the map for the current element we again update it's boudaries,
    means the starting point found at the previous value of the current (i.e. left boundry) and the similarly we uodate the right boundry.
    Time complexity: O(n), Space complexity: O(n)
*/

int consecutives1(vector<int>& nums){
    int maxLength = 0;

    unordered_set<int> elements(nums.begin(), nums.end());
    for(int num: nums){
        int streak = 0, currentElement = num;
        while(elements.find(currentElement) != elements.end()){
            streak++;
            currentElement++;
        }
        maxLength = max(maxLength, streak);
    }

    return maxLength;
}

int consecutives2(vector<int>& nums){
    if(nums.empty()) return 0;

    int maxLength = 1;
    int streak = 1;

    sort(nums.begin(), nums.end());
    for(int i=1; i<nums.size(); i++){
        if(nums[i] == nums[i-1]+1){
            streak++;
        }
        else if(nums[i] != nums[i-1]){
            streak = 1;
        }

        maxLength = max(maxLength, streak);
    }

    return maxLength;
}

int consecutives3(vector<int>& nums){
    int maxLength = 0;

    unordered_set<int> elements(nums.begin(), nums.end());
    for(int num: nums){
        if(elements.find(num-1) == elements.end()){ // To check if it is the starting point of the consecutive sequence
            int streak = 0, currentElement = num;

            while(elements.find(currentElement) != elements.end()){
                streak++;
                currentElement++;
            }

            maxLength = max(maxLength, streak);
        }
    }

    return maxLength;
}

int consecutives4(vector<int>& nums){
    int maxLength = 0;

    unordered_map<int, int> aMap;
    for(int num: nums){
        if(!aMap[num]){
            aMap[num] = aMap[num-1] + 1 + aMap[num+1]; // consecutives for the current num
            aMap[num - aMap[num-1]] = aMap[num]; // updating the left side boundry
            aMap[num + aMap[num+1]] = aMap[num]; // updating the right side boundry

            maxLength = max(maxLength, aMap[num]);
        }
    }

    return maxLength;
}

int main(){

    vector<int> nums = {2,20,4,10,3,4,5};

    // int res = consecutives1(nums);
    // int res = consecutives2(nums);
    // int res = consecutives3(nums);
    int res = consecutives4(nums);

    cout<<"The longest consecutive sequence for the given array is: "<<res<<endl;

    return 0;
}