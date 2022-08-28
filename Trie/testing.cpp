#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> v(n,vector<int> (2));
        for(int i=0;i<n;i++)
        {
            vector<int> vvv;
            int a,b;
            cin>>a>>b;
            vvv.push_back(a);
            vvv.push_back(b);
            v.push_back(vvv);

        }
        
    }   
}