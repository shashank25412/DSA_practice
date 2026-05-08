#include <bits/stdc++.h>
using namespace std;

/*
    ----------------------
    Sliding Window
    ----------------------
    When we are dealing with problems that require checking answers of some ranges in an array,
    the Sliding window algorithm can be a very powerful technique.

    How to identify if a problem can be solved using the sliding window technique?
        1. These problems generally evolve around Finding Maximum / Minimum Subarray, Substrings
           which satisfy some specific condition.
        2. The size of the subarray or substring 'K' will be given or asked in some of the problems.
        3. These problem can easily be solved in O(n2) time complexity using nested loops,
           using sliding window we can solve these in O(n) Time Complexity.
        4. Required Time Complexity: O(n) or O(nlog(n))
        5. Constraints: n <= 10e6 , If n is the size of the Array / String.

    There are generally two types of sliding window problems:
        1. Fixed Size Sliding Window: In this type of problems, the size of the subarray or substring 'K'
           is given and we have to find the answer for all the subarrays or substrings of size 'K'.
        2. Variable Size Sliding Window: In this type of problems, the size of the subarray or substring
           is not fixed and can vary. We have to find the answer for all the subarrays or substrings that
           satisfy a specific condition.

    -----------------------

    Max Sum Subarray of size K
    Problem Statement: Given an array of integers and a number K, find the maximum sum of a subarray of size K.

    Example:
        Input: arr[] = {100, 200, 300, 400}, K = 2
        Output: 700
        Explanation: The subarray of size 2 with the maximum sum is {300, 400}.

    Approach:
        1. We can solve this problem using a fixed size sliding window approach.
        2. We will maintain a window of size K and keep track of the sum of the elements in the window.
        3. We will slide the window from the beginning of the array to the end, updating the sum and keeping
           track of the maximum sum encountered.
        4. The time complexity of this approach is O(n) and the space complexity is O(1).
*/

int maxSumSubbarray(vector<int> &arr, int K){
    int ans = 0, sum = 0;

    // Calculate the first window
    for(int i=0; i<K; i++){
        sum += arr[i];
    }
    ans = max(ans, sum);

    for(int i=K; i<arr.size(); i++){
        sum += (arr[i] - arr[i-K]);
        ans = max(ans, sum);
    }

    return ans;
}

int main() {
    vector<int> arr = {100, 200, 300, 400};
    int K = 2;

    cout << "Maximum sum of a subarray of size " << K << " is: " << maxSumSubbarray(arr, K) << endl;

    return 0;
}