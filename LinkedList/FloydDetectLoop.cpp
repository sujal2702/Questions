#include<bits/stdc++.h>
using namespace std;

    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

    Node* floydDetectLoop(Node* head) {

    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast !=NULL) {
        
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast) {
            return slow;
        }
    }

    return NULL;

}

Node* getStartingNode(Node* head) {

    if(head == NULL) 
        return NULL;

    Node* intersection = floydDetectLoop(head);
    
    if(intersection == NULL)
        return NULL;
    
    Node* slow = head;

    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }  

    return slow;

}

Node *removeLoop(Node *head)
{
    if( head == NULL)
        return NULL;

    Node* startOfLoop = getStartingNode(head);
    
    if(startOfLoop == NULL)
        return head;
    
    Node* temp = startOfLoop;

    while(temp -> next != startOfLoop) {
        temp = temp -> next;
    } 

    temp -> next = NULL;
    return head;
}

// ---------------DETECT AND REMOVE LOOP USING SET---------------

/*
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void removeLoop(Node* head) {
        // code here
        set <Node *> st;
        Node* prev = NULL;
        Node* temp = head;
        
        while(temp != NULL){
        
        if(st.find(temp) == st.end()){ //mtlb nhi mila yaha sw
            st.insert(temp);
            //update head and prev
            prev = temp;
            temp = temp -> next;
            
        }
        
        // if this ends it means u are at repeated nodes
        else{
            prev -> next = NULL;
            return ; //AGAR Node* rha to return head
        }
        }
        // agar loop hua hi nhi to return head; void case me leave as it is
    }
};

// -----------------------IMPORTANT THING TO REMEMBER -------------------
                     /*    Simple mental rule

                             Loop ke baad:

                           fast == NULL → even  fast last node k aage NULL pe hoga

                            fast != NULL → odd   fast last wale node pe hoga 

-------------------------------------------------------------------------------------------------
----------------------- MIDDLE NODE RULE TO REMEMBER -------------------------------------------- */


slow = head;
fast = head->next;

while(fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
}

return slow;

/*


Simple Rule
fast = head;

👉 Jab tujhe middle node chahiye.

1 → 2 → 3 → 4 → 5
          ↑
        middle

For even list:

1 → 2 → 3 → 4
          ↑
       second middle

       
fast = head->next;
👉 Jab tujhe middle ke previous node chahiye — especially middle mein insertion ke liye.

1 → 2 → 3 → 4
    ↑
   slow

Then insert after slow:

1 → 2 → X → 3 → 4


Bas ye yaad rakh: --------- IMPORTANT ---------
    
fast = head->next →  slow ends at ----- first middle
fast = head → slow end at ----- second middle

For odd-sized lists, both generally end at the actual middle:

1 → 2 → 3 → 4 → 5
          ↑
        slow

That's why the difference becomes important mainly for even-sized linked lists.

*/
