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

// bht saare case ho skte hai lekin hum leaf node pe hee lgaenge ,,, to isliye humara new node leaf node pe hee lgega....
// TIME COMPLEXITY:- O(log(n))

node* insertnode(node* root,int val)
{
    if(root==NULL) return NULL;
    node* curr=root;
    while(true)
    {
        if(curr->data<=val)
        {
            if(curr->right!=NULL){curr=curr->right;}
            else
            {
                curr->right=new node(val);
                break;
            }
        }
        else
        {
            if(curr->left!=NULL){curr=curr->left;}
            else
            {
                curr->left=new node(val);
                break;
            }
        }
    }
    return root;
}
void inorder(node* root)
{
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    struct node* root = new node(6);
    root->left = new node(3);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right= new node(8);
    root->right->left= new node(7);

    inorder(root);
    insertnode(root,5);
    cout<<endl;
    inorder(root);

   
    
}
