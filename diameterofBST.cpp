
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

// int height(node* root)
// {
//     if(root==NULL) return 0;
//     int lh=height(root->left);
//     int rh=height(root->right);
//     return 1+max(lh, rh);
// }
// diameter mtlbh edges dekho nodes se nhi
// iski time complexity O(n^2) hai abh height function bhi diameter ke andr nikalo for O(n)
// int diameter(node*root)
// {
//     if(root==NULL) return 0;
//     int ld=diameter(root->left);

//     int lh=height(root->left);
//     int rh=height(root->right);

//     int rd=diameter(root->right);
//     return max(1+lh+rh,max(ld,rd));

// }



// O(n)
int heightfordiameter(node*root,int &diameter)
{
if(root==NULL) return 0;
  
    int lh=heightfordiameter(root->left,diameter);
    int rh=heightfordiameter(root->right,diameter);
    diameter=max(diameter,lh+rh);
    return 1+max(lh,rh);


}
int main()
{
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->right->left = new node(4);
    root->right->left->left = new node(5);
    root->right->left->left->left = new node(9);
    root->right->right = new node(6);
    root->right->right->right = new node(6);
    root->right->right->right->right = new node(6);
    int diameter=0;
    heightfordiameter(root,diameter);
    cout<<diameter;
    
    
    
}
