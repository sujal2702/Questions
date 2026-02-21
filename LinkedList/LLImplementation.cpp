#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //Constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
void InsertAtHead (Node* &head, int d){
    // insert krne se pehle Node create to karo
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void InsertAtTail(Node* &tail , int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

void print(Node* &head){

    Node* temp = head;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){
    Node* node1 = new Node(10);
    
    cout << "Data: " << node1->data << endl;
    cout << "Next pointer: " << node1->next << endl;

    Node* head = node1; //head pointed to node 1;
    Node* tail = node1; //at starting since there is only 1 node that's why same head & tail

    // print(head);
    // InsertAtHead(head , 12);
    // InsertAtHead(head , 15);
    // print(head);

    InsertAtTail(tail, 13);
    InsertAtTail(tail, 17);

    print(head);
    

    
    return 0;
}

//While Printing 

    //node already h  sirf print krna h to No Creation
    //since head ko move ya change nhi kr skte while printing LL disturb ho jayega
    //That's Why head pe bhi ek pointer laga do - temp naam ka