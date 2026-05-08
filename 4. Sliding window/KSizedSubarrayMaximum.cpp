#include <bits/stdc++.h>
using namespace std;

/*
    K sized Subarray Maximum
    --------------------------
    Problem Statement: Given an array of integers and a number K, find the maximum of all subarrays of size K.
    Example:
        Input: arr[] = {1, 2, 3, 4, 5}, K = 3
        Output: [3, 4, 5]
        Explanation: The subarrays of size 3 are {1, 2, 3}, {2, 3, 4} and {3, 4, 5} with maximums 3, 4 and 5 respectively.

    Approach:
        1. We keep a list of element which can contribute to the maximum of K sized array.
        2. So, for that, firstly we prepare our list for first K elements by adding element to the list by comparing
           the already existing value at the end of the list is whether less than the current value, if less 
           we remove it and we keep doing it until we found equal or grater than the current value, this ensures me
           that we are not storing any value in range K which do not contribute in my answer.
        3. And with that, the 1st value of the list will give me the answer for the first K elements.
        4. Now we slide our window from (K+1)th element to the end of the array, and in similar fashion we put each
           incoming element (arr[i]), but before that we also have to remove arr[i-K] as window sildes by 1.
           And whatever we found at the first element of the list will be our answer for the current window, similar
           way get the ans for the each silding window.
*/

vector<int> maxInKSizedSubarray(vector<int> &arr, int K){
    vector<int> ans;
    list<int> kMaxElements;

    for(int i=0; i<K; i++){
        while(!kMaxElements.empty() && kMaxElements.back() < arr[i]){
            kMaxElements.pop_back();
        }
        kMaxElements.push_back(arr[i]);
    }
    ans.push_back(kMaxElements.front());

    for(int i=K; i<arr.size(); i++){
        //remove the arr[i-K] element
        if(kMaxElements.front() == arr[i-K]) kMaxElements.pop_front();

        while(!kMaxElements.empty() && kMaxElements.back() < arr[i]){
            kMaxElements.pop_back();
        }
        kMaxElements.push_back(arr[i]);

        ans.push_back(kMaxElements.front());
    }

    return ans;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int K = 3;
    vector<int> ans = maxInKSizedSubarray(arr, K);
    for(int i: ans) cout << i << " ";

    return 0;
}