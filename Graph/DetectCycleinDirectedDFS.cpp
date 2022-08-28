
// single component bipartite graph
#include<bits/stdc++.h>
using namespace std;

bool cycleDirectedDfs( vector<vector<int>>&adj,vector<int> &vis,vector<int> &dfsvis,int x)
{
    vis[x]=1;
    dfsvis[x]=1;
    for(auto it:adj[x])
    {
        if(!vis[it])
        {
            
            if(cycleDirectedDfs(adj,vis,dfsvis,it))return true;
        
        }
        else if(dfsvis[it]==1)
        {
            return true;
        }
    }
    dfsvis[x]=0;
    return false;
}


int main()
{
    int V,E;
    cin>>V>>E;
    vector<vector<int>> adj(V,vector<int>());
    // vector<int> vis(V,0);
    vector<int> vis(V,0);
    vector<int> dfsvis(V,0);
    // 0 based indexing
    for(int i=0;i<E;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
       
    }   
    // <MULTIPLE component ho to for loop>
    bool f=true;
    // 0 based indexing
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            if(!cycleDirectedDfs(adj,vis,dfsvis,i))
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