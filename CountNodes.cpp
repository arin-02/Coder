#include<iostream>
#include<stack>
#include<vector>
#include<unordered_map>
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

//  2^height-1 ye aaenge number of nodes if (left height)==(right height)
int countnodes(node* root,int &count,int &height)
{
    if(root==NULL) return 0;
    int lh=countnodes(root->left,count,height);
    int rh=countnodes(root->right,count,height);
    height=1+max(lh,rh);
    if(lh==rh)
    {
        count+=pow(2,height)-1;
    }
    return 1+lh+rh;
}


int main()
{
    struct node *root = new node(2);
    root->left     = new node(7);
    root->right     = new node(5);
    root->left->right = new node(6);
    root->left->right->left = new node(1);
    root->left->right->right = new node(11);
    root->right->right = new node(9);
    root->right->right->left = new node(4);
    int count=0;
    int height=0;
    cout<<countnodes(root,count,height);
    
}
