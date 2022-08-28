#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ans=0;
    int maxi=0;
       for(int i=0; i<=n;i++)
       {
            if(i-1>=a[i] && n-i<=b[i])
            {
                ans++;
                maxi=max(ans,maxi);
            }
            else
            {
                ans=0;
            }
       }
}