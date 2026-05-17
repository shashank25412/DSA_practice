#include <bits/stdc++.h>
using namespace std;

/*
(7/Neetcode150)
    Problem Statement
    --------------------
    Products of Array Except Self: Given an integer array nums, return an array output where output[i] is the product of
    all the elements of nums except nums[i].

    Each product is guaranteed to fit in a 32-bit integer.

    Follow-up: Could you solve it in O(n) time without using the division operation?

    Example 1:
    Input: nums = [1,2,4,6]
    Output: [48,24,12,8]

    Example 2:
    Input: nums = [-1,0,1,2,3]
    Output: [0,-6,0,0,0]

    Constraints:
    - 2 <= nums.length <= 1000
    - -20 <= nums[i] <= 20


    Intuition:
    --------------------
    Aproach0: Keep product of all non-zero elements of the array, and have a count of zeroes in the array, if there are 2 or
    more than 2 zeroes in the array, the result array will have zeroes only, if it has 1 zero, so the result array will have
    zero at each place except the place where zeroes lies, that place will have the product we created in begining. If there's
    no zeroes in the array, then for each index of the result array, store the product divided by current element in the input
    array.
    Time complexity: O(n), Space complexity: O(1)

    Aproach1: n*n nested loop solution where we can go through every other elements of the array for each elements, do their
    product and return.
    Time complexity: O(n*n), Space complexity: O(1)

    Aproach2: Keep 2 arrays, 1 stores prefix product (excluding the current) and another stores suffix. Now for each element
    we can return the multiplication of prefix product and the suffix one.
    Time complexity: O(n), Space complexity: O(n)

    Aproach3: Instead of keeping 2 arrays, we just keep 2 vaiables which have prefix and postfix products stores, now first
    we iterate from left to right and take use of prefix product and store for the current index in the answer array, and
    then in second paas we go through right to left we update postfix product value and keep updating the element of the
    result array by multiplying it with the postfix element.
    Time complexity: O(n), Space complexity: O(1)

*/

vector<int> solutionByDivision(vector<int>& nums){
    int n = nums.size();
    vector<int> res(n, 1);

    int zeroes = 0, nonZeroProduct = 1;
    for(int a: nums){
        if(a==0){
            zeroes++;
        }
        else{
            nonZeroProduct *= a;
        }
    }

    if(zeroes>=2){
        for(int i=0; i<n; i++){
            res[i] = 0;
        }
    }
    else if(zeroes==1){
        for(int i=0; i<n; i++){
            if(nums[i]==0) res[i] = nonZeroProduct;
            else res[i] = 0;
        }
    }
    else {
        for(int i=0; i<n; i++){
            res[i] = nonZeroProduct/nums[i];
        }
    }

    return res;
}

vector<int> productWithoutSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, 1);

    int preProduct = 1, postProduct = 1;

    for(int i=0; i<n; i++){
        res[i] = preProduct;
        preProduct *= nums[i];
    }

    for(int i=n-1; i>=0; i--){
        res[i] *= postProduct;
        postProduct *= nums[i];
    }

    return res;
}

int main() {

    vector<int> nums = {1,2,4,6};

    // vector<int> res = solutionByDivision(nums);
    vector<int> res = productWithoutSelf(nums);

    cout<<"[";
    for(int a: res){
        cout<<a<<", ";
    }
    cout<<"]";

    return 0;
}