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

-------------------------------------------------------------------------------------------------------------------------------------------------------------------
EXCEPT INFIX TO.... PREFIX AND POSTIFX CONVERSION

 --------->>>>>> -------------->>>>>>(IMPORTANT)  --------------->>>>>>>>

BAAKI 4 JAISE KI prefix to postfix , infix AUR postfix to infix,prefix ka SAAR HAI YE

postfix me AAGE se start krte h
prefix me piche se start krte h iteration kisi bhi case me


Aur jisme convert kr rhe h usme krne ka try karo 
Agar prefix me convert kr rhe h to dono top k aage insert karo operator ko
Agar infix h to dono top k bich me karo insert
Agar postfix h to dono operator k baad me karo insert

sirf infix to prefix & infix to postfix ka case thoda alag  h (Already Mnetioned)

jab prefix to .. conversion ho 
tab ham piche se start kr rhe h 
'(' top1 + operator + top2 ')' -->  to Infix
top1 + top2  + operator  --> to Postfiix


jab postfix to .. conversion ho 
tab ham aage se start kr rhe h to 
'(' top2 + operator + top1 ')' --> to Infix
operator + top2 +  top1   --> to Prefix



----------------------------------------------------------------------------------------------------------------------------------------------
POSTFIX TO INFIX

Initialize empty stack st

Traverse the string from left to right (i = 0 to n-1):

    If current character is operand:
        Push it into stack

    Else (current character is operator):

        t1 = st.top()
        st.pop()

        t2 = st.top()
        st.pop()

        con = '(' + t2 + operator + t1 + ')'

        Push con back into stack

After traversal:
    Return st.top()
 */
