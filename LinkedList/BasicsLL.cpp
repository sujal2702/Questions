#include<bits/stdc++.h>
using namespace std;

// Define ListNode structure
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
//-----------------------IGNORE ABOVE THIS ---------------------------------------

//----------------------------------Converting from Linked List to array -----------------------------------------

vector<int> linkedListToArray(ListNode* head) {

    vector<int> arr;
    ListNode* temp = head;

    while(temp != NULL){
        arr.push_back(temp->val);
        temp = temp->next;
    }

    return arr;
}

//-----------------------Convert Array Into Linked List-----------------

ListNode* arrayToLinkedList(vector<int>& arr) {

    if(arr.size() == 0) return NULL;

    // Create head
    ListNode* head = new ListNode(arr[0]); //pehle 1st element create kar lo 
    ListNode* curr = head;                // aur head point kar do uspe

    for(int i = 1; i < arr.size(); i++){
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }

    return head;
}

//------------------------------Concept of slow and fast pointers - Example: Finding middle of linked list------------------
ListNode* findMiddle(ListNode* head) {
    
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;          // +1 step
        fast = fast->next->next;    // +2 steps
    }

    // When the loop ends, slow is at the middle.
    return slow;
}

//Reverse a LL Using Iterative Normal Approach

// --------------ITERATIVE APPROACH ----------------------------------------------------------
ListNode* reverseList(ListNode* head) {
        if(head == NULL || head -> next == NULL){ //0 OR 1 NODE CASE
            return head;
        } 
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev; // since prev = curr and curr = forward aur forward NULL pe tha 
                   // isliye curr bhi NULL ho jayega
}

//--------------------------Remove Duplicate from a sorted linked list -------------------------------

//---------THE MAIN REASON TO PUT THIS CODE IS TO SHOW HOW THE NODES ARE ADJUSTED WHEN U DELETE A NODE

    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* temp = head;
        while(temp != NULL && temp -> next != NULL){

            if(temp ->val == temp -> next -> val){

                ListNode* next_next = temp -> next -> next; //store kr lo taki LL lost na ho jaye
                ListNode* NodeToDelete = temp -> next; //duplicate next ko delete kar do
                delete NodeToDelete; //delete function
                temp-> next = next_next; // phir stored address use krlo  
                                        // temp k next ko point karane k liye
            }
             else{
                    temp = temp -> next;
                }
        }
        return head;
    }