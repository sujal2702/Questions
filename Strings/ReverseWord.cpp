// Reverse Words in a String III Easy Level

// Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

// without starting ya ending spaces or without uncessary spaces in between -----------> simple question

#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     string reverseWords(string s) {
//         int start = 0;
//         for(int i=0; i<=s.size(); i++){
//             if(i==s.size() || s[i] == ' '){
//                 reverse(s.begin()+start , s.begin()+i); //start to 1 less in i tak print
//                 start = i+1;
//             }
//         }
//         return s;
//     }
// };

//  ------------->  REVERSE A STRING (MEDIUM LEVEL) ------>> which have Starting , ending and middle spaces----->

string reverseWords(string s) {
      string ans = "";
      int n = s.size();
      reverse(s.begin() , s.end()); //pure string ko palat diye location sahi h but form ulta

      for(int i=0; i<n; i++){
        string word = "";   // empty string
        while(i<n && s[i] != ' '){ //jab tak space k equal nhi string se word banao
         word = word + s[i];
         i++;
        }

        reverse(word.begin(), word.end());

        if(word.length() > 0){ //ye isliye taki (agar word len 0) ho uske liye faltu space   
                                 // faltu space na add ho jaaye
        ans = ans + " " + word;
        }

      }
      return ans.substr(1);

      
}


// Step-by-Step Algorithm

// 🔸 Step 1: Ek empty string banao
// ans = ""


// Ye final answer store karega.

// 🔸 Step 2: String ki length nikal lo
// n = s.size()

// 🔸 Step 3: Puri string ko reverse kar do
// reverse(s.begin(), s.end())


// Agar string thi:

// "i love coding"


// Reverse ke baad ban jayegi:

// "gnidoc evol i"


// 👉 Ab words ki position sahi ho gayi
// 👉 Bas har word ka andar ka order galat hai

// 🔸 Step 4: String me loop chalao (0 se n tak)
// for i = 0 to n-1


// Har iteration me:

// 🔸 Step 5: Ek empty word string banao
// word = ""

// 🔸 Step 6: Jab tak space na mile tab tak characters add karo
// while(i < n && s[i] != ' ')
//     word += s[i]
//     i++


// Isse ek pura word mil jayega (ulta form me)

// Example:

// "gnidoc"

// 🔸 Step 7: Us word ko reverse karo
// reverse(word.begin(), word.end())


// Ab:

// "coding"

// 🔸 Step 8: Agar word empty nahi hai to answer me add karo
// if(word.length() > 0)
//     ans = ans + " " + word


// ⚠ Yaha har word ke pehle ek space add ho raha hai.

// 🔸 Step 9: Loop continue karega jab tak pura string process na ho jaye
// 🔸 Step 10: Pehla extra space hata do

// Kyuki har word ke pehle space lagaya tha:

// return ans.substr(1)



// Ye first character (extra space) hata deta hai.

int main() {
    string input;
    
    cout << "Enter a string to reverse words: ";
    getline(cin, input);  // Using getline to capture spaces in the input
    
    cout << "Original: \"" << input << "\"" << endl;
    cout << "Reversed: \"" << reverseWords(input) << "\"" << endl;
    
    return 0;
}
