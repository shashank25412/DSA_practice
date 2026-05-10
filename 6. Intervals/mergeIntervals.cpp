#include<bits/stdc++.h>
using namespace std;

/*
    Intervals
    ----------
    Interval problems typically involve sorting the given intervals, and then processing each interval in sorted order.
    Intervals can be sorted by,
        1. their start time, or by
        2. their end time.
    The choice of sorting order depends on the specific problem and the approach you want to take.

    --------------------------------------------------------------------------------------------------------------------

    Q. Given a collection of intervals, merge all overlapping intervals.

    Example 1:
    Input: [[1,3],[2,6],[8,10],[15,18]]
    Output: [[1,6],[8,10],[15,18]]
    Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

    Intuition:
    ----------
    1. Sort the intervals based on their start time.
    2. Iterate over each interval and check if the current interval starts before the previous interval ends.
       If it does, then we have an overlap and we can merge the intervals by updating the end time of the previous
       interval to be the maximum of the current end time and the previous end time.
    3. It it doesn't, then we can add the previous interval to our result and move on to the next interval.
*/

#define vectorOfPair vector<pair<int, int>>

vectorOfPair mergeIntervals(vectorOfPair &aIntervals){
    vectorOfPair oMergedIntervals;

    int start = aIntervals[0].first;
    int end = aIntervals[0].second;

    for(int i=1; i<aIntervals.size(); i++){
        // condition: if prev ends after the current starts, this means current is overlapping with previous
        if(aIntervals[i].first < end){
            end = max(end, aIntervals[i].second);
        }
        else { // non-overlaps
            oMergedIntervals.push_back({start, end});
            start = aIntervals[i].first;
            end = aIntervals[i].second;
        }
    }
    oMergedIntervals.push_back({start, end});

    return oMergedIntervals;
}

int main() {

    vectorOfPair aIntervals = {{1,3}, {4,6}, {5,8}, {7,8}, {9,11}};

    vectorOfPair mergedIntervals = mergeIntervals(aIntervals);

    for(auto interval: mergedIntervals){
        cout<<"("<<interval.first<<", "<<interval.second<<") ";
    }

    return 0;
}