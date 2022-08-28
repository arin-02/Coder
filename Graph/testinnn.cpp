#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> l,vector<int> r)
{
    vector<pair<int,int>> v;
    int k=r[0];
    for(int i=1;i<l.size();i++)
    {
        v.push_back({l[i],r[i]});

    }
    for(auto it:v)
    {
        
        if(it.first<k)return 0;
        else{
            k=it.second;
        }
    }
    return 1;
}

int main()
{
     vector<int> l={1,2,4};
     vector<int> r={2,3,5};
    cout<<solve(l,r);

}