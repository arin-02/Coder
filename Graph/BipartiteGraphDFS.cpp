// single component bipartite graph
#include<bits/stdc++.h>
using namespace std;

bool bipartiteGraphDFS( vector<vector<int>>&adj,vector<int> &color,int x)
{
    if(color[x]==-1)
        {
            color[x]=0;
        }
        
    for(auto it:adj[x])
    {
        if(color[it]==-1)
        {
            color[it]=!color[x];
             if( !bipartiteGraphDFS(adj,color,it)){return false;}
             
        }
        else if(color[it]==color[x]){return false;}
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
            if(!bipartiteGraphDFS(adj,color,i))
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