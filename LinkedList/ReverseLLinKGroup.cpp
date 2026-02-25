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

        while (temp != NULL && cnt < k) {
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

