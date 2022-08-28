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
    
       if(target==0) 
       {
        print(v);
        cout<<endl;
        return;
       }

    for(int i = index; i <n; i++)
    {
        if(i>index && arr[i]==arr[i-1]) continue;
        if(arr[i]<=target){
            
        v.push_back(arr[i]);
    combinationsum(i+1,arr,ans,target-arr[i],v,n);
    v.pop_back();

        }
    }
    


}

int main()
{
    int arr[]={1,1,1,2,2};
    int target=4;
    vector<int> v;
    vector<vector<int> > ans;
    int n=sizeof(arr)/sizeof(arr[0]);
    // int n=4;
    combinationsum(0,arr,ans, target,v,n);
    
    
    
}