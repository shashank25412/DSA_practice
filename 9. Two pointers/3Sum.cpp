#include <bits/stdc++.h>
using namespace std;

/*
(12/Neetcode150)
    Problem Statement
    --------------------
    3Sum: Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] where nums[i] + nums[j] + nums[k] == 0,
    and the indices i, j and k are all distinct.
    The output should not contain any duplicate triplets. You may return the output and the triplets in any order.

    Example 1:
    Input: nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]
    Explanation:
    nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
    nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
    nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
    The distinct triplets are [-1,0,1] and [-1,-1,2].

    Example 2:
    Input: nums = [0,1,1]
    Output: []
    Explanation: The only possible triplet does not sum up to 0.

    Example 3:
    Input: nums = [0,0,0]
    Output: [[0,0,0]]
    Explanation: The only possible triplet sums up to 0.

    Constraints:
    - 3 <= nums.length <= 1000
    - -10^5 <= nums[i] <= 10^5

    Intuition:
    --------------------
    Aproach1: A 3 loop solution, where for each element in the array we run n*n loop again to find the 2nd and 3rd number.
    Time complexity: O(n*n*n), Space complexity: O(1)

    Aproach2: First we'll sort the array and then for each index i in the array, we'll keep 2 pointers j and k one at right,
    another at left which goes in opposite direction and try find a sum which is equal to the -(arr[i]).
    Time complexity: O(n*n), Space complexity: O(1)
*/

vector<vector<int>> threeSum(vector<int>& nums){
    int n = nums.size();
    int i = 0, j = 1, k = n-1;
    vector<vector<int>> res;

    sort(nums.begin(), nums.end());

    for(i=0; i<n-2; i++){
        j = i+1;
        k = n-1;

        if(i>0 && nums[i]==nums[i-1]) continue;

        int target = -(nums[i]);

        while(j<k){
            if(nums[j]+nums[k] < target){
                j++;
            }
            else if(nums[j]+nums[k] > target){
                k--;
            }
            else{
                res.push_back((vector<int>){nums[i], nums[j], nums[k]});

                while(j<k && nums[j]==nums[j+1]) j++;

                j++;
                k--;
            }
        }
    }

    return res;
}

int main(){

    // vector<int> nums = {-1,0,1,2,-1,-4};
    vector<int> nums = {0, 0, 0, 0};

    vector<vector<int>> res = threeSum(nums);

    cout<<"[";
    for(auto i: res){
        cout<<"[";
        for(auto j: i){
            cout<<j<<", ";
        }
        cout<<"], ";
    }
    cout<<"]"<<endl;

    return 0;
}