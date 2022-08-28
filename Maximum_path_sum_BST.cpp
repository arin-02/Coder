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

int maximumpathsum(node *root,int &maxi)
{
    if(root==NULL) return 0;
    int ldata=maximumpathsum(root->left,maxi);
    int rdata=maximumpathsum(root->right,maxi);
    maxi=max(maxi,ldata+rdata+root->data);
    return root->data+max(ldata,rdata);
}
int main()
{
    struct node* root = new node(-10);
    root->left = new node(9);
    root->right = new node(20);
    root->right->left = new node(15);
    root->right->right = new node(7);
    
    int maxi=0;
    maximumpathsum(root,maxi);
    cout<<maxi<<endl;
    
}
