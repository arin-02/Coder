#include<iostream>
#include<string>
#include<vector>
using namespace std;
// brute force
// phele set mei dalo fir duplicate gayab fir kisi vector mei dalo 
// slution:-optimize recursion itself

void subsetsumnoduplicate(int arr[],int n,vector<int> &v,int sum,int index)
{
    if(index>n)
    {

    }
    cout<<sum<<" "<<endl;
   

    for(int i=index;i<n;i++)
    {
        if(arr[i]==arr[i-1]) continue;
        subsetsumnoduplicate(arr,n,v,sum+arr[index],i+1);
        subsetsumnoduplicate(arr,n,v,sum,i+1);
    }
}
int main()
{

    int arr[]={1,2,2,2,3,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int> v;
    subsetsumnoduplicate(arr,n,v,0,0);
}