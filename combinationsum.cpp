#include<iostream> 
#include<vector> 
using namespace std;

void print(vector<int> k)
{
    for(int i = 0; i < k.size(); i++)
    {
       cout<<k[i]<<" ";
    }
}
void combinationsum(int index,int arr[],vector<vector<int>> &ans,int target,vector<int> &v,int n)
{
    if(index==n)
    {
       if(target==0) 
       {
        print(v);
        cout<<endl;
       }

        
           
        return;
        
    }
    if(arr[index]<=target)
    {
    v.push_back(arr[index]);
    combinationsum(index,arr,ans,target-arr[index],v,n);
    v.pop_back();

    }
    combinationsum(index+1,arr,ans,target,v,n);


}

int main()
{
    int arr[]={2,7,3,6};
    int target=7;
    vector<int> v;
    vector<vector<int> > ans;
    int n=sizeof(arr)/sizeof(arr[0]);
    // int n=4;
    combinationsum(0,arr,ans, target,v,n);
    
    
    
}