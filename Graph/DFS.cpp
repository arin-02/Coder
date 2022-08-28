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
void dfs(vector<vector<int>> adj,vector<int> vis,int V,int E,int x)
{
    dfsvec.push_back(x);
    vis[x]=1;
    for(auto it:adj[x])
    {
        if(!vis[it])
        {
            // vis[it]=1;
            dfs(adj,vis,V,E,it);
        }
    }

}
int main()
{
    int V,E;
    cin>>V>>E;
    // V=7,E=6
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
// 7
// 6
// 1 2
// 2 3
// 3 5
// 4 6
// 7 2
// 7 5
    //    printgraph(adj,V,E);

    // as 1 based indexing so for loop 1 se lgaenge us number tk .. 
    // kyuki disconnected hai
    vector<int> vis(V+1,0);
    // 0 se us number tk vis array
    for(int i=1;i<=V;i++)
    {
        if(!vis[i])
        {
            dfs(adj,vis,V,E,i);
        }
    }
    for(int i=0;i<dfsvec.size();i++)
    {
       cout<<dfsvec[i] <<" ";
    }


}