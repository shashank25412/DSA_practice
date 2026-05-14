#include <bits/stdc++.h>
using namespace std;

/* 
(2/Neetcode150)
    Problem Statement
    --------------------
    Valid Anagram: Given two strings s and t, return true if the two strings are anagrams of each other,
    otherwise return false.
    (An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.)

    Constraints:
     i. 1 <= s.length, t.length <= 5 * 10^4
     ii. s and t consist of lowercase English letters.

    Example 1:
    Input: s = "racecar", t = "carrace"
    Output: true

    Example 2:
    Input: s = "jar", t = "jam"
    Output: false

    Intuition:
    --------------------
    Approach1: Sort the strings and compare.
    Time complexity: O(nlogn)

    Approach2: Keep 2 maps for both the strings which stores the counts of characters now compare the count
    of the characters of both the strings.
    Time complexity: O(n), Space complexity: O(n)

    Approach3: Since any string contains only the 26 letters of the english alphabets, we keep an map/array of
    length 26 to keep track of each characters for the string1 by interating over each character of string1
    and then we iterate over string2 and remove the count of the each character from the map/array. If any of
    the character of the array has count 1 or more then our answer is false, else true.
*/

bool isAnagram(string str1, string str2) {
    unordered_map<char, int> charCounts;

    for(char ch: str1) {
        charCounts[ch]++;
    }

    for(char ch: str2) {
        charCounts[ch]--;
        if(charCounts[ch] == 0) charCounts.erase(ch);
    }

    return (charCounts.size() == 0);
}

int main() {

    string s = "racecar", t = "carrace";
    
    cout<<isAnagram(s, t)<<endl;

    return 0;
}