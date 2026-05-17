#include <bits/stdc++.h>
using namespace std;

/*
(6/Neetcode150)
    Problem Statement
    --------------------
    Encode and Decode Strings: Design an algorithm to encode a list of strings to a string. The encoded string is then sent over
    the network and is decoded back to the original list of strings.

    Machine 1 (sender) has the function:

    string encode(vector<string> strs) {
        // ... your code
        return encoded_string;
    }
    Machine 2 (receiver) has the function:

    vector<string> decode(string s) {
        //... your code
        return strs;
    }
    So Machine 1 does:

    string encoded_string = encode(strs);
    and Machine 2 does:

    vector<string> strs2 = decode(encoded_string);
    strs2 in Machine 2 should be the same as strs in Machine 1.

    Implement the encode and decode methods.

    Example 1:
    Input: dummy_input = ["Hello","World"]
    Output: ["Hello","World"]
    
    Explanation:
    Machine 1:
        Codec encoder = new Codec();
        String msg = encoder.encode(strs);
        Machine 1 ---msg---> Machine 2

    Machine 2:
        Codec decoder = new Codec();
        String[] strs = decoder.decode(msg);

    Example 2:
    Input: dummy_input = [""]
    Output: [""]

    Constraints:
    - 0 <= strs.length < 100
    - 0 <= strs[i].length < 200
    - strs[i] contains any possible characters out of 256 valid ASCII characters.
*/

string encode(vector<string>& strs){
    string res="";

    for(string str: strs){
        int size = str.size();
        res += to_string(size)+ "#" + str;
    }

    return res;
}

vector<string> decode(string s){
    vector<string> res;

    {
    // bool sizeCheckFlag = true;
    // int size = 0;
    // string s="";

    // for(char ch: str){
    //     if(sizeCheckFlag){
    //         if(ch=='#'){
    //             sizeCheckFlag = false;
    //             if(size == 0){
    //                 res.push_back("");
    //                 sizeCheckFlag = true;
    //             }
    //             continue;
    //         }

    //         size = size*10 + (int)(ch-'0'); //cout<<"Debug1: "<<size<<endl;
    //     }
    //     else{
    //         s += ch; //cout<<"Debug2: "<<s<<"::"<<size<<endl;
    //         size--;

    //         if(size==0){
    //             res.push_back(s);
    //             s="";
    //             sizeCheckFlag = true;
    //             continue;
    //         }
    //     }
    // }
    }

    int i=0;
    while(i<s.size()){
        int j=i;
        
        while (s[j] != '#'){
            j++;
        }

        int size = stoi(s.substr(i, j-i));
        string word = s.substr(j+1, size);

        res.push_back(word);

        i = j+1+size;
    }

    return res;
}

int main() {

    vector<string> input = {"Hello","World"};

    string encodedString = encode(input);
    cout<<encodedString<<endl;

    vector<string> decodedString = decode(encodedString);

    cout<<"[";
    for(auto s: decodedString){
        cout<<s<<", ";
    }
    cout<<"]";

    return 0;
}