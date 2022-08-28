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

void addleft(node* root,vector<int>& ans)
{
    if(!root) return;
    node*curr=root;
    while(curr)
    {
        if(curr->left!=NULL ||curr->right!=NULL)
        {
        ans.push_back(curr->data);

        }
        if(curr->left){curr=curr->left;}
        else{ curr=curr->right;}
    }

}
void addleaves(node* root,vector<int>& ans)
{
    if(!root) return;
    node*curr=root;
    if(curr->left==NULL &&curr->right==NULL)
    {
        ans.push_back(curr->data);
        
    }
    addleaves(root->left,ans);
    addleaves(root->right,ans);
    
}
void addright(node* root,vector<int> &ans)
{
    
    
    if(!root) return;
    node*curr=root;
    vector<int> v;
    while(curr)
    {
        if(curr->right!=NULL ||curr->left!=NULL)
        {
        ans.push_back(curr->data);

        }
        if(curr->right){curr=curr->right;}
        else{ curr=curr->left;}
    }

    for(int i=v.size()-1;i>=0;i++)
    {
        ans.push_back(v[i]);
    }
}
void boundarytraversal(node* root,vector<int>&ans)
{
    if(root==NULL)return;
    ans.push_back(root->data);
    addleft(root->left,ans);
    addleaves(root,ans);
    addright(root->right,ans);
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

    vector<int> ans;
    boundarytraversal(root,ans);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }

    
}
