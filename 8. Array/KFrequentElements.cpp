#include <bits/stdc++.h>
using namespace std;

/*
(5/Neetcode150)
    Problem Statement
    --------------------
    Top K Frequent Elements: Given an integer array nums and an integer k, return the k most frequent elements within the array.
    The test cases are generated such that the answer is always unique.
    You may return the output in any order.

    Example 1:
    Input: nums = [1,2,2,3,3,3], k = 2
    Output: [2,3]

    Example 2:
    Input: nums = [7,7], k = 1
    Output: [7]

    Constraints:
    - 1 <= nums.length <= 10^4.
    - -1000 <= nums[i] <= 1000
    - 1 <= k <= number of distinct elements in nums.

    Intuition:
    --------------------
    Aproach1: Keep a map of elements with it's occurence in the array, now sort this map based on element's occurence. Return top K.
    Time complexity: O(n*logn), Space complexity: O(1)

    Aproach2: Keep a map of the elements and it's count, and then take a K sized min heap of this pair (elements & it's occurence) mapping,
    insert element in the heap based on the occurence, if any insertion increase size of heap more than K remove the top element. Return the heap.
    Time omplexity: O(n*logK), Space complexity: O(n+k)

    Aproach3: Keep a map of the elements and it's count, keep a bucket(vector) of occurences (of size n+1, as occurenceres will have value <= n),
    now each index of this bucket will stores the occurences of elements. Now move in the map and store it's elements in the bucket as per their
    occurences. To return the top K, start moving in the bucket from end and remove K elements from the bucket, this will be our answer.
    Time complexity: O(n), Space complexity: O(n)
*/

vector<int> solution1(vector<int>& nums, int k){
    unordered_map<int, int> elementsCount;

    for(int el: nums){
        elementsCount[el]++;
    }

    vector<pair<int, int>> arr;
    for(auto el: elementsCount){
        arr.push_back({el.second, el.first});
    }

    // sort(arr.rbegin(), arr.rend());
    sort(arr.begin(), arr.end(), [](pair<int, int> a, pair<int, int> b){
        return a.first > b.first;
    });

    vector<int> ans;
    for(int i=0; k>0; i++){
        ans.push_back(arr[i].second);
        k--;
    }

    return ans;
}

vector<int> solution2(vector<int>& nums, int k){
    unordered_map<int, int> elementsCount;
    for(int el: nums){
        elementsCount[el]++;
    }

    //min heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    for(auto el: elementsCount){
        minHeap.push({el.second, el.first});
        if(minHeap.size() > k){
            minHeap.pop();
        }
    }

    vector<int> ans;
    for(int i=0; k>0; i++){
        ans.push_back(minHeap.top().second);
        minHeap.pop();
        k--;
    }

    return ans;
}

vector<int> solution3(vector<int>& nums, int k){
    unordered_map<int, int> elementsCount;
    for(int el: nums){
        elementsCount[el]++;
    }

    int n = nums.size();
    vector<vector<int>> bucket(n+1);

    for(auto el: elementsCount){
        int item = el.first;
        int occurence = el.second;

        bucket[occurence].push_back(item);
    }

    vector<int> ans;
    for(int i=n; k>0; i--){
        for(int j=0; j<bucket[i].size() && k>0; j++){
            ans.push_back(bucket[i][j]);
            k--;
        }
    }

    return ans;
}

int main(){
    int k = 2;
    vector<int> nums = {1,2,2,3,3,3};

    // vector<int> ans = solution1(nums, k);
    // vector<int> ans = solution2(nums, k);
    vector<int> ans = solution3(nums, k);
    for(auto item: ans){
        cout<<item<<" ";
    } cout<<endl;

    return 0;
}