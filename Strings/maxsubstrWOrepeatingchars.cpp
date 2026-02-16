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

int main(){
    string input;
    
    cout << "Enter a string: ";
    cin >> input;
    
    int result = lengthOfLongestSubstring(input);
    
    cout << "Input string: " << input << endl;
    cout << "Length of longest substring without repeating characters: " << result << endl;
    
    return 0;
}
