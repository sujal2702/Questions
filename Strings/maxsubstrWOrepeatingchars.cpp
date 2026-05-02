// set + brute force approach ..
#include<bits/stdc++.h>
#include<set>
#include<string>
using namespace std;


    int lengthOfLongestSubstring(string s) {
        int ans  = 0; // becuase we need to return the max size of substring
        for(int i =0; i<s.size(); i++){
            unordered_set <int> st;
            for(int j=i; j<s.size(); j++){
                if(st.count(s[j])){ //returns 0 if element is not present // returns 1 if element is present
                    break;
                }
                else{
                    st.insert(s[j]);
                }
                ans = max(ans , j-i+1); //j-i-1 length deta h ..changes for every i loop
             }
        }
        return ans;
    }
// this is of Time complexity O(N^2)

//The Sliding Window + Two Pointer Approach in O(N) Time Complexity
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0;
        int r = 0;
        int maxLen = 0;
        int hash[256];
        fill(hash, hash + 256, -1);
        while (r < n) {
            // check if the element is in map or not

            if (hash[s[r]] != -1) { // this means it is in the map

                if (hash[s[r]] >= l) { //jo last occurrence hai, kya wo current window ke andar hai?
                    l = hash[s[r]] + 1; //shrink window where there in no duplicate
                }
            }
            // if it is not in  the map
            maxLen = max(maxLen, r - l + 1);
            hash[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};

int main(){
    string input;
    
    cout << "Enter a string: ";
    cin >> input;
    
    int result = lengthOfLongestSubstring(input);
    
    cout << "Input string: " << input << endl;
    cout << "Length of longest substring without repeating characters: " << result << endl;
    
    return 0;
}
