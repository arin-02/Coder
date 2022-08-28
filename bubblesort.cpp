#include<iostream>

using namespace std;
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int main()
{
	int n=5;
	int arr[n];
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	//BUBBLE SORT
	for(int i=0;i<n;i++)
	{
		for (int j = 0; j < n-1-i; j++)
		{
			if(arr[j]>arr[j+1])
			{
				// int temp=arr[j];
				// arr[j] = arr[j+1];
				// arr[j+1] = temp;
				swap(&arr[j],&arr[j+1]);
			}
		}
		
	}
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" "<<endl;
	}
}