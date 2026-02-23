#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* prev;
    Node* next;

    Node(int d){ //constructor
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }

    ~Node(){
        int value = this -> data;
        while(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout <<"Memory freed with extra space "<< value <<endl;
    }
};

void print (Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data << " " ;
        temp = temp -> next;
    }
    cout << endl;
}


int getLength (Node* head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}

void InsertAtHead(Node* &head ,Node* &tail, int d){
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}

void InsertAtTail(Node* &tail, Node* &head, int d){

    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
        Node* temp = new Node(d);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
}

void InsertAtPosition(Node* &head, Node* &tail, int d, int position){

    if(position == 1){ 
        InsertAtHead(head , tail, d);
        return ;
    }

    //pehle ek node piche tak traverse kro 
    Node* temp = head;
    int count = 1;
    while(count < position-1){
        temp = temp -> next;
        count++;
    }

    //temp sahi jagah pe hoga 1 behind jaha insert krna h uske 
    if(temp -> next == NULL){ // Iska Mtlb Last node par h
        InsertAtTail(tail, head, d);
        return ;
    }

    //ye h middle insertion ka actual case
    Node* NodeToInsert = new Node(d);

    NodeToInsert -> next = temp -> next;
    temp -> next -> prev = NodeToInsert;
    temp -> next = NodeToInsert ;
    NodeToInsert -> prev = temp;
    
}

void deleteAtPosition(Node* &head , int position){
    //1st node deletion
    if(position == 1){
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
        return ;
    }

    //if position is other than 1 // means last or middle one then fisrt traverse
    // make one prev and one curr node and point curr to which we need to delete
    Node* prev = NULL;
    Node* curr = head;

    int count = 1;
    while(count < position){
        prev = curr;
        curr = curr -> next;
        count++;
    }
    //now curr is on node which we need to delete 
    prev -> next = curr -> next;
    curr -> prev = NULL;
    if(curr -> next != NULL){
        curr -> next -> prev = prev;
    }
    curr -> next = NULL;
    delete curr;
}

int main(){
    // Node* node1 = new Node(10); //created 1st node

    Node* head = NULL; //head also pointing to node1 :: 1st node
    Node* tail = NULL;

    // print(head); 

    // cout << "Length of the Linked List is "<<getLength(head) << endl;

   InsertAtHead(head ,tail, 20);
   InsertAtHead(head,tail, 40);
   InsertAtTail(tail,head, 30);
   InsertAtTail(tail,head, 70);
   InsertAtPosition(head , tail, 50, 3);

   print(head);

   deleteAtPosition(head , 1);
   print(head);

   deleteAtPosition(head , 4);
   print(head);

   deleteAtPosition(head , 2);
   print(head);

    return 0;
} 

//40 20 50 30 70 
// Memory freed with extra space 40
// 20 50 30 70 
// Memory freed with extra space 70
// 20 50 30 
// Memory freed with extra space 50
// 20 30 

/*NOTE :  The destructor is written in such a way that if u don't make the node -> next = NULL (the node which u need to delete it's next shoud be NULL OtherWise it will DELETE THE ENTIRE LINKED LIST)
because we wrote the code of recusrive deletion  in ~Node() Destructor */
