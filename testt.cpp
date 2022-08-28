#include<bits/stdc++.h>
using namespace std;

int bs(int start,int end,int num ,vector<int> &srt)
{
        int ans=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(srt[mid]<=num)
        {
            ans=srt[mid];
            start=mid+1;

        }
        else end=mid-1;

    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        vector<int> r(n);
        for(int i=0;i<n;i++)
        {
            cin>>r[i];
        }
        
        vector<int>srt=r;
        vector<int> v;
        sort(srt.begin(),srt.end());
        unordered_map<int,int> um;
        for(int i=0;i<srt.size();i++)
        {
            um[srt[i]]=i;
        }
        for(int i=0;i<r.size();i++)
        {
            int k=um[r[i]];
            int num=2*r[i];
            int a=bs(0,k-1,num,srt);
            int b=bs(k+1,r.size()-1,num,srt);

            int z=max(a,b);
            v.push_back(z);
        }
        cout<<"Case #"<<i<<":"<<" ";
        for(int i=0;i<r.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
        
        

        

    }
}