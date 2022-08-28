// phele increase fir decreasing aisi sequence ...longest length return krni fir
// ya fir sirf increasing ho vo bhi bitonic hoti hai
// ya fir sirf decreasing ho vo bhi bitonic hoti hai
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


int main()
{

    vector<int> arr={1,11,2,10,4,5,2,1};
    int n=arr.size();
    vector<int> dp1(n,1);
   
    for(int i=0;i<n;i++)
    {
        for(int prev=0;prev<i;prev++)
        {
            if(arr[prev]<arr[i] && 1+dp1[prev]>dp1[i])
            {
                // dp1[i]=max(dp1[i],1+dp1[prev]);
                dp1[i]=1+dp1[prev];
            }
        }
        // maxi=max(maxi,dp1[i]);
    }


    vector<int> dp2(n,1);
    // IMPORTANT LINE
    reverse(arr.begin(),arr.end());

    for(int i=0;i<n;i++)
    {
        for(int prev=0;prev<i;prev++)
        {
            if(arr[prev]<arr[i]&& 1+dp2[prev]>dp2[i])
            {
                // dp2[i]=max(dp2[i],1+dp2[prev]);
                dp2[i]=1+dp2[prev];
            }
        }
        // maxi=max(maxi,dp2[i]);
    }
    int maxi=0;
    for(int i=0; i<n;i++)
    {
        maxi=max(maxi,dp1[i]+dp2[i]-1);
    }
    cout<<maxi<<endl;

   

    
}