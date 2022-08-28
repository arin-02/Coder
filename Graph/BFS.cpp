#include<bits/stdc++.h>
using namespace std;
// TC O(n) ... SC O(n) ...
vector<int> bfsvec;
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
void bfs(vector<vector<int>> adj,vector<int> vis,int V,int E,int x)
{
    queue<int> q;
    q.push(x);
    vis[x]=1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        bfsvec.push_back(x);
        for(auto it:adj[x])
        {
            if(!vis[it])
            {

                q.push(it);
                vis[it]=1;
            }
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
        if(vis[i]==0)
        {
            bfs(adj,vis,V,E,i);
        }
    }
    for(int i=0;i<bfsvec.size();i++)
    {
       cout<<bfsvec[i] <<" ";
    }


}