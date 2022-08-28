// single component bipartite graph
#include<bits/stdc++.h>
using namespace std;

bool bipartiteGraphBFS( vector<vector<int>>&adj,vector<int> &color,int x)
{
    color[x]=0;
    // vis[x]=1;
    queue<int> q;
    q.push(x);
    while(!q.empty())
    {
        int y=q.front();
        q.pop();
        for(auto it:adj[y])
        {
            if(/*!vis[it]&& */  color[it]==-1)
            {
                // vis[it]=1;
                // color[it]=!color[y];
                // OR
                color[it]=1-color[y];
                q.push(it);
            }
            else if(/*vis[it] && */ color[it]==color[y])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int V,E;
    cin>>V>>E;
    vector<vector<int>> adj(V,vector<int>());
    // vector<int> vis(V,0);
    vector<int> color(V,-1);
    // 0 based indexing
    for(int i=0;i<E;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }   
    // <MULTIPLE component ho to for loop>
    bool f=true;
    // 0 based indexing
    for(int i=0;i<V;i++)
    {
        if(color[i]==-1)
        {
            if(!bipartiteGraphBFS(adj,color,i))
            {
                f=false;
            }
        }
    }
    
    if(f)
    {
        cout<<"POSSIBLE "<<endl;
    }
    else
    {
        cout<<"NOT POSSIBLE"<<endl;
    }
}
// 4
// 5
// 0 1
// 1 2
// 2 0
// 2 3
// 3 0

// 4
// 4
// 0 1
// 1 2
// 2 3
// 3 0