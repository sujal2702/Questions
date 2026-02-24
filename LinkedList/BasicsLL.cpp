#include<bits/stdc++.h>
using namespace std;

//Converting from Linked List to array

vector<int> linkedListToArray(ListNode* head) {

    vector<int> arr;
    ListNode* temp = head;

    while(temp != NULL){
        arr.push_back(temp->val);
        temp = temp->next;
    }

    return arr;
}

//Convert Array Into Linked List

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



