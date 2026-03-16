#include<iostream>
using namespace std;

class Node{
   
    public:
    int data;
    Node* next;

    //Constructor
    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }

};

class Stack{

    public:
    Node* top;

    //Constructor
    Stack(){
        top = NULL; //is to initialize the stack as empty
    }

    //pushing an element in linked list which is like stack
    void push(int element){

    //first create a node
    Node* temp = new Node(element);

    if(temp == NULL){
        cout <<"Stack Overflow" <<endl; //just to ensure the memory is allocated or not
        return;
    }

    //hamlog generally insertAtHead karte h stack banane or maintain krne k liye
    temp -> next = top;
    top = temp;
  }

  void pop(){ //in this we remove the element which is newly inserted LIFO (because we want stack behaviour)                
                                                             // to remove from Head hi karna hoga.
    if(top == NULL){
        cout <<"Stack Underflow" <<endl;
        return;
    }

    // aur agar empty nhi hua to 
    Node* temp = top; //top pe temp rkho
    top = top -> next;
    delete temp;

  }

  int peek(){ //because when peek is called we need to return a value

    if(top != NULL){
        return top -> data;
    }
    else{
        cout<< "Stack is Empty" << endl;
        return -1;
    }
  }

  bool isEmpty(){

    if(top == NULL){
        return true;
    }
    else{
        return false;
    }
  }

};

int main(){

     Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.peek() << endl;

    s.pop();
    cout << "Top element after pop: " << s.peek() << endl;

    if(s.isEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }

    return 0;
}




