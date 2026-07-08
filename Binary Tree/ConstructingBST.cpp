//CONSTRUCTING BST FROM DIFFERNT WAYS --> FROM INORDER , PREORDER AND POSTORDER TRAVERSAL

//BST CONSTRUCTION USING POSTORDER TRAVERSAL

class Solution {
  public:
    Node* insertIntoBst(Node* root, int val){
        
        if(root == NULL){
            root = new Node(val);
            return root;
        }
        
        if(val < root->data){
            root->left = insertIntoBst(root->left,val);
        }
        else{
            root->right = insertIntoBst(root->right,val);
        }
        return root;
    }
    Node* constructTree(vector<int>& post) {
        
        Node* root = NULL;
        
        int n = post.size();
        
        for(int i=n-1; i>=0; i--){
            root = insertIntoBst(root,post[i]);
        }
        
        return root;
    }
};

// POSTORDER ME ROOT LAST ME HOTA H ISLIYE PICHE SE VALUE INSERTION START KIYE H
