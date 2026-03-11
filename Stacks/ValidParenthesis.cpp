#include<iostream>
#include<stack>
#include<string>
using namespace std;

//-------------------------MAIN LOGIC -------------------------------------------------
class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for (int i = 0; i < s.size(); i++) {

            char ch = s[i];

            // agar open bracket hai to stack me push karo
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }

            else {

                if (!st.empty()) { // not empty

                    if (ch == ')' && st.top() == '(' ||
                        ch == '}' && st.top() == '{' ||
                        ch == ']' && st.top() == '[') {

                        st.pop();
                    } 
                    else { 
                        // mtlb stack empty NHI H + closing bracket ka pair top pe nhi h
                        return false;
                    }
                } 
                else { 
                    // mtlb stack empty hai aur closing bracket mila h
                    return false;
                }
            }
        }

        if (st.empty()) {
            return true;
        } 
        else {
            return false;
        }
    }
};

//----------------------THIS IS THE TESTING PART OF THE CODE -------------------------------
int main() {
    
    Solution sol;
    
    // Test cases
    string test1 = "()";
    string test2 = "()[]{}";
    string test3 = "(]";
    string test4 = "([)]";
    string test5 = "{[]}";
    
    cout << "Test 1: \"" << test1 << "\" -> " << (sol.isValid(test1) ? "Valid" : "Invalid") << endl;
    cout << "Test 2: \"" << test2 << "\" -> " << (sol.isValid(test2) ? "Valid" : "Invalid") << endl;
    cout << "Test 3: \"" << test3 << "\" -> " << (sol.isValid(test3) ? "Valid" : "Invalid") << endl;
    cout << "Test 4: \"" << test4 << "\" -> " << (sol.isValid(test4) ? "Valid" : "Invalid") << endl;
    cout << "Test 5: \"" << test5 << "\" -> " << (sol.isValid(test5) ? "Valid" : "Invalid") << endl;
    
    return 0;
}