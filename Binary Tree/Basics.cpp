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

//Diameter of a tree with height // T.C. O(N^2)

class Solution {
  public:
  int height(Node* root) {
        
        if(root == NULL){
            return -1;
        }
        
        int left = height(root->left);
        int right = height(root->right);
        
        // ab ye wala part return aate wakt dekha jata h
        int ans = max(left,right)+1;
        return ans;
    }
    
    int diameter(Node* root) {
        // code here
        if(root == NULL){
            return 0;
        }
        
        int leftpart1 = height(root->left);
        int rightpart1 = height(root->right);
        int mid = height(root->left) + height(root->right)+2;
        
        int leftpart = diameter(root->left);
        int rightpart = diameter(root->right);
        
        int dia = max(leftpart ,max(rightpart , mid));
        return dia;
    }
};

//Diameter of a tree with height included in same pair // T.C. O(N)
