#include<iostream>
#include<stack>
#include<vector>
using namespace std;

// code for InsertAtBottom -------------------JUST THE LOGIC PART--------------------------

void insertAtBottom (stack <int>& st , int element){

    //Base Case
    if(st.empty()){
        st.push(element);
        return ;
    }

    int num = st.top(); //top element ko store karo phir pop karo
    st.pop();

    //recursive call
    insertAtBottom(st, element);

    //while returning wapas push karo har level pr .... top element ko
    st.push(num);
}

void ReverseStack(stack <int> &st){

    if(st.empty()){
        return ;
    }

    //top element ko store karo
    int num = st.top();
    st.pop();

    //recursive call
    ReverseStack(st);

    //while returning insertAtBottom call kar do taki reversed list k end me top jaye
    // aur pura stack reverse rhe

    insertAtBottom(st, num);
}

//------------------------------------------------------------------------------------------------------------------------
// Sort a STACK using Recursion
void sortedInsert(stack <int> &st , int element){

    if(st.empty() || !st.empty() && st.top() < element){
        st.push(element);
        return;
    }

    //normal
    int n = st.top();
    st.pop();

    //recusrive call
    sortedInsert(st, element);

    //while returning push elements which u poped earlier
    st.push(n);
}
void sortStack(stack <int> &st){

    if(st.empty()){
        return;
    }

    int num = st.top();
    st.pop();

    //recusrive call
    sortStack(st);

    //while returning back
    sortedInsert(st, num);
}

/*
---------------------------------------Reverse Stack Using Recursion-------------------------
Time Complexity O(n^2)
Space Complexity O(n)
-------------------------Algorithm-------------------------------------------------------

1. pehle stack empty karo 
2. while emptying Stack top element store karo qki usse hi insertAtBottom karna h
3. 1st case dekho baaki recursion reverse krke de dega 
4. jab recusrion reverse krke de de to uske end me insertAtBottom wale logic se top wala element dal do
5. insertAtBottom top ko last me kr dega har element k liye

*/


/*
 Brute Force method

 pehle stack k saare elements vector me daal lo
 phir vector me se left to right print karwa lo (reverse order me print hoga)

*/
