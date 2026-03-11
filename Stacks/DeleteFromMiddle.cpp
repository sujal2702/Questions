#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//---------------------------Delete From Middle of Stack----- Iterative Approach-------------

class Solution {
  public:

    void deleteMid(stack<int>& s) {
        
        vector<int> arr; //store temporarilt top elements of stack
        
        int n = s.size(); //stack ka size
        
        int k = s.size() - 1; // yeh variable top element ka index represent kar raha hai
        
        int mid;
        
        if(n & 1) {  //check even or odd
            
            mid = (n / 2); 
            // odd case me middle index directly n/2 hota hai
        } 
        else{
            
            mid = (n / 2) - 1; 
            // even case me problem ke according lower middle delete karna hai
        }
            
        while(k != mid) {
            
            arr.push_back(s.top()); 
            s.pop(); 
            k--; 
        }
        
        // yaha tak pahunchte hi top element middle element ban chuka hai
        
        s.pop(); // middle element ko delete kar diya
        
        // ab jo elements vector me store kiye the unko wapas stack me daalenge
        for(int i = arr.size() - 1; i >= 0; i--){
            
            s.push(arr[i]); 
            // reverse order me push kar rahe hain taki stack ka original order maintain rahe
        }
    }
};
//--------------------Recursive Approach ----------------------------------------------------

class Solution {
  public:
    void solve(stack<int>& s , int count, int size){
        
        //BASE CASE
        if(count == size/2){
            s.pop();
            return;
        }
        
        //top wala element remove karte rho
        int num = s.top();
        s.pop();
        
        //Recursive call
        solve(s, count+1, size);
        
        // return k time push karte jana
        s.push(num);
    }
    void deleteMid(stack<int>& s) {
       
       int count = 0;
       int  size= s.size();
       solve(s, count, size);
    }
};

