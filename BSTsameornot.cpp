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

bool isSameBST(node* root1,node* root2)
{
    if(root1==NULL ||root2==NULL)
    {
        if(root1==root2) return true;
        return false;
    }
    
    bool a=isSameBST(root1->left,root2->left);
    bool b=isSameBST(root1->right,root2->right);

    if( a==1 && b==1 &&root1->data==root2->data) {
        return true;
    }

    return false;
}

int main()
{
    struct node* root1 = new node(-10);
    root1->left = new node(9);
    root1->right = new node(20);
    root1->right->left = new node(15);
    root1->right->right = new node(7);

    struct node* root2 = new node(-10);
    root2->left = new node(9);
    root2->right = new node(20);
    root2->right->left = new node(15);
    root2->right->right = new node(7);
    
    cout<<isSameBST(root1, root2);

    
}
