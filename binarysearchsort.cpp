#include<bits/stdc++.h>
using namespace std;

// array should be sorted
// O(log(n))
int bst(int arr[],int n,int data)
{
 int l=0;
    int r=n-1;
while(l<r)
    {

    int mid=(l+r)/2;
        if(data==mid) return mid;
        else if(data>mid) l=mid+1;
        else r=mid-1;

    }
    return -1;

}
int main()
{

    int n=5;
    int arr[n];
    for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}

    int data=54;
   
    int m=bst(arr,n,data);
    cout<<arr[m];
    
}