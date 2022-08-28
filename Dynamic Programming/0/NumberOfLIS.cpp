#include<bits/stdc++.h>
using namespace std;

int main()
{
    // vector<int> arr={1,5,4,3,2,6,7,10,8,9};
    vector<int> arr={1,3,5,4,7};
    int n=arr.size();
    vector<int> dp(n,1); //kyuki length 1  to hogi km se km
    vector<int> cnt(n,1);
    int maxi=1;
    for(int i=0;i<n;i++)
    {
        for(int prev=0;prev<i;prev++)
        {
            // changed
            if(arr[prev]<arr[i] && 1+dp[prev]>dp[i])
            {
                dp[i]=1+dp[prev];
                // inherit
                cnt[i]=cnt[prev];
            }   
            else if(arr[prev]<arr[i] && 1+dp[prev]==dp[i])
            {
                // increase the count
                cnt[i]+=cnt[prev];
            }
        
        }
        maxi=max(maxi,dp[i]);    
    }
    cout<<endl;
    cout<<"length of largest LIS:- "<<maxi<<endl;
    int nums=0;
    for(int i=0;i<n;i++)
    {
        if(dp[i]==maxi) {nums+=cnt[i];}
    }
    cout<<"Number of LIS with length of max length LIS:- "<<nums<<endl;
    cout<<endl;
}