#include <bits/stdc++.h>
using namespace std;

/*
(11/Neetcode150)
    Problem Statement
    --------------------
    Two Sum II: Given an array of integers numbers that is sorted in non-decreasing order.
    Return the indices (1-indexed) of two numbers, [index1, index2], such that they add up to a given target number
    target and index1 < index2.
    Note that index1 and index2 cannot be equal, therefore you may not use the same element twice.
    There will always be exactly one valid solution.
    Your solution must use O(1) additional space.

    Example 1:
    Input: numbers = [1,2,3,4], target = 3
    Output: [1,2]
    Explanation:
    The sum of 1 and 2 is 3. Since we are assuming a 1-indexed array, index1 = 1, index2 = 2. We return [1, 2].

    Constraints:
    - 2 <= numbers.length <= 1000
    - -1000 <= numbers[i] <= 1000
    - -1000 <= target <= 1000

    Intuition:
    --------------------
    Aproach: Keep two pointers, 1 for left traversal in the array, another for the right traversal in the array.
    If the sum of the number at the left index and the number at the right index is greater than the target, increment
    the left index by 1, else decrement the right index by one, as in the non-decreasing sorted array, a bigger number
    will be found by moving toward right and a smaller number will be found by moving towards left.
    Time complexity: O(n), Space complexity: O(1)
*/

pair<int, int> twoSum(vector<int>& nums, int target){
    int left = 0, right = nums.size()-1;

    while(left<right){
        if(nums[left]+nums[right] == target){
            return {left, right};
        }
        else if(nums[left]+nums[right] > target){
            right--;
        }
        else{
            left++;
        }
    }

    return {-1, -1};
}

int main() {
    vector<int> numbers = {1,2,3,4};
    int target = 3;

    pair<int, int> res = twoSum(numbers, target);
    cout<<"{"<<res.first<<", "<<res.second<<"}"<<endl;

    return 0;
}