//Stack Implementation using array

#include<iostream>
#include<stack>
using namespace std;

class Stack{
    public:
    
    int size;
    int *arr;
    int top;

    Stack(int size){ //constructor
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
        if(size - top > 1) {//logic to check if stack is empty or not
            // if true means not empty
            top++;
            arr[top] = element;
        }
        else{
            cout <<"Stack Overflow" << endl;
        }
    }

    void pop(){
        //first check if stack is not empty
        if(top >= 0){
            top--;
        }
        else{
            cout <<" Stack Underflow" << endl;
        }
    }

    int peek(){
        if(top >= 0) return arr[top]; // we can't return just top because we need to return int not pointer
        else{
            cout<<"Stack is Empty so not top to return " <<endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){

    Stack st(5);

    st.push(5);
    st.push(10);
    st.push(20);
    st.push(5);
    st.push(10);
    st.push(20); // this will create stack overflow condition

    cout <<"Top element of stack is " <<st.peek() <<endl;

    st.pop();

    cout <<"Top element of stack is " <<st.peek() <<endl;

    st.pop();
    st.pop();

    cout <<"Top element of stack is " <<st.peek() <<endl;
}

// Stacks STL FUNCTION

// #include <iostream>
// #include <stack>
// using namespace std;

// int main() {

//     // Creating a stack
//     stack<int> s;

//     // PUSH - inserting elements
//     s.push(10);
//     s.push(20);
//     s.push(30);
//     s.push(40);

//     cout << "After pushing elements:\n";
//     cout << "Top element: " << s.top() << endl;
//     cout << "Size: " << s.size() << endl;

//     // POP - removing top element
//     s.pop();

//     cout << "\nAfter one pop:\n";
//     cout << "Top element: " << s.top() << endl;
//     cout << "Size: " << s.size() << endl;

//     // Checking empty
//     if(s.empty())
//         cout << "\nStack is empty\n";
//     else
//         cout << "\nStack is NOT empty\n";

//     // Traversing stack (by copying)
//     stack<int> temp = s;

//     cout << "\nStack elements (top to bottom): ";
//     while(!temp.empty()) {
//         cout << temp.top() << " ";
//         temp.pop();
//     }

//     // SWAP example
//     stack<int> s2;
//     s2.push(100);
//     s2.push(200);

//     cout << "\n\nBefore swap:";
//     cout << "\nStack1 size: " << s.size();
//     cout << "\nStack2 size: " << s2.size();

//     s.swap(s2);

//     cout << "\n\nAfter swap:";
//     cout << "\nStack1 size: " << s.size();
//     cout << "\nStack2 size: " << s2.size();

//     return 0;
// }
//--------------------------------------------------------------------------------------------------------------------------
//OUTPUT
/* 

After pushing elements:
Top element: 40
 Size: 4

 After one pop:
 Top element: 30
 Size: 3

 Stack is NOT empty

 Stack elements (top to bottom): 30 20 10

 -----------------------------------------------------------------------------------------------------------------------------

swap() exchanges the entire contents of two stacks.
After swapping, each stack gets the other stack’s elements.

So:

s.swap(s2);

Everything inside s goes to s2

Everything inside s2 goes to s

No elements are copied one-by-one; the containers just exchange their internal data.
*/