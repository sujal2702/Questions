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

void InsertAtPosition(Node* &head, Node* &tail, int position, int d){

   //Insert At Start
    if(position == 1){  //agar 1st me insert krna ho to 

    InsertAtHead(head , d);
    return;
   }

   Node* temp = head;


   int count = 1; // taki traverse kar ske ek piche tak jaha insert krna h uske
   
   Node* NodeToInsert = new Node(d);
   while(count < position - 1){ 
    temp = temp -> next;
    count++;
   }

   //Insert At End
   if(temp -> next == NULL){

    InsertAtTail(tail , d);
    return ;
   }
   
   //Now we are just 1 node behind where we need to insert
   NodeToInsert -> next = temp -> next;
   temp -> next = NodeToInsert;

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

    print(head);
    // InsertAtHead(head , 12);
    // InsertAtHead(head , 15);
    // print(head);

    InsertAtTail(tail, 13);
    InsertAtTail(tail, 17);

    print(head);

    InsertAtPosition(head , tail, 1, 22);
    InsertAtPosition(head , tail, 1, 30);
    InsertAtPosition(head , tail, 4, 90);
    InsertAtPosition(head , tail, 6, 40);
    InsertAtPosition(head, tail, 7, 50);
    InsertAtPosition(head, tail, 9, 100);

    print(head);
    

    
    return 0;
}

//While Printing 

//node already h  sirf print krna h to No Creation
//since head ko move ya change nhi kr skte while printing LL disturb ho jayega
//That's Why head pe bhi ek pointer laga do - temp naam ka

// while(count < position - 1) 

// becuase we are doing count++ inside h to agar hamara position 3 h to hame 2 tak jana h aur agar count < position  rkhenge to 2<3 wala condition satisfy ho jayega aur while loop ek baar aur chalega mtlb count++ ho jayega aur count = 3 hi ho jayega instead of 2 isliye ye while condition hi sahi h

//overall output ye ayegga  -------->>> 30 22 10 90 13 40 50 17 100
