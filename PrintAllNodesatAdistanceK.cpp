#include<iostream>
#include<stack>
#include<vector>
#include<unordered_map>
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
// sbhse phelel parent track kro sbke... abh target node se required distance door tk ke saare vector mei daal lo
// target se k distance door tk nikalna hai 
void markparents(node* root,unordered_map<node*,node*> &parent_track,node* target)
{
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        node*x=q.front();
        q.pop();
        if(x->left)
        {
            parent_track[x->left]=x;
            q.push(x->left);
        }
        if(x->right)
        {
            parent_track[x->right]=x;
            q.push(x->right);
        }
    }

}
void printnodesatdistanceK(node* root, node* target,int k)
{
    unordered_map<node*,node*> parent_track;
    markparents(root, parent_track,target);

    unordered_map<node*,bool> visited;
    queue<node*> q;
    q.push(target);
    visited[target]=true;
    int currlevel=0;
    while(!q.empty()) 
    {
        
            int sz=q.size();

            if(currlevel==k) break;

            currlevel++;
            for(int i=0;i<sz;i++) {
            node*x=q.front();
            q.pop();
            if(x->left &&!visited[x->left]) {
                q.push(x->left);
                visited[x->left]=true;
            
            }
            if(x->right &&!visited[x->right]) {
                q.push(x->right);
                visited[x->right]=true;
            }
            if(parent_track[x]&&!visited[parent_track[x]])
            {
                q.push(parent_track[x]);
                visited[parent_track[x]]=true;
            }


        }

    }
    vector<int> res;
    while(!q.empty())
    {
        node*x=q.front();;
        q.pop();
        res.push_back(x->data);
    }
    for(int i=0; i<res.size(); i++)
    {
        cout<<res[i]<<" ";
    }
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(8);
    
    printnodesatdistanceK(root,root->left,1);
    
}
