#include<iostream>
#include<string>
#include<vector>
using namespace std;


void subsetsum(int arr[],int n,int sum,int index)
{
    if(index>n-1)
    {
        cout<<sum<<" ";
        return;
    }
    sum+=arr[index];
    subsetsum(arr,n,sum,index+1);
    sum-=arr[index];
    subsetsum(arr,n,sum,index+1);
    /*
    
    ya direct aise likho

    subsetsum(arr,n,sum+=arr[index],index+1);
    subsetsum(arr,n,sum,index+1);
    */
}
int main()
{
    int arr[]={3,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);

    subsetsum(arr,n,0,0);

}