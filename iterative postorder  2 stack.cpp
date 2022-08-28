
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

void printlevelorder(node* root)
{
    if(root==NULL)
    {
        return ;
    }
    node*temp=root;
    vector<int> v;
    stack<node*> s1;
    s1.push(root);
    stack<int> s2;
    while(!s1.empty())
    {
        node* x=s1.top();
        s1.pop();
        s2.push(x->data);
        if(x->left) s1.push(x->left);
        if(x->right) s1.push(x->right);
    }

    

    while(!s2.empty())
    {
        cout<<s2.top()<<" "<<endl;
        s2.pop();
    }
}


int main()
{
    node*root=new node(1);
    root->left=new node(2);
    root->right=new node(7);
    root->right->left=new node(8);
    root->left->left=new node(3);
    root->left->left->right=new node(4);
    root->left->left->right->right=new node(5);
    root->left->left->right->right->right=new node(6);
    
    printlevelorder(root);
    cout<<endl;
    
    
}
