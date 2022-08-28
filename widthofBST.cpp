#include<iostream>
#include<stack>
#include<vector>
#include<queue>
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

int widthofBst(node* root,int &width)
{
    if(!root) return 0;

    int ans=0;
    queue<pair<node*,int>> q;
    q.push({root,0});
    while(!q.empty())
    {
        // 0 based indexing
        int sz=q.size();    
        int mini=q.front().second;
        int start,last;
        for(int i=0;i<sz;i++)
        {
            int curr=q.front().second- mini;
            
            node*x=q.front().first;
            
            q.pop();
            if(i==0)start=curr;
            if(i==sz-1)last=curr;
            if(x->left)
            {
                q.push({x->left, (curr*2)+1});
            }
            if(x->right)
            {
                q.push({x->left, (curr*2)+2});

            }

        }
        width=max(width,last-start+1);


    }

}
int main()
{
    struct node* root = new node(-10);
    root->left = new node(9);
    root->right = new node(20);
    root->right->left = new node(15);
    root->right->left = new node(7);
    
    int width=0;
    widthofBst(root,width);
    cout<<width<<" ";
    
}
