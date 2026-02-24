#include<bits/stdc++.h>
using namespace std;

//Converting from Linked List to array

vector<int> linkedListToArray(Node* head) {

    vector<int> arr;
    ListNode* temp = head;

    while(temp != NULL){
        arr.push_back(temp->val);
        temp = temp->next;
    }

    return arr;
}
