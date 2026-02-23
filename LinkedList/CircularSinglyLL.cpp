#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }

    ~Node(){
        int value = this -> data ;
        while(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout <<"Memory freed for data " << value <<endl;
    }
};

void InsertAtPostion(Node* &tail , int element , int d){
    //if LL is empty
    if(tail == NULL){
        Node* temp = new Node(d);
        temp -> next = temp;
        tail = temp;

    }
    else{

    //ab element search karke curr uspe point karo aur current k aage element dalo 
    Node* curr = tail ; //qki sirf tail hi available hai

    while(curr->data != element){
        curr = curr -> next;
    }

    //ab current = element ko point kar rha hoga 
    //node create karo aur General solution likho 
    Node* temp = new Node(d);
    temp -> next = curr -> next;
    curr -> next = temp;
 }
}

void print(Node* tail){
    Node* temp = tail;
    do{
        cout << tail -> data <<" ";
        tail= tail -> next;
    }
    while(tail != temp);
    cout << endl;
}
int main(){
    Node* tail = NULL;

    InsertAtPostion(tail, 5, 1);
    // print(tail);

    InsertAtPostion(tail ,1 ,2);
    // print(tail);

    InsertAtPostion(tail ,2 ,3);
    print(tail); 

    InsertAtPostion(tail ,2, 1);
    print(tail);

    return 0;
}