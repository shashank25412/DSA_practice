#include <bits/stdc++.h>
using namespace std;

/*
(10/Neetcode150)
    Problem Statement
    --------------------
    Valid Palindrome: Given a string s, return true if it is a palindrome, otherwise return false.
    A palindrome is a string that reads the same forward and backward. It is also case-insensitive and ignores all non-alphanumeric characters.
    Note: Alphanumeric characters consist of letters (A-Z, a-z) and numbers (0-9).

    Example 1:
    Input: s = "Was it a car or a cat I saw?"
    Output: true
    Explanation: After considering only alphanumerical characters we have "wasitacaroracatisaw", which is a palindrome.

    Example 2:
    Input: s = "tab a cat"
    Output: false
    Explanation: "tabacat" is not a palindrome.

    Constraints:
    - 1 <= s.length <= 1000
    - s is made up of only printable ASCII characters.

    Intuition:
    --------------------
    Aproach1: Remove all the non alphanumeric characters first, loop over the new string and check till half, that the characters from the
    beginning is equal to the character from the end.
    Time complexity: O(n), Space complexity: O(1)

    Aproach2: Keep 2 pointers, a left and a right, move the pointer ahead if you find a non-alphanumeric characters, otherwise compare the
    characters at left and right if doesn't match then return false, else comapre till left is less than right, and return true if all matches.
    Time complexity: O(n), Space complexity: O(1)
*/

bool isPalindrome(string& s){
    string formattedStr="";
    for(char ch:s){
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
            formattedStr += tolower(ch);
        }
    }

    cout<<formattedStr<<endl;

    int size = formattedStr.size();
    for(int i=0; i<size/2; i++){
        if(formattedStr[i] != formattedStr[size-1-i]){
            return false;
        }
    }
    return true;
}

bool isAlphaNumeric(char ch){
    if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
        return true;
    }
    else{
        return false;
    }
}

bool isPalindrome2(string& s){
    int left = 0, right = s.size()-1;

    while(left<right){
        while(left<right && !isAlphaNumeric(s[left])){
            left++;
        }
        while(left<right && !isAlphaNumeric(s[right])){
            right--;
        }

        if(left<right && tolower(s[left]) != tolower(s[right])){
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int main() {
    string s = "Was it a car or a cat I saw?";

    cout<<(isPalindrome2(s)?"True":"False")<<endl;

    return 0;
}