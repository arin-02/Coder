#include<iostream>
using namespace std;

// worst n^2
// avg nlogn
void swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void merge(int arr[],int n,int lb,int mid,int ub)
{

    int i=lb;
    int j=mid+1;
    int k=0;
    int brr[n];
    while(i<=mid && j<=ub)
    {
        if(arr[i]<=arr[j])
        {
            brr[k]=arr[i];
            i++;
            k++;
        }
        else 
        {
            brr[k]=arr[j];
            j++;
            k++;
        }
    }
    if(i>mid)
    {
        while(j<=ub)
        {
            brr[k]=arr[j];
            j++;
            k++;

        }
    }
    else{
        while(i<=mid)
        {
            brr[k]=arr[i];
            
            i++;
            k++;

        }
    }
    for(int m=lb;m<=ub;m++)
    {
        arr[m]=brr[m-lb];
    }

}
void mergesort(int arr[],int n,int lb,int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        mergesort(arr,n,lb,mid);
        mergesort(arr,n,mid+1,ub);
        merge(arr,n,lb,mid,ub);
    }
}
int main()
{
    int n=9;
    int arr[]={15,5,24,8,1,3,16,10,20};
    int lb=0;
    int ub=n-1;
    mergesort(arr,n,lb,ub);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}