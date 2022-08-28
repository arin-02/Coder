#include<bits/stdc++.h>
using namespace std;
// TC O(n) ... SC O(n) ...
vector<int> dfsvec;
void printgraph(vector<vector<int>> adj,int V,int E)
{
    for(int i=1;i<=V;i++)
    {
        cout<<i<<"->";
        for(auto it:adj[i])
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
}
bool cyclebfs(vector<vector<int>> adj,vector<int> vis,int V,int E,int x)
{
     queue<pair<int,int> >q;
    q.push({x,-1});
    vis[x]=1;
    while(!q.empty())
    {
        int y=q.front().first;
        int prev=q.front().second;
        q.pop();
        
        for(auto it:adj[y])
        {
            if(!vis[it] )
            {
                vis[it]=true;
                q.push({it,y});
                
            }
            else if(prev!=it){

                return true;

            }
        }
        
    }
    return false;


}
int main()
{
    int V,E;
    cin>>V>>E;
    // V=11,E=20
    // 1 based indexing

    //    vector<int> adj[V+1];
       vector<vector<int>> adj(V+1,vector<int>());
       for(int i=1;i<=E;i++)
       {
        int x,y;
        cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
       }
// V=11,E=20
// 11
// 20
// 1 2
// 2 1
// 2 4
// 3 5
// 4 2
// 5 3
// 5 10
// 5 16
// 6 5
// 6 7
// 7 6
// 7 8
// 8 7
// 8 9
// 8 11
// 9 10
// 9 8
// 10 5
// 10 9
// 11 8

    //    printgraph(adj,V,E);

    // as 1 based indexing so for loop 1 se lgaenge us number tk .. 
    // kyuki disconnected hai
    vector<int> vis(V+1,0);
    bool check = false;
    // 0 se us number tk vis array
    for(int i=1;i<=V;i++)
    {
        if(!vis[i])
        {
            if(cyclebfs(adj,vis,V,E,i) && !vis[i])
            {
                check=true;
            }
        }
    }
    if(check)
    {
        cout<<"CYCLE POSSIBLE"<<endl;
    }
    else
    {
        cout<<"NO CYCLE POSSIBLE"<<endl;
    }
   


}