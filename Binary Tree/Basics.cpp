// Easy level Questions of Binary Tree
/*
 With Respect to this given function
 Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
//Height of a Tree 

class Solution {
  public:
    int height(Node* root) {
      
        if(root == NULL){
            return 0;
        }
        
        int left = height(root->left);
        int right = height(root->right);
        
        int ans = max(left , right) + 1;
        return ans;
    }
};

