#include<iostream>
using namespace std;


void build(int node,int st,int en,int tree[],int a[])
{
    if(st==en)//leaf node
    {
        tree[node] = a[st];
        return ;
    }
    int mid=(st+en)/2;
    build(2*node,st,mid,tree,a);//left
    build(2*node+1,mid+1,en,tree,a);//right
    tree[node]=tree[2*node]+tree[2*node+1];
}
int main()
{
 int n=8;
 
  int a[]={5,3,2,4,1,8,6,10};
// for(int i=0;i<sz;i++)
// {
//     cin>>a[i];
// }
int tree[4*n];
 build(1,0,n-1,tree,a);
 for(int i=1;i<15;i++)
 {
cout<<tree[i]<<" ";
 }
}