#include<bits/stdc++.h>
#include<string>
using namespace std;

class Solution {
  public:
    string calc_Sum(vector<int>& arr1, vector<int>& arr2) {
        // Complete the function
        vector<int> ans;
        int i = arr1.size() - 1;
        int j = arr2.size() - 1;
        int carry = 0;
        
        while(i>=0 && j>=0){ //piche se start kiye h
            
            int val1 = arr1[i];
            int val2 = arr2[j];
            
            int sum = val1 + val2 + carry;
            
            carry = sum / 10; // carry 1 aage k liye store kiye h
            sum = sum % 10 ; // isse sirf last element jo ayega wo store karenge
            ans.push_back(sum);
            i--;
            j--;
        }
        
        //if element from 1st arr1 is left 
        while(i>=0){
            
            int val1 = arr1[i];
            
            int sum = val1 + carry;
            
            carry = sum / 10; // carry 1 aage k liye store kiye h
            sum = sum % 10 ; // isse sirf last element jo ayega wo store karenge
            ans.push_back(sum);
            i--;
            
        }
        
         while(j>=0){ //2nd Case Jisme arr2 se element bacha ho
            
            int val2 = arr2[j];
            
            int sum =  val2 + carry;
            
            carry = sum / 10; // carry 1 aage k liye store kiye h
            sum = sum % 10 ; // isse sirf last element jo ayega wo store karenge
            ans.push_back(sum);

            j--;
        }
        
        while(carry != 0){ // jisme carry bacha ho
          
          int sum = carry;
          carry = sum/10;
          sum = sum % 10;
          ans.push_back(sum);
          
        }
       // Reverse the vector
            reverse(ans.begin(), ans.end());

       // Convert vector<int> to string
        string result = "";

        for (int num : ans) {
         result += (num + '0');  // int digit ko char me convert kar rahe
        }

      return result;

    }
};
