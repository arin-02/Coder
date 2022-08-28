#include<iostream>
#include<stack>
#include<vector>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
    public:
            node(int val)
            {
                data=val;
                left=NULL;
                right=NULL;
            }
};

void deleteBST(node* root)
{
    
}
void inorder(node* root)
{
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    struct node* root = new node(6);
    root->left = new node(3);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right= new node(8);
    root->right->left= new node(7);

    inorder(root);
    deleteBST(root);
    cout<<endl;
    inorder(root);

   
    
}
