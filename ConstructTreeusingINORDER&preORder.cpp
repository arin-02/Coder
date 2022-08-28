#include<iostream>
#include<stack>
#include<vector>
#include<map>
#include<queue>
#include<math.h>
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

node* building(vector<int>&preorder,int prestart,int preend,vector<int>&inorder,int instart,int inend,map<int,int>&m)
{
    if(prestart>preend||instart>inend)
    { 
        return NULL;
    }
    node* root=new node(preorder[prestart]);

    int indexofroot=m[root->data];

    int leftnums=indexofroot-instart;
 
    root->left=building(preorder,prestart+1,preend+leftnums,inorder,instart,indexofroot-1,m);

    root->right=building(preorder,prestart+leftnums+1,preend,inorder,indexofroot+1,inend,m);

}
node* buildtree(vector<int>&inorder,vector<int>&preorder)
{
    map<int,int> m;
    for(int i=0;i<inorder.size();i++)
    {
        m[inorder[i]]=i;
    }
    node*root=building(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,m);

}

int main()
{
    
     vector<int> inorder={9,3,15,20,7};
    vector<int> preorder={3,9,20,15,7};
    
}
