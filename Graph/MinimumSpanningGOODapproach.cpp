// graph into tree such that it contains n nodes and n-1 edges then it is minimum spannin gtree and every node is reached by other node
// assign weight 1 if no weight is specified

// PRIMS ALGORITHM:- 
// minimum edge connected to the edges takes 


// CHL NHI RHA

#include<bits/stdc++.h>
using namespace std;

 

void minimumspanningtree(vector<vector<pair<int,int>>> &adj,int src,int V)
{
    // hmare paas n-1 edge honge mst mei 
      vector<int> smallestkey(V);
 vector<bool> MST(V);
 vector<int> parent(V);
 for(int i = 0; i < V; i++)
 {
    smallestkey[i] =1e9;
    MST[i] =false;
    parent[i] =-1;
 }

 priority_queue< pair<int,int>, vector<pair<int,int> > ,greater<pair<int,int> >> pq;
 smallestkey[0] =0;
 parent[0] =-1;
 pq.push({0,0});
    for(int count=0;count<V-1;count++)
    {
        int u=pq.top().second;
        pq.pop();
        MST[u]=true;
        
        MST[u]=true;
        for(auto it:adj[u])
        {
            int x=it.first;
            int weight=it.second;
            if(MST[x]==false && weight<smallestkey[x])
            {
                parent[x]=u;
                pq.push({smallestkey[x],weight});
                smallestkey[x]=weight;
            }
        }
    }
    for(int i=1;i<V;i++)
    {
        cout<<parent[i]<<"->"<<i<<endl;
    }
    
    
}


int main()
{
   int V,E;
 
    cin>>V>>E;
    vector<vector<pair<int,int>>> adj(V+1,vector<pair<int,int>>());
    
   
    // 0 based indexing
    // for(int i=0;i<E;i++)
    // {
    //     int x,y,wt;
    //     cin>>x>>y>>wt;
    //     adj[x].push_back({y,wt});
    //     adj[y].push_back({x,wt});
    // }   
    // 1 based indexing
   for(int i=1;i<=E;i++)
    {
        int x,y,wt;
        cin>>x>>y>>wt;
        adj[x].push_back({y,wt});
        adj[y].push_back({x,wt});
    }  

    int src=0;
    
    minimumspanningtree(adj,src,V);
    
}
// 0 based indexing
// 4 6
// 0 3 6
// 0 1 2
// 3 1 8
// 1 2 3
// 1 4 5
// 4 2 7
// 1 based indexing
// 6 9
// 5 4 9
// 5 1 4
// 4 1 1
// 4 3 5
// 4 2 3
// 3 2 3
// 1 2 2
// 3 6 8
// 2 6 7

