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

void changeTree(node*root)
{
    if(root==NULL) return ;
    int child=0;
    if(root->left)
    {
        child+=root->left->data;
    }
    if(root->right)
    {
        child+=root->right->data;
    }
    if(child>=root->data) root->data=child;
    else{
        if(root->left) root->left->data=root->data;
        else if(root->right) root->right->data=root->data;
    }
    changeTree(root->left);
    changeTree(root->right);
    int total=0;
    if(root->left) total+=root->left->data;
    if(root->right) total+=root->right->data;
    if(root->left || root->right) root->data=total;
}
void inorder(node* root)
{
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}

int main()
{
    struct node* root = new node(20);
    root->left = new node(8);
    root->left->left = new node(4);
    root->left->right = new node(12  );
    root->left->right->left = new node(10 );
    root->left->right->right = new node(14  );
    root->right= new node(22);
    root->right->right= new node(25);

    inorder(root);
    changeTree(root);
    cout<<endl;
     inorder(root);
    
}
