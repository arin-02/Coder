
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

int height(node*root)
{
    if(root==NULL) return 0;
    int left=height(root->left);
    int right=height(root->right);
    return 1+max(left,right);
}
// O(n^2)
// bool check(node* root)
// {
//     if(root==NULL) return true;
//     int lh=height(root->left);
//     int rh=height(root->right);
//     if(abs(lh-rh)>1) return false;
//     bool left=check(root->left);
//     bool right=check(root->right);
//     if(!left||!right) return false;
//     return true;
// }


// O(N)
bool check(node* root,int &height)
{
    if(root==NULL){
          
        height=0;
        return true;
    }
    int lh=0;
    int rh=0;
    bool left=check(root->left,lh);
    bool right=check(root->left,rh);

        height= 1+max(lh,rh);
        // cout<<height<<" ";
        if(abs(lh-rh)>1) return false;
        if(!left||!right) return false;
        return true;
    
}
int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->left->left->left = new node(7);
    
    cout<<height(root)<<endl;
    int height=0;
    cout<<check(root,height);
    cout<<endl;
    
    
}
