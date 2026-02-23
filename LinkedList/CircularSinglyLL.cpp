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

    if(tail == NULL){
        cout <<"Tail hi nhi h" <<endl;
        return ;
    }

    Node* temp = tail;

    do{
        cout << tail -> data <<" ";
        tail= tail -> next;
    }
    while(tail != temp);
    cout << endl;
}

void deleteNode(Node* &tail, int value){
    if(tail == NULL){
        //nothing to delete 
        return ;
    }
    else{
        //prev aur curr banao // aur prev curr k piche rhe islsiye prev ko tail pe rkho
        Node* prev = tail;
        Node* curr = prev -> next;

        //ab value dundho 
        while(curr ->data != value){
            prev = curr;
            curr = curr -> next;
        }
        // ab curr is pointing to value node
        // for 1 Node linked List curr , prev , tail sab usipe hoga 
       if(curr == prev){
         tail = NULL;
       }
       // for more than 2 node >=2 nodes
       if(curr == tail){
            tail = prev;
        }

        prev -> next = curr -> next;
         
        curr -> next = NULL;
        delete curr; 
    }
}

int main(){
    Node* tail = NULL;

    InsertAtPostion(tail, 5, 1);
    // print(tail);

    InsertAtPostion(tail ,1 ,2);
    // print(tail);

    InsertAtPostion(tail ,2 ,3);
    // print(tail); 

    InsertAtPostion(tail ,2, 4);
    print(tail);

    deleteNode(tail , 1);
    print(tail);

    deleteNode(tail , 2);
    print(tail);
   
    // deleteNode(tail , 1);
    // print(tail);
    

    return 0;
}

// code output overall
/*

1 2 4 3 
Memory freed for data 1
3 2 4
Memory freed for data 2
3 4

*/