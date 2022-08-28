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

node* lowestCommonAncestor(node* root,int x,int y)
{
    if(root==NULL||root->data==x||root->data==y)return root;

    node* left=lowestCommonAncestor(root->left,x,y);
    node* right=lowestCommonAncestor(root->right,x,y);
    if(left==NULL)
    {
        return right;
    }
    else if(right==NULL)
    {
        return left;
    }
    return root;
    
    
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

    node*x=lowestCommonAncestor(root,4,14);
    cout<<x->data<<endl;

    
}
