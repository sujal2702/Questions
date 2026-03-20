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

/* --------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Infix to postfix conversion

 Rules ( IMPORTANT)
1. Operand (a, b, 1, 2…)

➡️ Directly add to answer string

2. (

➡️ Push to stack

3. )

➡️ Pop until '(' is found

4. Operator (+ - * / ^)

➡️ While stack has higher/equal priority → pop
➡️ Then push current operator

⚠️ Exception:

^ → right associative (don’t pop on equal)

5. End of expression

-----------PSEUDOCODE-----------------------

function priority(op):

    if op == '+' or '-': return 1
    if op == '*' or '/': return 2
    if op == '^': return 3

    return 0
function infixToPostfix(s):

    create empty stack st
    create empty string ans

    for each character ch in s:

        if ch is operand:
            append ch to ans

        else if ch == '(':
            push ch to stack

        else if ch == ')':
            while stack is not empty AND top != '(':
                append top to ans
                pop stack
            pop '(' from stack

        else:  // operator

            while stack is not empty AND
                  (priority(ch) < priority(top) OR
                  (priority(ch) == priority(top) AND ch != '^')):

                append top to ans
                pop stack

            push ch to stack

    // after traversal
    while stack is not empty:
        append top to ans
        pop stack

    return ans
--------------------------------------------------------------------------------------------------------------------------------------------------------------
Infix to Prefix Conversion

1. Reverse the string + after reversing completely reverse the bracket
2. Perform this infix to postfix conversion and store it in answer 
3. At last reverse the answer

one change in logic of infix to postfix logic here

If current character is operator:

    If operator == '^':
        While stack not empty AND
              priority(curr) <= priority(stack.top()):
            pop → add to answer

    Else:
        While stack not empty AND
              priority(curr) < priority(stack.top()):
            pop → add to answer

    Push current operator to stack
    
 */
