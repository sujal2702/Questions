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

void print(Node* &head){

    Node* temp = head;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp -> next;
    }
}

int main(){
    Node* node1 = new Node(10);
    
    cout << "Data: " << node1->data << endl;
    cout << "Next pointer: " << node1->next << endl;

    Node* head = node1; //head pointed to node 1;
    print(head);
    cout << endl;
    
    InsertAtHead(head , 12);
    InsertAtHead(head , 15);
    print(head);
    cout << endl;
    

    
    return 0;
}

//While Printing 

    //node already h  sirf print krna h to No Creation
    //since head ko move ya change nhi kr skte while printing LL disturb ho jayega
    //That's Why head pe bhi ek pointer laga do - temp naam ka
