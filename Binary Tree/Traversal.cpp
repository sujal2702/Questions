// LevelOrderTraversal Has already been covered in Implementation.cpp file 
//Here we will see Inorder Preorder Postorder traversal

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node* left;
    node* right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* buildTree(node* root)
{
    int data;
    cin >> data;

    if (data == -1)
        return NULL;

    root = new node(data);

    root->left = buildTree(root->left);
    root->right = buildTree(root->right);

    return root;
}

// Inorder: Left -> Node -> Right
void inorder(node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


int main()
{
    node* root = NULL;

    cout << "Enter tree data :" << endl; //(-1 for NULL)
    root = buildTree(root);

    cout << "\nInorder Traversal: ";
    inorder(root);

    

    cout << endl;

    return 0;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
}

