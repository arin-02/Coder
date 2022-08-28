#include<iostream>
using namespace std;

int main()
{
    // find max aur minimum sum of subarray of size k
    int arr[]={2,5,1,8,2,9,1};
    int n=7;
    int k=3;
    int i=0,ans=0;
    int j=0,sum=0;

    while(j<n)
    {
        sum+=arr[j];
        if(j-i+1<k)
        {
            j++;

        }
        else if(j-i+1==k) {
      
            ans=max(ans,sum);
            sum-=arr[i];
            i++;
            j++;
        }
       

        

    }
    cout<<ans<<endl;

}