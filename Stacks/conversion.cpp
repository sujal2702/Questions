/*
        The Priority order is maximum for '^' 3 , Then '*' & '/' 2 , '+' & '-' 1 , and others have -1;  */

// 1.Function to Convert from infix to postfix

class Solution {
  public:
  
    int priority(char op){
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;  // Design this function first , assign priorities
    if(op == '^') return 3;
    return 0;
    }
    
    string infixToPostfix(string& s) {

    int n = s.size();
    
    int i = 0;
    stack <char> st;
    string ans = "";
     
    while(i < n){
        
        if((s[i] >= 'a' && s[i] <= 'z')||
          (s[i] >= 'A' && s[i] <= 'Z')||
          (s[i] >= '0' && s[i] <= '9')){ //these are operands
          
            ans = ans + s[i];
        }
        
        else if(s[i] == '('){
            st.push(s[i]);
        }
        
        else if( s[i] == ')'){
            
            while(!st.empty() && st.top() != '('){
                ans = ans + st.top();
                st.pop();
            }
            //ab top pe open bracket hoga isliye once more pop
            if(!st.empty()) st.pop();
        }
        
        else{
            //ab sirf operators bache h
            while(!st.empty() && 
                ((priority(s[i]) < priority(st.top())) ||
                (priority(s[i]) == priority(st.top()) && s[i] != '^'))){
                ans = ans + st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        
       i++; 
    }
     while(!st.empty()){
    ans = ans + st.top();
    st.pop();
        }
    return ans;
        
    }
};

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
