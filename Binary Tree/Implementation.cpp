//Implementation of Binary Tree 

#include <iostream>
#include <queue>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{ // since main fnction me starting me root = NULL h isliye yaha pe NULL hi pass hoga

    cout << "Enter the Data:" << endl;
    int data;
    cin >> data; // here we accept the data which we got from user

    root = new node(data); // here we call constructor and for root everything is initialised
                           //  yaha pe root ka value modify aur update ho jaaye
    if (data == -1)
    { // if we got -1 return from that position
        return NULL;
    }
    cout << "Enter the data for the left side of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data for the right side of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void LevelOrderTraversal(node *root)
{

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {

        node *temp = q.front();
        
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL); // aage wale numbers k liye
            }
        }
        else
        {
            cout << temp -> data <<" ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{

    node *root = NULL; // initialising root to NULL in starting

    root = buildTree(root); // building root while passing root which is NULL

    LevelOrderTraversal(root);

    return 0;
}

/*
🧠 Core idea

👉 Function ke andar jo root hai, wo “copy of pointer” hai
👉 Isliye function ke andar change karne se main ka root directly change nahi hota

But…
👉 Function naya address return karta hai
👉 Aur main usko wapas assign kar deta hai

🔁 Ek chhota sa real-life example

Socho:

Tumhare paas ek slip hai jisme address likha hai (ye root hai)
Tum slip kisi dost ko dete ho (function call)
Dost kya karta hai?
Purani slip fek deta hai
Nayi slip likh deta hai (new node ka address)
Tumhe wapas de deta hai

👉 Ab tum:

purani slip ki jagah nayi slip rakh lete ho
🔍 Code ke saath simple flow
Step 1: main()
node* root = NULL;
root = buildTree(root);

👉 Abhi:

root = NULL
Step 2: Function call
buildTree(root)

👉 Function ke andar:

root = NULL (copy aayi)
Step 3: New node ban gaya
root = new node(data);

👉 Ab:

root = address 1000 (example)
Step 4: Return
return root;

👉 Function bolta hai:

“ye lo naya address (1000)”
Step 5: Back to main
root = buildTree(root);

👉 Matlab:

root = 1000
💥 Final samajh

👉 Function ke andar change direct nahi hota
👉 Return ke through update hota hai

🎯 Ek line me yaad rakh

👉 “Function andar root banata hai, return karta hai, aur main usko pakad leta hai”

⚠️ Bonus (jo confusion hata dega)

Agar tum ye likhte:

buildTree(root);  // ❌ return assign nahi kiya sirf function likh diya

👉 Toh:

root = NULL hi rehta

💥 Kyunki tumne return value use hi nahi ki

🚀 Ultra simple summary
Step	Kya ho raha hai
Call	 : NULL pass hua
Inside	 : new node bana
Return	 : address mila
Assign	 : root update ho gaya

NORMAL ------------------LEVEL ORDER TRAVERSAL---------------------without printing in different levels---
---------------------same line me print karne k liye -----------------------------------------------------

void LevelOrderTraversal(node* root){

    queue <node*> q;
    q.push(root);

    while(!q.empty()){

        node* temp = q.front();
        cout << temp -> data <<" ";
        q.pop();

        if(temp -> left){
            q.push(temp -> left);
        }
        if(temp -> right){
            q.push(temp -> right);
        }
    }
}

use this as an input --> 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 

Remove all cout statements (except the print one in levelOrderTraversal) and it will work without asking for data again n again
*/
