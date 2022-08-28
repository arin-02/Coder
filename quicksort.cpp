#inc lude<bits/stdc++.h>
using namespace std;

// worst n^2
// avg nlogn
void swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
int partition(int arr[],int lb,int ub)
{
    int pivot=arr[lb];
    int start=lb;
    int end=ub;
    while(start<end)
    {
        while(arr[start]<=pivot)
        {
            start++;
        }
        while(arr[end]>pivot)
        {
            end--;
        }
        if(start<end)
        {
        swap(&arr[start],&arr[end]);

        }
    }
    swap(&arr[lb],&arr[end]);
    return end;

}
void quicksort(int arr[],int n,int lb,int ub)
{
    if(lb<ub)
    {
    int loca=partition(arr,lb,ub);
    quicksort(arr,n,lb,loca-1);
    quicksort(arr,n,loca+1,ub);

    }
} 
int main()
{
    int n=9;
    int arr[]={7,6,10,5,9,2,1,15,7};
    int lb=0;
    int ub=n-1;
    quicksort(arr,n,lb,ub);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}