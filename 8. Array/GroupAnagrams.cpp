#include <bits/stdc++.h>
using namespace std;

/*
(4/Neetcode150)
    Problem Statement
    --------------------
    Group Anagrams: Given an array of strings strs, group all anagrams together into sublists. You may return
    the output in any order.
    (An anagram is a string that contains the exact same characters as another string, but the order of the
    characters can be different.)

    Example 1:
    Input: strs = ["act","pots","tops","cat","stop","hat"]
    Output: [["hat"],["act", "cat"],["stop", "pots", "tops"]]

    Example 2:
    Input: strs = ["x"]
    Output: [["x"]]

    Example 3:
    Input: strs = [""]
    Output: [[""]]

    Constraints:
     - 1 <= strs.length <= 1000.
     - 0 <= strs[i].length <= 100
     - strs[i] is made up of lowercase English letters.

    Intuition:
    --------------------
    Approach1: Sort each string and group the equal strings by grouping their indices first and then taking the
    value from the indices.
    Time complexity: O(m*nlogn), where n is the average size of the strings and m is the length of the string array.

    Approach2: Keep a map of key-values where key will be a 26 length string (like a hash key) that holds the counts of
    each alphabetic characters (among 26 characters) of the string and value will be an array of string having count of
    characters as in the key. Basically it represents a string as it's characters occurences (like 1a0b2c.... for acc)
    in canonical representation. At the end, return the array of values as answer.
    Time complexity: O(m*n), where n is the average size of the strings and m is the length of the string array.
    Space complexity: O(n)
*/

vector<vector<string>> groupAnagrams(vector<string> strs) {
    unordered_map<string, vector<string>> charCountMap;

    for(auto str: strs) {

        vector<int> charCount(26, 0);
        for(auto ch: str) charCount[ch-'a']++;

        string keyString = "";
        for(int i=0; i<26; i++){
            keyString += to_string(charCount[i]) + "#"; // we need # as a delimeter other wise 10 and 1 0 will be considered same
        }

        charCountMap[keyString].push_back(str);
    }

    vector<vector<string>> ans;
    for(auto it: charCountMap){
        ans.push_back(it.second);
    }

    return ans;
}

int main() {

    vector<string> strs = {"act","pots","tops","cat","stop","hat"};

    vector<vector<string>> ans = groupAnagrams(strs);

    for(auto group: ans){
        cout<<"[";
        for(auto str: group){
            cout<<str<<", ";
        }
        cout<<"] ";
    }

    return 0;
}