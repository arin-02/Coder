#include <bits/stdc++.h>
#include<vector>
using namespace std;
typedef long long ll ;
int main() {
  int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ll a[n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        int tsum=0;
        for(int i=0; i<n-1; i++)
        {
            tsum+=a[i];
        }
        int ans=0;
        int firsti;
        for(int i=0; i<n; i++)
        {
            if(a[i]>0)
            firsti=i;
            break;
        }
        int count=0;
        for(int i=firsti+1; i<n-1; i++)
        {
            if(a[i]==0)count++;
        }
        tsum+=count;
        cout<<tsum<<endl;
    }
  


}
