#include<bits/stdc++.h>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

//--------------------REVERSE LINKED LIST IN K GROUPS-----------------------------
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // pehle NULL walo ko hata lo
        if (head == NULL) {
            return NULL;
        }

        // Step 1 : ab 1st k elements ko reverse karo
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;



        ListNode* temp = head; //check karo ki k elements hai bhi ki nhi agar nhi h to don't reverse
        int cnt = 0;

        while (temp != NULL && cnt < k) { //this loop is to check ki 'k' jitne elements present h bhi ki nhi // agar hai to normal procedure aur agar nhi phir to return head // return karo wahi element
                                                                                                                                       // taaki sirf k element ho to hi reversal ho wrna naa ho 
            temp = temp->next; 
            cnt++;
        }

        if (cnt < k)
            return head;

        cnt = 0;

        while (curr != NULL && cnt < k) {
            // Normal Reversal Code Iterative way
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }

        // Step 2: ab aage k parts k liye recursion call kar do aur sahi
        // position pe insert karo
        head->next = reverseKGroup(next, k);

        // step 3 : overall iss reverse linked list ka head previous part hoga
        return prev;
    }
};

/* NORMAL----------------- REVERSE LINKED LIST --------------------------------- */

   // ------------------------RECURSIVE APPROACH ------------------------------------------------
   
    void reverse(ListNode* &head, ListNode* prev, ListNode* curr){

        //base case // rukna kaha h?
        if(curr == NULL){
            head = prev;
            return ;
        }

        ListNode* forward = curr -> next;
        reverse(head , curr, forward);

        // wapas return k time 
        curr -> next = prev; // yahi main h jo return k time sahi connection krta h reverse me
    }
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;
        reverse(head , prev, curr);
        return head;

    // --------------ITERATIVE APPROACH ----------------------------------------------------------
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
