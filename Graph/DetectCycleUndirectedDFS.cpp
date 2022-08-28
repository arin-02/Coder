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
bool cycledfs(vector<vector<int>> adj,int parent,vector<int> vis,int V,int E,int x)
{
    
    vis[x]=1;
        parent=x;
    for(auto it:adj[x])
    {
        if(!vis[it])
        {
            if(cycledfs(adj,parent,vis,V,E,it))return true;
        }
        if(vis[it] && parent!=it)return true;

    }
    return false;

}
int main()
{
    int V,E;
    cin>>V>>E;
    // V=8,E=7
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
// V=8,E=7
// 8
// 7
// 1 3
// 3 4
// 2 5
// 5 8
// 8 7
// 5 6
// 7 6


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
            if(cycledfs(adj,-1,vis,V,E,i) && !vis[i])
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