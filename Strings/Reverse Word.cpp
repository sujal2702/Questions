// Reverse Words in a String III Easy Level

// Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

// without starting ya ending spaces or without uncessary spaces in between -----------> simple question

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        for(int i=0; i<=s.size(); i++){
            if(i==s.size() || s[i] == ' '){
                reverse(s.begin()+start , s.begin()+i); //start to 1 less in i tak print
                start = i+1;
            }
        }
        return s;
    }
};

